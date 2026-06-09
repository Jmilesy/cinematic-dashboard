#!/usr/bin/env bash
set -euo pipefail

REPO="/usr/share/hassio/homeassistant"
REMOTE="origin"
BRANCH="main"
LOCK_FILE="/tmp/ha-git-save.lock"

usage() {
  echo "Usage: ha-git-save \"Short description of the tested change\"" >&2
  exit 2
}

[[ $# -eq 1 && -n "${1// }" ]] || usage
MESSAGE="$1"

exec 9>"$LOCK_FILE"
flock -n 9 || {
  echo "Another Home Assistant Git operation is already running." >&2
  exit 1
}

cd "$REPO"

[[ "$(git branch --show-current)" == "$BRANCH" ]] || {
  echo "Refusing to save: live Home Assistant must remain on branch '$BRANCH'." >&2
  exit 1
}

git fetch --quiet "$REMOTE" "$BRANCH"
REMOTE_AHEAD="$(git rev-list --count "HEAD..${REMOTE}/${BRANCH}")"
if [[ "$REMOTE_AHEAD" -ne 0 ]]; then
  echo "Refusing to save: GitHub is $REMOTE_AHEAD commit(s) ahead of the live system." >&2
  echo "Review and fast-forward the live checkout before committing." >&2
  exit 1
fi

echo "Validating Home Assistant configuration..."
ha core check

# Keep selected storage-mode dashboards without tracking all of .storage.
mkdir -p lovelace/storage-backups
if [[ -f .storage/lovelace.dashboard_mushroom ]]; then
  cp .storage/lovelace.dashboard_mushroom \
    lovelace/storage-backups/lovelace.dashboard_mushroom.json
fi

# Stage only deliberate configuration and operational documentation.
git add \
  .gitignore \
  .github \
  automations.yaml \
  configuration.yaml \
  scripts.yaml \
  scenes.yaml \
  blueprints \
  docs \
  esphome \
  lovelace \
  scripts \
  templates \
  themes \
  www/floorplan

# This is a deliberate local compatibility patch inside an otherwise ignored
# HACS integration. Track only this source file, never the whole component.
WASTE_PATCH="custom_components/waste_collection_schedule/waste_collection_schedule/source/dover_gov_uk.py"
if [[ -f "$WASTE_PATCH" ]]; then
  git add -f "$WASTE_PATCH"
fi

if git diff --cached --quiet; then
  echo "No safe Home Assistant changes are waiting to be saved."
  exit 0
fi

FORBIDDEN='(^|/)(secrets\.yaml|\.storage/|\.cache/|backups/|.*\.db(-shm|-wal)?$|.*\.bak.*$|.*\.pickle$|.*_key\.pem$)'
if git diff --cached --name-only | grep -E "$FORBIDDEN" >/dev/null; then
  echo "Refusing to commit forbidden secrets, runtime data, databases, or backups:" >&2
  git diff --cached --name-only | grep -E "$FORBIDDEN" >&2
  git reset --quiet
  exit 1
fi

git diff --cached --check

echo "Files to commit:"
git diff --cached --stat
git commit -m "$MESSAGE"
git push "$REMOTE" "$BRANCH"

echo "Saved and pushed: $(git rev-parse --short HEAD) $MESSAGE"

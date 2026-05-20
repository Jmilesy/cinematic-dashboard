#!/usr/bin/env bash
set -euo pipefail

REPO="/usr/share/hassio/homeassistant"
BRANCH="main"
REMOTE="origin"
STAMP="$(date '+%Y-%m-%d %H:%M:%S %z')"

cd "$REPO"

if command -v ha >/dev/null 2>&1; then
  ha core check >/tmp/ha-github-backup-core-check.log 2>&1
fi

# Keep selected Home Assistant UI-storage dashboards backed up without tracking
# the whole .storage directory, which may contain runtime metadata.
mkdir -p lovelace/storage-backups
if [[ -f .storage/lovelace.dashboard_mushroom ]]; then
  cp .storage/lovelace.dashboard_mushroom lovelace/storage-backups/lovelace.dashboard_mushroom.json
fi

# Stage only deliberate, safe HA source/config areas. Do not blanket-add repo
# root because runtime files, temporary backups, and integrations can appear here.
git add \
  .gitignore \
  automations.yaml \
  configuration.yaml \
  scripts.yaml \
  scenes.yaml \
  blueprints \
  esphome \
  lovelace \
  templates \
  themes \
  www/floorplan

if git diff --cached --quiet; then
  echo "No staged HA changes to back up."
  exit 0
fi

if git diff --cached --name-only | grep -E '(^|/)(secrets\.yaml|\.storage/|\.cache/|.*\.db(-shm|-wal)?$|.*\.bak.*$)' >/dev/null; then
  echo "Refusing backup: staged files include secrets, runtime storage/cache/database, or local .bak files." >&2
  git diff --cached --name-only >&2
  exit 1
fi

git commit -m "HA backup ${STAMP}"
git push "$REMOTE" "$BRANCH"

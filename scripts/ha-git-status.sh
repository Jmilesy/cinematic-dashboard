#!/usr/bin/env bash
set -euo pipefail

REPO="/usr/share/hassio/homeassistant"
cd "$REPO"

git fetch --quiet origin main

echo "Home Assistant Git status"
echo "========================="
echo "Branch:       $(git branch --show-current)"
echo "Local HEAD:   $(git rev-parse --short HEAD)"
echo "GitHub HEAD:  $(git rev-parse --short origin/main)"
echo "Ahead/behind: $(git rev-list --left-right --count HEAD...origin/main | tr '\t' '/')"
echo
git status --short
echo
echo "Recent deployed commits:"
git log -5 --oneline --decorate

#!/usr/bin/env bash
set -euo pipefail

STAMP="$(date '+%Y-%m-%d %H:%M:%S %z')"
exec /usr/local/bin/ha-git-save "HA safety backup ${STAMP}"

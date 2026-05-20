# Home Assistant Maintenance Todo

## Recorder Review

- Check recorder database size and growth rate.
- Identify high-churn entities by row count before changing exclusions.
- Pay special attention to mmWave coordinate/speed sensors, noisy phone sensors, media stats, and frequent power/energy updates.
- Keep useful summary/binary states where possible so history remains useful.
- Only purge/repack after confirming backups and free disk space.

Status: pending, no recorder settings changed yet.

## Watchman Report Cleanup

- Updated Watchman's ignored file patterns on 2026-05-20 so reports should stop scanning local backups, `.git`, `.cache`, `www/community`, `__pycache__`, and dependency folders.
- Config file changed: `.storage/core.config_entries` (not Git-tracked by design).
- Backup made on the HA host before editing: `.storage/core.config_entries.bak-watchman-ignore-patterns-*`.
- Next step: reload/restart Watchman or Home Assistant, then run a fresh Watchman report and clean the remaining live references.

Status: pending reload/re-run.

# Home Assistant Maintenance Todo

## Recorder Review

- Check recorder database size and growth rate.
- Identify high-churn entities by row count before changing exclusions.
- Pay special attention to mmWave coordinate/speed sensors, noisy phone sensors, media stats, and frequent power/energy updates.
- Keep useful summary/binary states where possible so history remains useful.
- Only purge/repack after confirming backups and free disk space.

Status: pending, no recorder settings changed yet.

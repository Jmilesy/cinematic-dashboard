# Home Assistant GitHub Workflow

GitHub is the durable record. The live Home Assistant checkout on `main`
represents the currently deployed configuration.

## Repository Scope

The GitHub repository is currently named `cinematic-dashboard`, but it is the
full operational Home Assistant configuration repository, not only the
Cinematic dashboard. It includes automations, scripts, templates, Lovelace,
floorplan assets, operational documentation, and ESPHome configuration.

Renaming the repository to `ha-config` may be considered later as a separately
approved maintenance task. The existing name does not change its current scope.

## Installed Commands

These commands already exist on the Home Assistant host:

- `/usr/local/bin/ha-git-status`
- `/usr/local/bin/ha-git-save`
- `/usr/local/bin/ha-github-backup`

`ha-git-save` is an implemented and tested guard, not a proposal. It:

1. Locks Git operations so two sessions cannot save concurrently.
2. Requires the deployed checkout to be on `main`.
3. Fetches GitHub and refuses to commit if GitHub is ahead.
4. Runs `ha core check`.
5. Stages only approved configuration and documentation paths.
6. Blocks secrets, runtime storage, databases, credentials, and backups.
7. Checks the staged diff, commits it, and pushes to GitHub.

## Normal Change

1. Run `ha-git-status` before editing.
2. Make one closely related change.
3. Keep a timestamped local backup before risky edits.
4. Run Home Assistant's configuration check.
5. Reload only the affected domain, or restart Core when required.
6. Verify the behaviour.
7. Save immediately:

   ```bash
   ha-git-save "Fix hall light motion reset"
   ```

The save command validates Home Assistant again, stages only approved paths,
blocks secrets/runtime data, commits, and pushes `main`.

## ESPHome

ESPHome YAML belongs in this repository under `esphome/` and is included by
`ha-git-save`. Keep secrets out of Git and use the existing ESPHome secrets
mechanism.

For an ESPHome change:

1. Check Git status and identify the exact device YAML.
2. Back up before risky firmware or connectivity changes.
3. Validate or compile the device configuration.
4. Install by OTA only when the device is online and recovery is understood.
5. Confirm the device reconnects to Home Assistant and its key entities work.
6. Use `ha-git-save` with a device-specific commit message.

Do not bulk-update every device as part of an unrelated configuration change.

## Desktop Editing

The clean operational desktop clone is
`C:\Users\jon_m\cinematic-dashboard-live`.

The older `C:\Users\jon_m\cinematic-dashboard` checkout contains unfinished
May 2026 work. Treat it as WIP reference material and do not pull, deploy, or
push from it until those changes have been reviewed and selectively recovered.

Before editing:

```powershell
git status
git pull --ff-only origin main
```

Do not pull when the desktop has uncommitted or unpushed work. Commit that work
to a temporary branch first, then reconcile it deliberately.

After desktop changes are tested and pushed, deploy on Home Assistant only when
the live checkout is clean:

```bash
cd /usr/share/hassio/homeassistant
git pull --ff-only origin main
ha core check
```

## Safety Net

At 03:23 each night, `ha-github-backup` captures safe uncommitted configuration
changes. This is a recovery net, not the normal way to finish work.

## Rules

- Never use `git add .` in the Home Assistant config directory.
- Never commit `.storage`, databases, secrets, local backups, credentials, or
  generated caches.
- Keep commits small and describe the behaviour changed.
- `main` must always match the deployed state.
- Do not force-push `main`.
- Do not reset or discard dirty files without reviewing who created them.

## Session Handover

Every Home Assistant work session must end with a handover entry in the shared
priorities/task database. Record:

- What changed and why.
- Validation or physical testing performed.
- The Git commit hash, or why no commit was made.
- Backups created.
- Remaining work, known risks, and anything awaiting human testing.
- Any dirty files intentionally left on the live host or desktop.

The Git commit is the technical record; the task database is the operational
handover. Both are required when a session changes Home Assistant.

## Recovery

Use Git history to inspect the previous version first:

```bash
git log --oneline -10
git show <commit>:automations.yaml
```

Restore only the affected file or lines, validate, reload, verify, and commit
the rollback as a new commit. Avoid rewriting deployed history.

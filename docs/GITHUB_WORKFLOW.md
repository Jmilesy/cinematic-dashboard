# Home Assistant GitHub Workflow

GitHub is the durable record. The live Home Assistant checkout on `main`
represents the currently deployed configuration.

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

## Recovery

Use Git history to inspect the previous version first:

```bash
git log --oneline -10
git show <commit>:automations.yaml
```

Restore only the affected file or lines, validate, reload, verify, and commit
the rollback as a new commit. Avoid rewriting deployed history.

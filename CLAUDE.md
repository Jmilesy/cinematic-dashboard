# Home Assistant Operating Rules

Read `docs/GITHUB_WORKFLOW.md` before changing this repository.

This repository is the full deployed Home Assistant configuration despite its
historical `cinematic-dashboard` name. The live checkout is
`/usr/share/hassio/homeassistant` on the Home Assistant host.

Before editing, run `ha-git-status`. Keep changes small, preserve unknown work,
validate and test them, then use:

```bash
ha-git-save "Describe the tested behaviour change"
```

Do not use `git add .`, force-push `main`, commit secrets/runtime data, or leave
a changed HA session without a handover entry in the shared priorities/task
database. ESPHome YAML under `esphome/` follows the same Git workflow and also
requires device validation, reconnection, and functional checks.

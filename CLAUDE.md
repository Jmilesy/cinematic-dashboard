# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

---

## What This Repository Is

This is the **Home Assistant Bible & Cinematic Dashboard Development Hub** — a documentation-first, reference-only project. It is **not** Jon's live Home Assistant configuration. Nothing here is deployed automatically. Jon manually copies improvements from this repo into his real HA when ready.

All YAML is example-only and lives in `/config-examples` or `/experiments`.

---

## Repository Architecture

Four distinct layers with strict boundaries:

| Layer | Folder | Role |
|---|---|---|
| Documentation | `/docs` | Single source of truth. Authoritative architecture and rules. |
| Reference Config | `/config-examples` | Illustrative HA YAML examples. Reference-only, never live. |
| Experimental | `/experiments` | Active sandbox for cinematic dashboard prototyping. |
| Assets | `/assets` | Images, backgrounds, icons, mockups. |

### Separation of Concerns

Within HA configuration, each concern lives in its own layer — never mix them:

- **Sensors** = data layer (raw values, no computation)
- **Templates** = logic layer (formatting, conditionals, computed values)
- **Dashboards** = UI layer (references sensors/templates only, no inline logic)
- **Themes** = styling layer (colors, effects, typography — no logic)
- **Resources** = custom cards, JS, CSS

### Active Development

The primary working prototype is `experiments/cinematic-header/`, which contains:

```
homeassistant/
  configuration.yaml           # Main entry point with includes
  includes/
    sensors/                   # header, presence, system, weather sensors
    templates/                 # header, global, card, utility templates
    dashboards/
      ui-lovelace.yaml         # Dashboard entry point
      views/                   # home, climate, lighting, media, system
      cards/                   # presence, weather, media, system cards
      header/                  # cinematic_header.yaml + header_effects.yaml
    themes/                    # cinematic_dark.yaml, cinematic_light.yaml
    resources/                 # Custom card definitions and JS/CSS
```

---

## No Build System

This is a pure YAML/Markdown/Jinja2 project. There are no build steps, no package managers, no test runners, no linters. There is nothing to install or compile.

---

## Collaboration Rules

These rules apply to all AI agents in this repo:

1. **Single-scope changes only.** Never edit multiple conceptual areas (e.g. sensors + dashboards) in one change.
2. **Always state the target file** before making changes.
3. **No inline logic in dashboards.** Logic belongs in sensors or templates.
4. **No cross-domain edits** without explicit instruction. Editing sensors means not touching templates or dashboards.
5. **No deletions without confirmation** from Jon.
6. **No duplication.** If logic exists in sensors, don't replicate it in templates or dashboards.
7. **Document architectural decisions** in `docs/development.md` using the decision log format defined there.
8. **Treat `/config-examples` as reference-only.** Never assume it reflects Jon's real HA.
9. **Treat `/experiments` as sandbox-only.** Safe to change; non-authoritative.

---

## Naming Conventions

All filenames and entity names use:
- **Lowercase only**
- **Underscores** as separators (no hyphens, no spaces)
- **Descriptive names**

Examples: `header_sensors.yaml`, `sensor.header_temperature`, `template.header_greeting`, `cinematic_header.yaml`

---

## Key Documentation Files

When unsure about architecture or rules, consult these in order:

- `docs/architecture.md` — system design, folder roles, principles
- `docs/development.md` — workflow rules and decision log format
- `docs/sensors.md` — sensor categories and naming
- `docs/templates.md` — template layer structure
- `docs/dashboard.md` — dashboard philosophy and layout rules
- `docs/theming.md` — theme structure and cinematic styling

# Changelog

All notable changes to this project will be documented in this file.

This repository follows a documentation-first, architecture-driven workflow.
Changes are grouped by date and category. This file tracks updates to
documentation, example configurations, experiments, and repository structure.

All structural or architectural changes must be recorded here. The changelog
ensures transparency across all AI and human contributors, predictable version
history, and safe multi-AI collaboration.

---

## Format

Each entry uses the following structure:

```
## YYYY-MM-DD

### Added
- New files, features, documentation, or examples.

### Changed
- Updates to existing files, refactors, or improvements.

### Removed
- Deprecated or replaced files (only with explicit confirmation).
```

---

## 2026-02-25

### Added

- `experiments/claude/` — new staging area for Claude Code-authored dashboard
  files, structured to mirror the live HA config for direct deployment:
  - `lovelace/cinematic-v2.yaml` — second dashboard entry point
  - `lovelace/dashboards/cards/cinematic_header_card.yaml` — shared 3-column
    header card (time | weather | presence)
  - `lovelace/dashboards/views/cinematic_home.yaml` — home view with cinematic
    header, Overview and Weather sections
  - `lovelace/dashboards/views/cinematic_climate.yaml` — Temperature and
    Humidity sections
  - `lovelace/dashboards/views/cinematic_lighting.yaml` — Rooms and Scenes
    sections
  - `lovelace/dashboards/views/cinematic_media.yaml` — Now Playing and Devices
    sections
  - `lovelace/dashboards/views/cinematic_system.yaml` — System Status and
    Network sections
  - `lovelace/templates/cinematic_v2_templates.yaml` — full button-card
    template set (base_block, section_header, header blocks, card blocks,
    utility helpers)
  - `themes/cinematic_dark.yaml` — cinematic dark theme with CSS variables for
    glow, blur, gradients, and icon colours
  - `manual_deploy/configuration_yaml_snippet.yaml` — snippet documenting the
    configuration.yaml addition required for manual edits
- `CLAUDE.md` — project guidance file for Claude Code (architecture rules,
  naming conventions, collaboration boundaries)
- Initial root-level project files: `.aider.json`, `.claude.json`,
  `.copilot-instructions.md`, `CONTRIBUTING.md`, `GLOSSARY.md`,
  `PROJECT-GUIDE.md`, `REPO-INDEX.md`, `ROADMAP.md`, folder-level READMEs,
  issue templates, pull request template, labels list

### Changed

- `cinematic-dashboard.code-workspace` — added live HA network share
  (`\\192.168.1.104\config`) as a workspace folder; added YAML file
  associations and editor settings
- Repository structure formalised for multi-AI collaboration
- Documentation aligned with the Home Assistant Bible architecture

### Removed

- None.

---

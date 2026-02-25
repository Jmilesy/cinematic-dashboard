# Theming Architecture & Cinematic Design Principles

This document defines how themes are structured, named, and used within this
repository. It describes the reference theme architecture, not Jon’s live Home
Assistant configuration.

All theme YAML in this repo is example‑only and lives in:

- config-examples/homeassistant/includes/themes/
- experiments/cinematic-header/homeassistant/includes/themes/

Jon’s real themes remain local, private, and not linked to GitHub.

---

## Purpose

- Define how themes are organised
- Establish naming conventions
- Document the cinematic theme philosophy
- Explain how themes interact with dashboards and the header
- Provide a safe reference for all AIs
- Prevent drift or destructive changes

---

# Theme Categories

## 1. Cinematic Themes

These are the primary themes used for the cinematic dashboard experience. They
define:

- colour palettes
- typography
- shadows
- atmospheric effects
- header styling
- card styling

Location: experiments/cinematic-header/homeassistant/includes/themes/

Examples:

- cinematic_dark.yaml
- cinematic_light.yaml

## 2. Reference Themes

Simple example themes used to demonstrate structure and naming.

Location: config-examples/homeassistant/includes/themes/

---

# Cinematic Theme Philosophy

The cinematic dashboard aims to feel:

- atmospheric
- immersive
- modern
- minimal
- responsive
- visually consistent

Themes are responsible for:

- colour systems
- background layers
- gradients
- glow effects
- card elevation
- header ambience
- icon styling
- text contrast

Themes must **never** contain:

- logic
- entity references
- dashboard layout
- card configuration

Themes define **style only**.

---

# Folder Structure

config-examples/ homeassistant/ includes/ themes/ cinematic_dark.yaml
cinematic_light.yaml

experiments/ cinematic-header/ homeassistant/ includes/ themes/
cinematic_dark.yaml cinematic_light.yaml

---

# Naming Conventions

General rules:

- lowercase
- underscores
- descriptive names
- no spaces
- no hyphens

Examples:

- cinematic_dark
- cinematic_light

Theme filenames must match the theme name.

---

# Theme Structure

A theme file should follow this pattern:

theme_name: primary-color: "#..." accent-color: "#..." card-background-color:
"#..." header-background: "#..." text-color: "#..." disabled-text-color: "#..."
divider-color: "#..." state-icon-color: "#..." state-icon-active-color: "#..."

Rules:

- Use clear, consistent variable names
- Prefer CSS variables where possible
- Avoid hardcoding colours in dashboards
- Keep theme logic minimal and declarative

---

# Interaction With Dashboards

Themes control:

- global colours
- header ambience
- card elevation
- background layers
- icon colours
- text contrast

Dashboards should:

- reference theme variables
- avoid inline colours
- avoid inline shadows
- avoid inline gradients

The cinematic header relies heavily on theme variables for:

- glow effects
- weather ambience
- time‑of‑day shifts
- presence indicators

---

# AI Collaboration Rules (Theme-Level)

1. Never modify multiple theme files in one change.
2. Always state which file you are editing.
3. Never remove themes unless Jon confirms.
4. Never add logic to themes.
5. Always follow naming conventions.
6. Treat experiments/ as sandbox-only.
7. Document decisions in development.md.

---

# Long-Term Vision

- A unified cinematic theme system
- Zero inline styling in dashboards
- Zero duplication across themes
- A reusable theme foundation for all future UI work
- A repo that all AIs can safely extend
- Future-proof foundation for the cinematic dashboard

This document defines the foundation for the theme layer.

---

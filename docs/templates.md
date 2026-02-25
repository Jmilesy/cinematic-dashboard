# Template Architecture & Logic Conventions

This document defines how templates are structured, named, and used within this
repository. It describes the reference template architecture, not Jon’s live
Home Assistant configuration.

All template YAML in this repo is example‑only and lives in:

- config-examples/homeassistant/includes/templates/
- experiments/cinematic-header/homeassistant/includes/templates/

Jon’s real templates remain local, private, and not linked to GitHub.

---

## Purpose

- Define how templates are organised
- Establish naming conventions
- Explain the relationship between templates, sensors, and dashboards
- Document the cinematic header template model
- Provide a safe reference for all AIs
- Prevent drift or destructive changes

---

# Template Categories

## 1. Header Templates

Used by the cinematic header for:

- greetings
- weather icons
- time formatting
- presence summaries
- ambient effects

Location:
experiments/cinematic-header/homeassistant/includes/templates/header_templates.yaml

## 2. Global Templates

Reusable logic shared across dashboards, cards, and sensors.

Location: config-examples/homeassistant/includes/templates/global_templates.yaml

## 3. Card Templates

Reusable UI logic for blocks, summaries, indicators, and status components.

Location: config-examples/homeassistant/includes/templates/card_templates.yaml

## 4. Utility Templates

Small helper functions for formatting, icons, and conditional logic.

Location:
config-examples/homeassistant/includes/templates/utility_templates.yaml

---

# Template Philosophy

## Templates = Logic Layer

Templates contain:

- formatting
- computed values
- conditional logic
- string manipulation
- icon selection

Templates do NOT contain:

- raw sensor data
- UI layout
- styling
- dashboard-specific behaviour

## Sensors = Data Layer

Raw values belong in sensors, not templates.

## Dashboards = Presentation Layer

Dashboards read template outputs and never compute logic.

## Zero Duplication

If logic exists in templates, do not duplicate it in dashboards or sensors.

---

# Folder Structure

config-examples/ homeassistant/ includes/ templates/ card_templates.yaml
global_templates.yaml header_templates.yaml utility_templates.yaml

experiments/ cinematic-header/ homeassistant/ includes/ templates/
header_templates.yaml

---

# Naming Conventions

General rules:

- lowercase
- underscores
- descriptive names
- no spaces
- no hyphens

Examples:

- template.header_greeting
- template.weather_icon
- template.format_temperature
- template.presence_summary

Header templates must begin with: header\_

Examples:

- template.header_greeting
- template.header_weather_icon
- template.header_time_string

---

# Template File Structure

template:

- name: "Descriptive Name" unique_id: something_unique state: > {{ ... }}

Rules:

- Always include unique_id
- Keep logic readable
- Use Jinja only for computation
- Offload raw values to sensors
- Offload UI to dashboards

---

# AI Collaboration Rules (Template-Level)

1. Never modify multiple template files in one change.
2. Always state which file you are editing.
3. Never remove templates unless Jon confirms.
4. Never duplicate logic across templates.
5. Never add UI logic to templates.
6. Always follow naming conventions.
7. Treat experiments/ as sandbox-only.
8. Document decisions in development.md.

---

# Long-Term Vision

- Clean, modular template architecture
- Unified header template model
- Zero duplication
- Zero dead logic
- Safe AI collaboration
- Future-proof foundation for the cinematic dashboard

This document defines the foundation for the template layer.

---

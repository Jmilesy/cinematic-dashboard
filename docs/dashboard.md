# Dashboard Architecture & Cinematic UI Design

This document defines the dashboard philosophy, structure, and development
workflow used in this repository.  
It describes the **reference dashboard architecture**, not Jon’s live Home
Assistant configuration.

All dashboard YAML in this repo is **example‑only** and lives in:

- `/config-examples/homeassistant/includes/dashboards/`
- `/experiments/cinematic-header/homeassistant/includes/dashboards/`

Jon’s real dashboards remain **local**, **private**, and **not linked to
GitHub**.

---

## 🎬 Purpose of This Document

- Define the structure of dashboards in this repo
- Document the cinematic dashboard design philosophy
- Explain how views, cards, and headers are organised
- Provide a safe reference for all AIs
- Prevent drift, duplication, or destructive changes
- Support ongoing development of the cinematic header

This is part of the **Home Assistant Bible**.

---

## 🧱 Dashboard Layers

The dashboard system in this repo is built around three layers:

### 1. **Reference Dashboards** (`/config-examples`)

Contains simple, clean example dashboards showing:

- layout structure
- card organisation
- view separation
- naming conventions

These are **illustrative only**.

### 2. **Cinematic Dashboard Experiments** (`/experiments/cinematic-header`)

Contains:

- the cinematic header
- atmospheric effects
- prototype cards
- prototype views
- prototype themes

This is the **active development space** for the cinematic UI.

### 3. **Documentation Layer** (`/docs`)

Defines:

- dashboard rules
- naming conventions
- layout philosophy
- AI collaboration rules

This is the **source of truth** for all AIs.

---

## 📁 Dashboard Folder Structure

Dashboards in this repo follow a predictable structure:

config-examples/ homeassistant/ includes/ dashboards/ ui-lovelace.yaml views/
cards/ header/

experiments/ cinematic-header/ homeassistant/ includes/ dashboards/
ui-lovelace.yaml views/ cards/ header/

---

## 🧩 Dashboard Components

### **1. ui-lovelace.yaml**

The entry point for the dashboard.

Defines:

- theme
- header
- navigation
- view includes

### **2. Views**

Each view lives in its own file.

Examples:

- `home.yaml`
- `climate.yaml`
- `lighting.yaml`
- `media.yaml`
- `system.yaml`

Views must:

- be modular
- contain no inline templates
- reference cards via includes

### **3. Cards**

Each card lives in its own file.

Examples:

- `presence_summary.yaml`
- `weather_block.yaml`
- `system_overview.yaml`
- `media_now_playing.yaml`
- `waste_collection.yaml`

Cards must:

- be self‑contained
- use templates where possible
- avoid inline logic

### **4. Header**

The cinematic header lives in:

`/experiments/cinematic-header/homeassistant/includes/dashboards/header/`

It contains:

- `cinematic_header.yaml`
- `header_effects.yaml`

This is the **prototype** for the future unified header.

---

## 🎨 Cinematic Dashboard Philosophy

The cinematic dashboard aims to be:

- atmospheric
- immersive
- clean
- modular
- responsive
- theme‑driven
- animation‑aware

Key principles:

### **1. Minimal inline YAML**

Logic belongs in:

- sensors
- templates
- themes

Not in dashboards.

### **2. Modular views**

Each view focuses on a single domain:

- climate
- lighting
- media
- system
- home

### **3. Reusable cards**

Cards should be:

- portable
- template‑driven
- visually consistent

### **4. Header as a UI anchor**

The cinematic header provides:

- weather
- time
- presence
- system state
- ambient effects

It is the “cinematic identity” of the dashboard.

---

## 🧠 AI Collaboration Rules (Dashboard-Level)

1. Never modify multiple views or cards in one change.
2. Always state which file you are editing.
3. Never add inline templates to dashboards.
4. Always use templates from `/config-examples` or `/experiments`.
5. Never remove cards or views unless confirmed.
6. Treat `/experiments` as the active development space.
7. Document UI decisions in `development.md`.

---

## 🚀 Long-Term Vision

- A unified cinematic dashboard
- A reusable header module
- A clean, modular card library
- A fully documented UI architecture
- A repo that all AIs can safely extend
- Zero drift
- Zero duplication

This document defines the foundation for the dashboard layer.

# Home Assistant Architecture Overview

This document defines the architecture, structure, and long‑term design
philosophy of Jon’s Home Assistant system as represented in this repository.

It describes the **reference architecture**, not Jon’s live Home Assistant
configuration.  
All YAML in this repo is **example‑only** and lives in `/config-examples` or
`/experiments`.

Jon’s real Home Assistant remains **local**, **private**, and **not linked to
GitHub**.

---

## 🎯 Purpose of This Document

- Provide a clear, authoritative description of the Home Assistant architecture
- Define naming conventions and folder structure
- Explain how sensors, templates, dashboards, and themes are organised
- Document the cinematic dashboard development model
- Ensure all AIs follow the same rules and structure
- Prevent drift, duplication, or destructive changes

This is part of the **Home Assistant Bible**.

---

## 🧱 High-Level Architecture

The architecture is built around four core layers:

### 1. **Documentation Layer** (`/docs`)

The HA Bible:

- architecture
- naming conventions
- sensors
- templates
- dashboards
- theming
- development workflow

This is the **source of truth** for all AIs.

### 2. **Reference Configuration Layer** (`/config-examples`)

Contains:

- example sensors
- example templates
- example dashboards
- example themes
- example resources

These are **illustrative only**.  
Jon manually copies improvements into his real HA when ready.

### 3. **Experimental Layer** (`/experiments`)

Contains:

- cinematic header module
- prototype dashboards
- prototype cards
- prototype themes
- UI experiments

This is the **sandbox** for new ideas.

### 4. **Assets Layer** (`/assets`)

Contains:

- icons
- backgrounds
- header images
- mockups

Used for documentation and UI development.

---

## 📁 Repository Structure (Explained)

### `/docs`

The HA Bible.  
Defines the architecture and rules.

### `/config-examples`

Reference-only Home Assistant YAML.  
Not Jon’s live config.

### `/experiments`

Cinematic dashboard development space.  
Contains:

- header components
- dashboard prototypes
- card prototypes
- view layouts
- themes
- resources

### `/assets`

Images and visual resources.

### `README.md`

Explains the dual purpose of the repo:

- HA Bible
- Cinematic Dashboard Development Hub

---

## 🧩 Architectural Principles

### **1. Modularity**

Every logical component lives in its own file:

- sensors
- templates
- dashboards
- themes
- resources

This prevents merge conflicts and makes AI-assisted editing safe.

### **2. Predictable Structure**

All includes follow the same pattern:

config-examples/ homeassistant/ includes/ sensors/ templates/ dashboards/
themes/ resources/

### **3. Clean Separation of Concerns**

- Sensors = data
- Templates = logic
- Dashboards = UI
- Themes = styling
- Resources = JS/CSS/custom cards

### **4. AI-Friendly Naming**

All files use:

- lowercase
- underscores
- descriptive names

Examples:

- `header_sensors.yaml`
- `presence_summary.yaml`
- `cinematic_header.yaml`

### **5. Future-Proofing**

Avoid:

- deprecated integrations
- dead entities
- inline YAML duplication
- monolithic dashboards

Everything is built for long-term maintainability.

---

## 🧠 AI Collaboration Rules (Architecture-Level)

1. Never modify multiple conceptual areas in one change.
2. Always state which file you are editing.
3. Never remove entities unless confirmed.
4. Always follow naming conventions.
5. Treat `/config-examples` as reference-only.
6. Treat `/experiments` as sandbox-only.
7. Document architectural decisions in `development.md`.

---

## 🏗 Long-Term Vision

- A fully documented, future-proof HA architecture
- A unified cinematic dashboard experience
- A clean, modular sensor and template system
- A repo that all AIs can safely collaborate on
- Zero drift
- Zero duplication
- Zero dead entities

This document defines the foundation for that system.

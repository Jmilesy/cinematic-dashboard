# Development Workflow & Collaboration Rules

This document defines how development is carried out in this repository.  
It applies to Jon and all AI collaborators (Copilot, ChatGPT, Claude, Gemini,
Grok).

This repo is a **documentation hub**, a **reference architecture**, and a
**development space** for the cinematic dashboard.  
It is **not** Jon’s live Home Assistant configuration.

All YAML in this repo is **example‑only** and lives in:

- `/config-examples`
- `/experiments`

Jon manually copies improvements into his real HA when ready.

---

## 🎯 Purpose of This Document

- Define how changes are made
- Prevent drift or destructive edits
- Ensure all AIs follow the same rules
- Document decisions and architecture evolution
- Maintain a clean, future‑proof structure
- Support safe experimentation

This is part of the **Home Assistant Bible**.

---

# 🧠 Core Development Principles

### **1. Documentation First**

All architectural decisions must be documented in `/docs` before or alongside
implementation.

### **2. No Direct Production Changes**

Jon’s real Home Assistant is **not** linked to GitHub.  
Nothing in this repo is deployed automatically.

### **3. Reference-Only YAML**

All YAML in this repo is:

- safe
- illustrative
- modular
- non-destructive

### **4. Experiments Are Isolated**

All prototypes live in `/experiments`, especially:

- cinematic header
- prototype dashboards
- prototype cards
- prototype themes

### **5. Modularity Above All**

Every logical component lives in its own file:

- sensors
- templates
- dashboards
- themes
- resources

### **6. Predictable Naming**

All filenames use:

- lowercase
- underscores
- descriptive names

Examples:

- `header_sensors.yaml`
- `presence_summary.yaml`
- `cinematic_header.yaml`

### **7. Zero Duplication**

If logic exists in:

- sensors → do not duplicate in templates
- templates → do not duplicate in dashboards
- dashboards → do not duplicate across views

---

# 📁 Development Areas

### **1. Documentation Layer (`/docs`)**

The HA Bible.  
Defines:

- architecture
- naming conventions
- sensors
- templates
- dashboards
- theming
- development rules

### **2. Reference Config Layer (`/config-examples`)**

Contains:

- example sensors
- example templates
- example dashboards
- example themes
- example resources

These are **not** Jon’s real HA files.

### **3. Experimental Layer (`/experiments`)**

Contains:

- cinematic header
- prototype dashboards
- prototype cards
- prototype themes
- prototype resources

This is the **active development space**.

### **4. Assets Layer (`/assets`)**

Contains:

- icons
- backgrounds
- header images
- mockups

Used for UI development and documentation.

---

# 🧩 AI Collaboration Rules

These rules ensure safe, predictable, high‑quality collaboration.

### **1. Never modify multiple conceptual areas in one change**

Example:

- editing sensors + dashboards in the same change = ❌
- editing only sensors = ✔

### **2. Always state which file you are editing**

Example:

> “Updating: config-examples/homeassistant/includes/sensors/header_sensors.yaml”

### **3. Never remove entities or files unless Jon confirms**

Deletions require explicit approval.

### **4. Never add inline templates to dashboards**

Logic belongs in:

- sensors
- templates

Not in dashboards.

### **5. Always follow naming conventions**

Lowercase, underscores, descriptive.

### **6. Treat `/config-examples` as reference-only**

Never assume these files exist in Jon’s real HA.

### **7. Treat `/experiments` as sandbox-only**

Safe for:

- prototypes
- drafts
- new ideas

### **8. Document decisions in this file**

Any architectural or structural decision must be logged here.

---

# 📝 Decision Logging Format

Every decision should be logged like this:

## Decision: [Short Title]

**Date:** YYYY-MM-DD  
**Summary:**  
A short description of the change or rule.  
**Reasoning:**  
Why the decision was made.  
**Impact:**  
What it affects.  
**Files Updated:**  
List of files.

Example:

## Decision: Adopt Cinematic Header Architecture

**Date:** 2026-02-24  
**Summary:**  
The cinematic header becomes the foundation for the unified dashboard UI.  
**Reasoning:**  
Provides a consistent, atmospheric UI anchor.  
**Impact:**  
Dashboards, themes, sensors, templates.  
**Files Updated:**

- experiments/cinematic-header/...

---

# 🚀 Long-Term Development Vision

- A fully documented, future-proof HA architecture
- A unified cinematic dashboard experience
- A clean, modular sensor and template system
- A reusable header module
- A repo that all AIs can safely extend
- Zero drift
- Zero duplication
- Zero dead entities

This document defines how the system evolves safely over time.

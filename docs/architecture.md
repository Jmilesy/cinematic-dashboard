# Home Assistant Architecture Overview

This document explains the structure, philosophy, and long‑term design goals of the Cinematic Dashboard architecture.  
It is written to be AI‑friendly, modular, and safe for multi‑model collaboration.

---

## 🎯 Core Principles

### 1. Modularity
Every logical component lives in its own file:
- Sensors  
- Templates  
- Dashboards  
- Themes  
- Resources  

This prevents merge conflicts and makes AI‑assisted editing safe.

### 2. Predictable Structure
All includes follow the same pattern:

homeassistant/includes/sensors  
homeassistant/includes/templates  
homeassistant/includes/dashboards  
homeassistant/includes/themes  

This ensures any AI can locate the correct file instantly.

### 3. Clean Separation of Concerns
- Sensors = data  
- Templates = formatting logic  
- Dashboards = UI  
- Themes = styling  
- Resources = JS/CSS/custom cards  

No file mixes responsibilities.

### 4. AI‑Friendly Naming
All files use:
- lowercase  
- underscores  
- descriptive names  

Example: header_sensors.yaml, presence_summary.yaml

### 5. Future‑Proofing
The architecture avoids:
- deprecated integrations  
- dead entities  
- inline YAML duplication  
- monolithic dashboards  

Everything is built for long‑term maintainability.

---

## 📁 Folder Breakdown

### sensors/
Contains all sensor definitions:
- header sensors  
- presence sensors  
- system sensors  
- weather sensors  

Each file contains only sensor: blocks.

### templates/
Contains all Jinja templates:
- header templates  
- card templates  
- utility templates  

Each file contains only template: blocks.

### dashboards/
Contains the entire Lovelace UI:
- ui-lovelace.yaml (entry point)
- header components  
- views  
- cards  

Each card/view/header is isolated for clarity.

### themes/
Contains theme definitions:
- cinematic_dark  
- cinematic_light  

Themes are modular and override‑friendly.

### resources/
Contains:
- custom cards  
- JS  
- CSS  

This keeps all external resources organised.

---

## 🧠 AI Collaboration Rules

1. Never modify multiple files at once.  
2. Always state which file you are editing.  
3. Never create new sensors/templates without confirming naming.  
4. Never remove entities unless confirmed.  
5. Always maintain modularity.

---

## 🏗 Long‑Term Vision

- A cinematic, atmospheric dashboard  
- A clean, unified sensor architecture  
- A fully documented, AI‑extendable system  
- Zero duplication  
- Zero dead entities  
- Zero deprecated integrations  

This repo is the foundation for that system.

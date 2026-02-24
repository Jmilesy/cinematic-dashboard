# Sensor Architecture

This document explains how sensors are structured, named, and organised within the Cinematic Dashboard.  
Sensors provide the raw data that powers the entire UI — presence, weather, system status, header logic, and more.

All sensors are defined in modular include files to keep the configuration clean, maintainable, and AI‑friendly.

---

## 🎯 Purpose of Sensors

Sensors exist to:
- gather raw data from integrations  
- normalise entity values  
- compute derived values for templates  
- provide clean, predictable inputs for dashboards  
- separate data from presentation logic  

Sensors **never** contain:
- formatting  
- UI logic  
- card layout  
- Jinja templates  

Those belong in templates or dashboards.

---

## 📁 Sensor Folder Structure

Sensors live in:

homeassistant/includes/sensors/

Files:
- header_sensors.yaml  
- presence_sensors.yaml  
- system_sensors.yaml  
- weather_sensors.yaml  

Each file contains only sensor: blocks.

---

## 🧩 Sensor Types

### 1. Header Sensors
Used by the cinematic header for:
- time and date  
- weather summary  
- presence summary  
- dynamic colour shifts  
- atmospheric effects  

These sensors feed directly into header templates.

---

### 2. Presence Sensors
Tracks:
- who is home  
- who is away  
- last seen times  
- device trackers  
- occupancy summaries  

Presence sensors are unified into a single, clean structure.

---

### 3. System Sensors
Monitors:
- Home Assistant health  
- uptime  
- CPU load  
- memory usage  
- storage  
- network status  

These sensors power the system view and diagnostics.

---

### 4. Weather Sensors
Provides:
- temperature  
- humidity  
- wind  
- conditions  
- forecasts  

These sensors feed the weather block and header.

---

## 🧠 Naming Conventions

Sensors follow this pattern:

- lowercase  
- underscores  
- descriptive names  
- no abbreviations unless universally understood  

Examples:
- header_time  
- presence_anyone_home  
- system_cpu_load  
- weather_temperature  

---

## 🛑 Rules for Sensor Editing

1. Never embed formatting in sensors.  
2. Never duplicate logic — use templates for formatting.  
3. Never mix sensor types (weather logic stays in weather_sensors).  
4. Never modify multiple sensor files at once.  
5. Always check for existing sensors before creating new ones.  

---

## 🧠 AI Collaboration Notes

When editing sensors:
- Always specify which file you are modifying  
- Never create new sensors without confirming naming  
- Never remove sensors unless confirmed  
- Keep logic readable and well‑commented  
- Maintain strict separation of concerns  

---

## 🚀 Long‑Term Vision

Sensors will evolve to support:
- richer presence detection  
- advanced weather summaries  
- system health scoring  
- dynamic header effects  
- unified data pipelines  

This document ensures all future sensor logic remains consistent, modular, and maintainable.

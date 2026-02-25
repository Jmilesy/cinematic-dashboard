# Sensor Architecture & Naming Conventions

This document defines how sensors are structured, named, and used within this
repository.  
It describes the **reference sensor architecture**, not Jon’s live Home
Assistant configuration.

All sensor YAML in this repo is **example‑only** and lives in:

- `/config-examples/homeassistant/includes/sensors/`
- `/experiments/cinematic-header/homeassistant/includes/sensors/`

Jon’s real sensors remain **local**, **private**, and **not linked to GitHub**.

---

## 🎯 Purpose of This Document

- Define how sensors are organised in this repo
- Establish naming conventions
- Explain the relationship between sensors, templates, and dashboards
- Document the cinematic header sensor model
- Provide a safe reference for all AIs
- Prevent drift, duplication, or destructive changes

This is part of the **Home Assistant Bible**.

---

# 🧱 Sensor Categories

Sensors in this repo fall into four main categories:

### **1. Header Sensors**

Used by the cinematic header to display:

- weather
- time
- date
- presence
- system state
- ambient effects

Located in:
`/experiments/cinematic-header/homeassistant/includes/sensors/header_sensors.yaml`

### **2. Presence Sensors**

Used to track:

- Jon
- Natalie
- Jacob
- Joseph

Located in:
`/config-examples/homeassistant/includes/sensors/presence_sensors.yaml`

### **3. System Sensors**

Used for:

- uptime
- CPU
- memory
- network
- HA status

Located in:
`/config-examples/homeassistant/includes/sensors/system_sensors.yaml`

### **4. Weather Sensors**

Used for:

- temperature
- humidity
- conditions
- forecast
- alerts

Located in:
`/config-examples/homeassistant/includes/sensors/weather_sensors.yaml`

---

# 🧩 Sensor Philosophy

### **1. Sensors = Data Layer**

Sensors should contain:

- raw values
- processed values
- state transformations

They should **not** contain:

- UI logic
- formatting
- styling
- card-specific behaviour

### **2. Templates = Logic Layer**

If a sensor requires:

- formatting
- conditional logic
- string manipulation
- computed states

…it belongs in a **template**, not a sensor.

### **3. Dashboards = Presentation Layer**

Dashboards should:

- read sensor values
- never compute logic
- never duplicate sensor behaviour

### **4. Zero Duplication**

If a value exists in:

- sensors → do not duplicate in templates
- templates → do not duplicate in dashboards

---

# 🧱 Folder Structure

Sensors follow a predictable structure:

config-examples/ homeassistant/ includes/ sensors/ header_sensors.yaml
presence_sensors.yaml system_sensors.yaml weather_sensors.yaml

experiments/ cinematic-header/ homeassistant/ includes/ sensors/
header_sensors.yaml

---

# 🧠 Naming Conventions

### **General Rules**

- lowercase
- underscores
- descriptive names
- no spaces
- no hyphens

### **Examples**

- `sensor.jon_home`
- `sensor.family_home_count`
- `sensor.header_weather_icon`
- `sensor.system_uptime`
- `sensor.weather_feels_like`

### **Header Sensor Naming**

Header sensors must begin with:

`header_`

Examples:

- `sensor.header_temperature`
- `sensor.header_condition`
- `sensor.header_greeting`

---

# 🧩 Sensor File Structure

Each sensor file should follow this pattern:

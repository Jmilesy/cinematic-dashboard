# Cinematic Header (Experimental Module)

This folder contains a fully isolated, self‑contained implementation of the
Cinematic Header for Home Assistant.

## Purpose

- Acts as a reference implementation for all AI agents.
- Provides a safe sandbox for UI development.
- Does NOT touch the live Home Assistant configuration unless manually copied.
- Preserves the full internal `homeassistant/` folder structure for accurate
  examples.

## Structure

experiments/cinematic-header/ └── homeassistant/ ├── includes/ │ ├──
dashboards/header/ │ ├── sensors/header_sensors.yaml │ └── templates/... ├──
themes/ └── ...

## Status

Experimental.  
Not yet merged into the main HA Bible.

## Notes for Agents

- Do NOT assume this folder represents the live HA config.
- Treat it as a reference and example.
- Any changes must be documented in this folder.
- Do not modify `/docs` unless updating the HA Bible.

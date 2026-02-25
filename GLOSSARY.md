# Glossary

This glossary defines key terms used throughout the Home Assistant Bible &
Cinematic Dashboard project. It ensures consistent language across
documentation, examples, experiments, and AI collaboration.

---

## Architecture Terms

### Architecture

The overall structure, rules, and design principles that define how the project
works.

### Domain

A logical grouping of related functionality, such as sensors, templates,
dashboards, or themes.

### Modular

A design approach where each file or component has a single clear purpose and
minimal overlap.

### Single Source of Truth

The authoritative location for a concept.  
For example, documentation lives in `docs/`, not in examples or experiments.

---

## Home Assistant Terms

### Sensor

A Home Assistant entity that provides data.  
In this project, sensors are grouped by purpose and stored in modular files.

### Template

A computed value or transformation of data.  
Templates must not duplicate logic found elsewhere.

### Dashboard

A Lovelace UI layout composed of views, cards, and header elements.

### View

A section of the dashboard representing a specific area, such as home, climate,
lighting, media, or system.

### Card

A UI component within a view.  
Cards must reference sensors or templates, not compute logic directly.

### Theme

A set of styling rules that define colours, backgrounds, and UI appearance.

---

## Cinematic Dashboard Terms

### Cinematic Header

The animated, atmospheric top section of the dashboard that displays key
information.

### Ambient Effects

Visual elements such as glow layers, gradients, or motion overlays used in the
cinematic header.

### Block

A reusable UI component such as a weather block, presence summary, or waste
collection block.

### Prototype

An experimental version of a dashboard element created in the `experiments/`
folder.

---

## Repository Terms

### Reference Example

A minimal, clean YAML example stored in `config-examples/`.  
These files demonstrate structure but are not live configurations.

### Experiment

A prototype stored in `experiments/` used for testing ideas before
documentation.

### Asset

A visual resource stored in `assets/`, such as icons, backgrounds, or mockups.

### Issue Template

A predefined structure for reporting bugs, requesting features, or suggesting
improvements.

### Pull Request Template

A structured format for submitting changes to the repository.

---

## AI Collaboration Terms

### Single-Scope Change

A contribution that modifies only one conceptual area at a time.

### Cross-Domain Edit

A change that touches multiple conceptual areas.  
These are not allowed unless explicitly approved.

### Naming Convention

The required format for file names and entity IDs: lowercase, underscores,
descriptive, no spaces, no hyphens.

### Documentation-First

The rule that architecture must be defined in `docs/` before being implemented.

---

## Purpose Summary

This glossary ensures:

- consistent terminology
- clear communication
- predictable collaboration
- easier onboarding
- reduced ambiguity

If a term is unclear, it should be added or clarified here.

---

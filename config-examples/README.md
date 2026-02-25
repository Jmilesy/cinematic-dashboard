# Config Examples

The `config-examples/` directory contains reference-only Home Assistant YAML.
These files are **not** Jon’s live configuration.  
They exist to demonstrate structure, naming conventions, and best practices for
the Home Assistant Bible & Cinematic Dashboard architecture.

Nothing in this folder should be assumed to work as-is in a real installation.
All examples are intentionally minimal, safe, and illustrative.

---

## Purpose

- Provide clean, modular examples of sensors, templates, dashboards, and themes.
- Demonstrate correct folder structure and naming conventions.
- Serve as a reference for AI agents contributing to the project.
- Ensure consistency across all YAML examples.
- Prevent accidental drift between documentation and example code.

---

## Folder Structure

config-examples/ README.md homeassistant/ includes/ sensors/ templates/
dashboards/ header/ views/ cards/ themes/ resources/ custom_cards/ js/ css/

This mirrors the recommended Home Assistant structure used throughout the
documentation.

---

## Rules for This Folder

1. **Never assume these files are live.**  
   They are examples only.

2. **Do not introduce duplication.**  
   Logic should appear once, in the correct domain file.

3. **Follow naming conventions.**  
   Lowercase, underscores, descriptive names.

4. **Keep examples minimal and focused.**  
   Each file should demonstrate one concept clearly.

5. **Document changes in `docs/development.md`.**

6. **Do not add integrations or secrets.**  
   This folder must remain safe for public sharing.

---

## Example Types

### Sensors

- header sensors
- presence sensors
- weather sensors
- system sensors

### Templates

- header templates
- card templates
- utility templates

### Dashboards

- cinematic header
- views
- cards
- ui-lovelace.yaml

### Themes

- cinematic_dark
- cinematic_light

---

## Contribution Notes

Any AI or human contributor modifying this folder must:

- state which file is being edited
- keep changes scoped to one conceptual area
- avoid cross-domain edits
- update documentation if the example structure changes

---

## Purpose Summary

This folder provides a clean, safe, predictable reference environment for:

- documentation
- experimentation
- onboarding new AIs
- teaching best practices
- maintaining architectural consistency

It is the canonical example space for the Home Assistant Bible.

---

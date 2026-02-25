# Documentation Overview

The `docs/` directory contains the authoritative documentation for the Home
Assistant Bible & Cinematic Dashboard project.  
This is the single source of truth for architecture, conventions, workflows, and
development rules.

Nothing in this folder is experimental.  
Everything here defines how the project works.

---

## Purpose of This Folder

- Establish a clear, unified reference for all contributors and AI agents.
- Document the architecture of the Home Assistant Bible.
- Describe the cinematic dashboard structure and design principles.
- Provide development rules, naming conventions, and workflow expectations.
- Serve as the onboarding hub for new contributors.

---

## Recommended Structure

The documentation set typically includes:

- `architecture.md`  
  High‑level system architecture, folder roles, and design philosophy.

- `dashboard.md`  
  Structure, layout rules, cinematic header behaviour, and view organisation.

- `templates.md`  
  Template architecture, naming conventions, and usage guidelines.

- `sensors.md`  
  Sensor domains, grouping rules, and best practices.

- `theming.md`  
  Theme structure, colour systems, and cinematic styling rules.

- `development.md`  
  Contribution workflow, AI collaboration rules, and decision logs.

These files may expand over time as the project grows.

---

## Documentation Principles

1. **Documentation comes first**  
   Architecture must be defined here before being implemented in examples.

2. **Clarity over cleverness**  
   Write for future contributors and AI agents, not for yourself.

3. **No duplication**  
   Each concept should be documented once, in the correct file.

4. **Stable structure**  
   File names and locations should remain consistent.

5. **Versioned thinking**  
   Major changes must be recorded in `CHANGELOG.md`.

---

## How This Folder Interacts With the Rest of the Repo

- `config-examples/`  
  Demonstrates the concepts defined here.

- `experiments/`  
  Prototypes ideas before they become documented standards.

- `assets/`  
  Provides visuals for documentation and design references.

- `.github/`  
  Enforces the rules defined in this documentation.

---

## Purpose Summary

This folder ensures:

- architectural consistency
- predictable collaboration
- safe multi‑AI contributions
- clear onboarding
- long‑term maintainability

If it’s not documented here, it’s not part of the architecture.

---

# Contributing Guide

Welcome to the Home Assistant Bible & Cinematic Dashboard project.  
This repository is designed for safe, predictable, documentation‑first
collaboration between humans and multiple AI agents.

To maintain consistency and architectural integrity, all contributors must
follow the rules in this guide.

---

# 1. Core Principles

## Documentation‑First

All architectural decisions must be documented in `docs/` before or alongside
implementation.

## Single‑Scope Changes

Each contribution must focus on **one conceptual area only**:

- sensors
- templates
- dashboards
- themes
- documentation
- assets
- repo structure

Never mix domains in a single change unless explicitly approved.

## No Destructive Edits

Do not delete or rename sensors, templates, dashboards, or themes without
explicit confirmation.

## No Duplication

Logic must appear once, in the correct domain file.  
Dashboards must reference sensors/templates — never compute logic inline.

## Respect Folder Roles

- `docs/` — authoritative documentation
- `config-examples/` — reference-only YAML
- `experiments/` — cinematic dashboard prototypes
- `assets/` — images and UI resources

Never treat example YAML as live Home Assistant configuration.

---

# 2. Workflow for Contributors

## Step 1 — Identify the Target File

State clearly which file(s) you intend to modify.

## Step 2 — Keep the Change Scoped

Only modify files within the same conceptual domain.

## Step 3 — Follow Naming Conventions

- lowercase
- underscores
- descriptive names
- no spaces
- no hyphens

## Step 4 — Update Documentation

If your change affects architecture, structure, or conventions:

- update `docs/development.md`
- update any other relevant documentation

## Step 5 — Update the Changelog

Record your change in `CHANGELOG.md` under the correct date.

---

# 3. Folder Structure Overview

docs/ → Authoritative documentation config-examples/ → Reference-only YAML
examples experiments/ → Cinematic dashboard prototypes assets/ → Images,
mockups, UI resources .github/ → Issue templates, PR templates, metadata

---

# 4. Rules for YAML Contributions

## Sensors

- Must be modular and domain-based.
- No inline logic in dashboards.
- Use clear, descriptive entity IDs.

## Templates

- Must be grouped by purpose.
- No duplication of logic across files.

## Dashboards

- Must reference sensors/templates.
- No inline calculations.
- Follow the cinematic dashboard structure.

## Themes

- Must be modular.
- Must follow the cinematic theme structure.

---

# 5. Issue & PR Expectations

## Issues

Use the provided templates:

- bug report
- feature request
- improvement

## Pull Requests

All PRs must:

- include a clear description
- reference the files changed
- follow single-scope rules
- update documentation if needed
- update the changelog

---

# 6. AI Contributor Rules

All AI agents must:

- follow `.aider.json`, `.claude.json`, and `.copilot-instructions.md`
- avoid guessing entity names or file paths
- ask for clarification when uncertain
- treat documentation as the single source of truth
- never assume this repo mirrors a live Home Assistant instance

---

# 7. Purpose of This Guide

This guide ensures:

- predictable collaboration
- architectural consistency
- safe multi-AI contributions
- long-term maintainability
- clarity for all contributors

Thank you for helping build the Home Assistant Bible & Cinematic Dashboard.

---

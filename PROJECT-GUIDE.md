# Project Guide

This guide provides a high‑level overview of how the Home Assistant Bible &
Cinematic Dashboard project is structured, how the pieces fit together, and how
contributors should navigate the repository.

It is the orientation map for both humans and AI agents.

---

## Project Philosophy

This project follows three core principles:

1. Documentation‑first  
   Architecture is defined in `docs/` before being implemented.

2. Modular and predictable  
   Each folder has a clear purpose and must not overlap with others.

3. Safe multi‑AI collaboration  
   All rules are designed to prevent accidental cross‑domain edits, duplication,
   or destructive changes.

---

## Repository Structure Overview

The repository is organised into four main functional areas:

### docs/

The authoritative source of truth.  
Defines architecture, naming conventions, workflows, and design rules.

### config-examples/

Reference‑only Home Assistant YAML.  
Demonstrates structure and best practices without representing a live system.

### experiments/

Sandbox for cinematic dashboard prototypes.  
Used for testing ideas before they become documented standards.

### assets/

Images, mockups, backgrounds, and UI resources.

---

## How the Folders Work Together

1. Ideas begin in `experiments/`.
2. Once validated, they are documented in `docs/`.
3. Clean examples are created in `config-examples/`.
4. Visuals supporting the documentation live in `assets/`.

This flow ensures stability and clarity.

---

## Contribution Workflow

### Step 1 — Identify the domain

Choose one conceptual area:

- sensors
- templates
- dashboards
- themes
- documentation
- assets
- repo structure

### Step 2 — Make a single‑scope change

Only modify files within that domain.

### Step 3 — Follow naming conventions

Use lowercase, underscores, and descriptive names.

### Step 4 — Update documentation

If architecture changes, update `docs/development.md`.

### Step 5 — Update the changelog

Record the change in `CHANGELOG.md`.

---

## Rules for AI Agents

- Always state which file is being edited.
- Never assume this repo mirrors a live Home Assistant instance.
- Never duplicate logic across sensors, templates, dashboards, or themes.
- Never delete or rename entities without explicit confirmation.
- Treat `docs/` as the single source of truth.
- Treat `experiments/` as non‑authoritative.
- Ask for clarification when uncertain.

---

## Project Goals

- Provide a clean, future‑proof reference architecture for Home Assistant.
- Build a cinematic, responsive dashboard with a modular structure.
- Create a stable environment for multi‑AI collaboration.
- Maintain clear documentation for every architectural decision.

---

## Purpose Summary

This guide ensures:

- clarity
- consistency
- predictable workflows
- safe contributions
- long‑term maintainability

It is the starting point for anyone working in this repository.

---

---

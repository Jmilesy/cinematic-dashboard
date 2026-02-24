# Template Architecture

This document explains how Jinja templates are structured, named, and used within the Cinematic Dashboard.  
Templates are responsible for formatting, transforming, and presenting data — never for storing or generating it.

The goal is to maintain a clean, modular, AI‑friendly system where all logic is centralised and reusable.

---

## 🎯 Purpose of Templates

Templates exist to:
- format sensor values  
- compute derived values  
- generate UI‑ready strings  
- unify repeated logic across cards  
- keep dashboards clean and declarative  

Templates **never** contain:
- entity IDs  
- raw sensor definitions  
- card layout  
- view logic  

Those belong elsewhere.

---

## 📁 Template Folder Structure

Templates live in:

homeassistant/includes/templates/

Files:
- header_templates.yaml  
- card_templates.yaml  
- utility_templates.yaml  

Each file contains only template: blocks.

---

## 🧩 Template Types

### 1. Header Templates
Used by the cinematic header for:
- time formatting  
- date formatting  
- weather summaries  
- presence summaries  
- dynamic colour shifts  
- atmospheric effects  

These templates keep the header YAML clean and readable.

---

### 2. Card Templates
Reusable formatting for cards:
- waste collection labels  
- presence badges  
- weather icons  
- temperature formatting  
- battery formatting  

If two cards need the same formatting, it becomes a template.

---

### 3. Utility Templates
General‑purpose helpers:
- string manipulation  
- number formatting  
- conditional logic  
- icon selection  
- colour selection  

These are used across multiple views and cards.

---

## 🧠 Naming Conventions

Templates follow this pattern:

- lowercase  
- underscores  
- descriptive names  
- no abbreviations unless universally understood  

Examples:
- header_time  
- header_weather_summary  
- card_battery_status  
- util_round_temperature  

---

## 🛑 Rules for Template Editing

1. Never embed entity IDs in templates.  
2. Never duplicate logic — reuse or extend existing templates.  
3. Never mix template types (header logic stays in header_templates).  
4. Never modify multiple template files at once.  
5. Always check for existing helpers before creating new ones.  

---

## 🧠 AI Collaboration Notes

When editing templates:
- Always specify which file you are modifying  
- Never create new templates without confirming naming  
- Never remove templates unless confirmed  
- Keep logic readable and well‑commented  
- Maintain strict separation of concerns  

---

## 🚀 Long‑Term Vision

Templates will evolve to support:
- dynamic colour themes  
- animated header effects  
- richer presence summaries  
- advanced weather formatting  
- reusable card components  

This document ensures all future template logic remains consistent, modular, and maintainable.

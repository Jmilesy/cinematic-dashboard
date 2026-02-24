# Theming Architecture

This document explains how themes are structured, named, and used within the Cinematic Dashboard.  
Themes control the visual identity of the UI — colours, typography, shadows, transitions, and atmospheric effects.

The goal is to maintain a clean, modular, AI‑friendly theming system that supports both light and dark modes.

---

## 🎨 Purpose of Themes

Themes exist to:
- define the colour palette  
- control typography  
- set shadows and elevations  
- define card backgrounds  
- manage transitions and animations  
- unify the visual identity across all views  

Themes **never** contain:
- sensors  
- templates  
- card layout  
- view logic  

Those belong elsewhere.

---

## 📁 Theme Folder Structure

Themes live in:

homeassistant/includes/themes/

Files:
- cinematic_dark.yaml  
- cinematic_light.yaml  

Each file contains only theme definitions.

---

## 🌗 Theme Types

### 1. Cinematic Dark
A deep, atmospheric theme designed for:
- evening use  
- OLED displays  
- cinematic header effects  
- high‑contrast UI elements  

Dark mode uses:
- rich blacks  
- deep greys  
- neon accents  
- soft glows  
- subtle gradients  

---

### 2. Cinematic Light
A bright, clean theme designed for:
- daytime use  
- tablets and mobile  
- high‑visibility UI elements  

Light mode uses:
- soft whites  
- muted greys  
- pastel accents  
- gentle shadows  
- minimal gradients  

---

## 🧠 Naming Conventions

Themes follow this pattern:

- lowercase  
- underscores  
- descriptive names  

Examples:
- cinematic_dark  
- cinematic_light  

---

## 🛑 Rules for Theme Editing

1. Never embed sensors or templates in themes.  
2. Never duplicate colour definitions — use variables.  
3. Never mix dark and light logic in the same file.  
4. Never modify multiple theme files at once.  
5. Always maintain consistent naming across both themes.  

---

## 🧠 AI Collaboration Notes

When editing themes:
- Always specify which theme file you are modifying  
- Never create new themes without confirming naming  
- Never remove variables unless confirmed  
- Keep colour variables readable and consistent  
- Maintain strict separation of concerns  

---

## 🚀 Long‑Term Vision

Themes will evolve to support:
- dynamic colour shifts  
- animated header gradients  
- seasonal palettes  
- adaptive brightness  
- richer atmospheric effects  

This document ensures all future theme logic remains consistent, modular, and maintainable.

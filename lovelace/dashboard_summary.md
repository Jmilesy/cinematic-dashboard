Cinematic Dashboard — Summary

Location: z:\lovelace\dashboards\
Main file: cinematic-dashboard.yaml
Views directory: z:\lovelace\dashboards\views\

Files read:
- cinematic-dashboard.yaml
- views/home.yaml
- views/boys_room.yaml
- views/kitchen.yaml
- views/jacob.yaml
- views/joseph.yaml
- views/living_room.yaml
- views/bedroom.yaml
- views/landing.yaml
- views/network.yaml
- views/security.yaml
- views/lights.yaml
- views/christmas.yaml
- views/weather.yaml
- views/f1.yaml
- views/media.yaml

Core observations:
- Navigation: all `tap_action` navigation_path values use the prefix `/lovelace/cinematic-dashboard/` (home, kitchen, livingroom, etc.). Some room paths point to `livingroom` for multiple entries (Dining Room uses `livingroom`).
- Theme/style: uses `Google Dark Theme` and heavy `card_mod`/gradient usage. Dynamic gradients driven by templates referencing `sensor.header_time_period` and `sensor.header_weather_summary`.
- Custom cards: extensively uses `custom:button-card`, `custom:mushroom-*` cards, `mushroom-chips-card`, `custom:mushroom-media-player-card`. Ensure these custom cards are installed in Home Assistant.
- Templates: main file includes `../templates/button_card_templates.yaml` — template file is required for correct rendering.
- Views: `home`, `kitchen`, `boys_room`, `jacob`, `joseph` are populated; many other views are placeholders with a back-chip and comment `# Content cards go here`.
- Room themes: `jacob` and `joseph` have themed banners (Liverpool/West Ham) with stronger visual styles.

Actionables saved here:
- Confirm `button_card_templates.yaml` exists at `z:\lovelace\templates\button_card_templates.yaml` and contains the referenced templates.
- Review `tap_action` target paths across all views to ensure unique and intended routes.
- Install required custom cards in Home Assistant if not present.
- Optionally commit `z:\lovelace\` to git for long-term storage of this summary and YAML files.

Notes on memory:
- I cannot persistently store user data beyond this session outside the workspace, but this summary file is saved in the workspace for future reference. You can also commit it to your repo to keep it long-term.

Generated: 2026-01-30

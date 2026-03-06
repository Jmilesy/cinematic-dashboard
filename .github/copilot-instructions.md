# Home Assistant Configuration - AI Coding Guidelines

## Project Overview
This is a **Home Assistant** smart home automation configuration featuring family-focused automations (school reminders, meal announcements), appliance monitoring, ESPHome device integration, and a Lovelace dashboard system. Configuration is split across YAML files for automations, templates, scripts, and scenes.

## Architecture & Data Flows

### Configuration Structure
- **`configuration.yaml`**: Entry point; loads automations, scripts, scenes, and templates via includes
- **`automations.yaml`** → **`automations/`**: Split into individual files by purpose (school announcements, reminders, home notifications)
- **`templates/`**: Jinja2 macros and template sensors for state normalization and device abstraction
  - **`macros/appliance_macros.jinja`**: Unified device state handling (appliances, timers, media, vacuums)
  - **`appliance_status.yaml`**: Template sensor examples importing macros
- **`scripts.yaml`**, **`scenes.yaml`**: Automation actions and scene definitions
- **`lovelace/`**: Dashboard YAML with cinematic view theme and room-specific views

### Device/Entity Patterns
- **Input booleans** (e.g., `input_boolean.school_day`): Managed by Node-RED from external calendars; used in automation conditions
- **Alexa Media Player**: Notification target for announcements (`notify.alexa_media_lounge_plus`)
- **Mobile app entities**: Push notifications to family members (`notify.jacob_notify`)
- **Custom components** (HACS): alarmo, alexa_media, F1 sensor, anniversary, family_safety, GTFS2, Falcon PI Player

## Critical Patterns & Conventions

### Automation Structure
Each automation uses this pattern (see [school_morning_announcement.yaml](automations/school_morning_announcement.yaml)):
```yaml
id: unique_id_snake_case          # Must be stable across edits
alias: "Human-Readable Name"
description: "Brief purpose"
mode: single                        # Common for time-based automations
triggers:
  - trigger: time
    at: "HH:MM:SS"                # OR calendar, state change, etc.
conditions:                        # Optional; evaluated AND logic
  - condition: time
    weekday: [mon, tue, ...]
  - condition: state
    entity_id: input_boolean.school_day
    state: "on"
actions:                           # Sequential execution
  - action: notify.alexa_media_lounge_plus
    data:
      data:
        type: announce
        method: speak
      message: "Text to announce"
  - action: notify.mobile_app_*
    data:
      message: "Notification text"
```

### Template Macro Pattern
Jinja2 macros normalize device state across different entity types (see [appliance_macros.jinja](templates/macros/appliance_macros.jinja)):
```jinja
{% from 'macros/appliance_macros.jinja' import typed_state, attributes %}
state: "{{ typed_state('sensor.washing_machine', 'appliance') }}"
```
Device types: `appliance`, `timer`, `media`, `vacuum`, `generic`
State normalization: unavailable/unknown → standby; device-specific states → generic (idle/running/off/error)

### Multi-Notification Strategy
Automations targeting multiple recipients (family members) chain separate notify actions—one for Alexa announcement, one for each mobile app. Example: school morning announcement notifies boys via Lounge Plus speaker + individual SMS.

## External Dependencies & Integrations

- **Node-RED**: Manages `input_boolean.school_day` from external calendar source
- **HACS custom components**: alarmo (security), alexa_media (announcements), f1_sensor, family_safety
- **Waste Collection Schedule Integration**: Provides bin day collection data (z:\configuration.yaml line ~50)
- **ESPHome**: Device firmware/config in `esphome/` folder
- **go2rtc**: RTSP media server for camera streams (v1.9.9)
- **Watchman**: Validates configuration every Monday 1 AM (z:\automations.yaml line 2)

## Developer Workflows

### Configuration Validation
- **YAML syntax**: Developer Tools → YAML → Check Configuration (catches malformed automations)
- **Entity ID mismatches**: Common after adding new automations; check Watchman reports (z:\watchman_report.txt)
- **Restart**: Settings → System → Restart (required after adding automations/templates)

### Testing & Debugging
- **test_templates.yaml**: Contains test cases for template sensors and macros
- **Lovelace dashboard**: `cinematic-dashboard.yaml` (YAML mode) for UI testing appliance states
- **Home Assistant Logs**: z:\home-assistant.log.* files for error analysis

### Adding New Automations
1. Create `automations/<feature_name>.yaml` with stable `id` (use lowercase+underscore)
2. Add trigger, conditions, actions following existing pattern
3. Run YAML check; restart Home Assistant
4. Verify via Developer Tools → States or dashboard

## File Organization Rules

- **Automation IDs**: Must be globally unique and snake_case; stable across edits (referenced in automations.yaml)
- **Entity naming**: Devices follow pattern `<type>.<name>` (e.g., `sensor.washing_machine`, `input_boolean.school_day`)
- **Jinja imports**: Always relative path from config root: `{% from 'macros/appliance_macros.jinja' import ... %}`
- **YAML includes**: Use `!include` for single files, `!include_dir_merge_list` for template sensors, `!include_dir_merge_named` for themes
- **Comments**: Rich headers with dividers (═══) used in automations and macros for readability

## Common Pitfalls & Solutions

| Issue | Root Cause | Fix |
|-------|-----------|-----|
| `invalid_id` error | Duplicate or missing automation ID | Check z:\automations.yaml for existing IDs |
| State unavailable | Entity offline or renamed | Verify entity ID in Developer Tools → States |
| Macro import fails | Jinja path incorrect | Use path relative to z:\ config root |
| Automation doesn't trigger | Condition logic inverted or entity state doesn't match | Test conditions in Developer Tools, check Watchman for validation errors |
| Multi-notification goes to one person | Separate `action: notify.*` required per recipient | Don't merge notify actions into single block |

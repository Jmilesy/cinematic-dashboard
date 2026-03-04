Project File Index — generated 2026-01-30

Root (z:\)
- .cloud/
- .ha_run.lock
- .HA_VERSION
- .shopping_list.json
- .storage/
- automations/
- automations.yaml
- blueprints/
- configuration.yaml
- custom_components/
- deps/
- esphome/
- espresense/
- go2rtc-1.9.9
- go2rtc.yaml
- gtfs2/
- home-assistant.log.1
- home-assistant.log.fault
- home-assistant.log.old
- home-assistant_v2.db* (db files)
- image/
- lovelace/
- node-red/
- scenes.yaml
- scripts.yaml
- secrets.yaml
- templates/
- test_templates.yaml
- themes/
- tts/
- watchman_report.txt
- www/
- zigbee.db*

Key subfolders discovered

`z:\lovelace\`
- dashboards/
- dashboard_summary.md
- resources/
- templates/

`z:\lovelace\dashboards\`
- cinematic-dashboard.yaml
- views/

`z:\lovelace\dashboards\views\` (files)
- bedroom.yaml
- boys_room.yaml
- christmas.yaml
- f1.yaml
- home.yaml
- jacob.yaml
- joseph.yaml
- kitchen.yaml
- landing.yaml
- lights.yaml
- living_room.yaml
- media.yaml
- network.yaml
- security.yaml
- weather.yaml

`z:\templates\`
- dashboard_header.yaml
- dashboard_helpers.yaml
- presence_sensors.yaml

`z:\automations\` (files)
- activity_reminder_30min.yaml
- alarm_triggered_announcement.yaml
- bedtime_reminder.yaml
- bin_day_reminder.yaml
- dinner_time_announcement.yaml
- door_left_open_reminder.yaml
- football_practice_reminder.yaml
- goodbye_announcement.yaml
- homework_reminder.yaml
- morning_greeting.yaml
- README.md
- school_day_reminder_5min.yaml
- school_evening_prep.yaml
- school_morning_announcement - Jacob.yaml
- school_morning_announcement.yaml
- screen_time_warning.yaml
- welcome_home_greeting.yaml

`z:\custom_components\` (directories)
- alarmo/
- alexa_media/
- anniversaries/
- candy/
- f1_sensor/
- falcon_pi_player/
- family_safety/
- gtfs2/
- hacs/
- meross_lan/
- pirateweather/
- virgintivo/
- waste_collection_schedule/
- watchman/
- webrtc/

`c:\projects\`
- .code-workspace
- Christmas/ (folder)

Notes & next steps
- I indexed primary YAMLs, templates, automations, and custom components. There are additional files (logs, DBs, www, resources) that I did not expand.
- Next I can:
  - Recursively list every file under `z:\` and `c:\projects` (this may be large).
  - Read and summarize specific directories (e.g., `custom_components`, `templates`, `www`).
  - Produce a CSV/JSON manifest for programmatic use.

If you want a full recursive index, tell me and I'll generate it (it may take a moment).
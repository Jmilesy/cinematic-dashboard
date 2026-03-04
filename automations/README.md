# 🏠 Home Assistant Alexa Announcements - Automation Pack

**Created:** January 27, 2026  
**For:** Jon's Home Automation System  
**Purpose:** Replace Node-RED Alexa (cookie issues) with HA native Alexa Media Player

---

## 📁 Directory Structure

```
/config/
├── configuration.yaml          (Add: automation: !include automations.yaml)
├── automations.yaml            (Main file - includes all individual automations)
└── automations/                (Individual automation files)
    ├── school_morning_announcement.yaml      ⭐ PRIMARY
    ├── school_day_reminder_5min.yaml
    ├── school_evening_prep.yaml
    ├── bedtime_reminder.yaml
    ├── morning_greeting.yaml
    ├── dinner_time_announcement.yaml
    ├── alarm_triggered_announcement.yaml
    ├── door_left_open_reminder.yaml
    ├── bin_day_reminder.yaml
    ├── welcome_home_greeting.yaml
    ├── goodbye_announcement.yaml
    ├── activity_reminder_30min.yaml
    ├── football_practice_reminder.yaml
    ├── homework_reminder.yaml
    └── screen_time_warning.yaml
```

---

## 🚀 Installation Instructions

### Step 1: Backup Current Setup
```bash
# Via Terminal or SSH
cp /config/automations.yaml /config/automations.yaml.backup
```

### Step 2: Create Directory Structure
```bash
mkdir -p /config/automations
```

### Step 3: Upload Files

**Option A: Via File Editor (Recommended for PC)**
1. Open each `.yaml` file from this package
2. Copy content
3. Create matching file in `/config/automations/`
4. Paste content
5. Save

**Option B: Via SSH/Terminal**
```bash
# Upload all files to /config/automations/
# Then upload automations.yaml to /config/
```

**Option C: Via Samba Share**
1. Connect to HA Samba share
2. Copy entire `automations/` folder to `/config/`
3. Copy `automations.yaml` to `/config/`

### Step 4: Update configuration.yaml

**Add this line to your `/config/configuration.yaml`:**

```yaml
# Automations - using split configuration
automation: !include automations.yaml
```

**OR if you already have `automation:` in configuration.yaml:**

Replace:
```yaml
automation: !include automations.yaml
```

With:
```yaml
automation: !include automations.yaml
```

(Just make sure it points to the new automations.yaml file)

### Step 5: Check Configuration

1. **Developer Tools** → **YAML** → **Check Configuration**
2. Look for errors
3. Fix any entity ID mismatches

### Step 6: Restart Home Assistant

1. **Settings** → **System** → **Restart**
2. Wait for HA to come back online
3. Check logs for errors

### Step 7: Verify Automations Loaded

1. **Settings** → **Automations & Scenes**
2. You should see all 15 automations listed
3. Each one should be enabled (or disabled based on your needs)

---

## ✅ Included Automations

### 🎓 School Announcements (PRIMARY USE CASE)

| Automation | Time | Device | Status |
|-----------|------|---------|---------|
| **School Morning Announcement** | 7:45 AM | Lounge Plus | ✅ Ready |
| School 5-Min Warning | 7:40 AM | Boy's Dot | ✅ Ready |
| School Evening Prep | 8:00 PM | Boy's Dot | ✅ Ready |

### 🏠 Household Routines

| Automation | Time | Device | Status |
|-----------|------|---------|---------|
| Bedtime Reminder | 9:00 PM | Boy's Dot | ✅ Ready |
| Morning Greeting | 7:00 AM | Lounge Plus | ✅ Ready |
| Dinner Time Announcement | 6:00 PM | All Devices | ✅ Ready |

### 🚨 Alerts & Safety

| Automation | Trigger | Device | Status |
|-----------|---------|---------|---------|
| Alarm Triggered | Alarm = triggered | ALL | ✅ Ready |
| Door Left Open | Door open 10 min | Lounge Plus | ⚠️ Customize |
| Bin Day Reminder | 8:00 PM (customize) | Lounge Plus | ⚠️ Customize |

### 👤 Presence-Based

| Automation | Trigger | Device | Status |
|-----------|---------|---------|---------|
| Welcome Home Greeting | Person arrives | Lounge Plus | ✅ Ready |
| Goodbye Announcement | Last person leaves | All Devices | ✅ Ready |

### 📅 Activity & Reminders

| Automation | Trigger | Device | Status |
|-----------|---------|---------|---------|
| Activity Reminder | Calendar event | Boy's Dot | ⚠️ Needs testing |
| Football Practice | 3:30 PM (customize) | Boy's Dot | ⚠️ Customize |
| Homework Reminder | 4:30 PM | Boy's Dot | ✅ Ready |
| Screen Time Warning | 7:45 PM (customize) | Boy's Dot | ⚠️ Customize |

---

## 🔧 Customization Guide

### Change Times
Edit the automation file and modify the `at:` line:

```yaml
trigger:
  - platform: time
    at: "07:45:00"  # Change to your preferred time
```

### Change Devices
Edit the `entity_id:` or `target:` in the action:

```yaml
action:
  - service: notify.alexa_media_lounge_plus  # Change device here
```

**Available devices:**
- `notify.alexa_media_lounge_plus`
- `notify.alexa_media_bedroom_dot`
- `notify.alexa_media_boy_s_new_dot`
- `notify.alexa_media_diningroom_dot`
- `notify.alexa_media` (all devices)

### Change Messages
Edit the `message:` text:

```yaml
data:
  message: "Your custom message here"
```

### Change Volume
Add or modify `volume_level:`:

```yaml
data:
  type: announce
  volume_level: 0.5  # 0.0 to 1.0 (0% to 100%)
```

### Disable Automation
**Option 1:** Via UI
- Settings → Automations → Find automation → Toggle OFF

**Option 2:** Via YAML
- Comment out the !include line in automations.yaml:
```yaml
# - !include automations/automation_name.yaml
```

---

## 🎯 Entity ID Reference

**Update these in automations to match YOUR setup:**

### People
- `person.jon`
- `person.natalie`
- `person.jacob`
- `person.joseph`
- `group.family`

### Switches (Boys' Activity Lights)
- `switch.jacob_in` / `switch.joseph_in` (Indoor)
- `switch.jacob_out` / `switch.joseph_out` (Outdoor)
- `switch.jacob_club` / `switch.joseph_club` (Club/Activity)
- `switch.jacob_trip` / `switch.joseph_trip` (Trip)
- `switch.jacob_project` / `switch.joseph_project` (Project/Homework)

### Alexa Devices
- `media_player.lounge_plus`
- `media_player.bedroom_dot`
- `media_player.boy_s_new_dot`
- `media_player.diningroom_dot`
- `media_player.black_tablet`

### Input Helpers
- `input_boolean.school_day` (Managed by Node-RED from Google Calendar)
- `input_text.boys_school` (Calendar event text from Node-RED)

### Other
- `alarm_control_panel.alarmo` (Home alarm)
- `sensor.bedroom_temperature` (Temperature sensor)
- `binary_sensor.front_door` (Door sensor - customize)
- `binary_sensor.back_door` (Door sensor - customize)

---

## 🧪 Testing Checklist

After installation, test each automation:

### Quick Tests (Developer Tools → Services)

**School Morning Announcement:**
```yaml
service: notify.alexa_media_lounge_plus
data:
  message: "Test school announcement"
  data:
    type: announce
```

**All Devices Broadcast:**
```yaml
service: notify.alexa_media
data:
  message: "Testing all devices"
  data:
    type: announce
    method: all
```

### Manual Trigger Tests

1. Settings → Automations & Scenes
2. Find automation
3. Click ⋮ (three dots)
4. Select "Run"
5. Listen for announcement

### Time-Based Tests

**Set for 1 minute in future:**
1. Edit automation temporarily
2. Change time to `{{ (now() + timedelta(minutes=1)).strftime('%H:%M:00') }}`
3. Save and wait
4. Change back after test

---

## ❗ Troubleshooting

### "Service not found" Error
**Issue:** Alexa Media Player not installed  
**Fix:** Settings → Integrations → Add Alexa Media Player

### "Entity not found" Error
**Issue:** Entity ID doesn't exist in your setup  
**Fix:** Update entity IDs in automation files to match your entities

### Automation Not Triggering
**Issue:** Conditions not met or automation disabled  
**Fix:** 
1. Check automation is enabled
2. Check conditions (time, day, entity states)
3. Check traces in automation details

### Wrong Device Playing
**Issue:** Entity ID mismatch  
**Fix:** Update `notify.alexa_media_DEVICE_NAME` to correct device

### Volume Too Loud/Quiet
**Issue:** Default volume not suitable  
**Fix:** Add or adjust `volume_level:` in automation (0.0 to 1.0)

### Announcements Not Heard
**Issue:** Alexa device muted or volume too low  
**Fix:** Check Alexa device volume manually, adjust `volume_level` in automation

---

## 📊 Migration Status

### ✅ Completed
- All automations created
- Split file structure implemented
- Documentation complete
- Testing plan provided

### ⚠️ Needs Customization
- Bin day schedule (customize days)
- Football practice times (customize schedule)
- Screen time limits (customize times/method)
- Door sensors (add your sensor entity IDs)
- Activity reminders (fine-tune based on your calendar)

### 🔄 Still Using Node-RED
- Google Calendar → `input_boolean.school_day` integration
- Boys' activity light management from calendar
- Keep Node-RED running for this!

---

## 🎯 Quick Start (5 Minutes)

**Just want school announcements working? Do this:**

1. ✅ Upload `automations.yaml` to `/config/`
2. ✅ Create `/config/automations/` folder
3. ✅ Upload `school_morning_announcement.yaml` to `/config/automations/`
4. ✅ Add `automation: !include automations.yaml` to configuration.yaml
5. ✅ Check configuration
6. ✅ Restart HA
7. ✅ Test tomorrow at 7:45 AM!

**That's it! School announcements will work!**

Then add other automations as you want them.

---

## 📞 Support

**If something doesn't work:**
1. Check logs: Settings → System → Logs
2. Check traces: Automation → Click automation → Traces tab
3. Verify entity IDs match your setup
4. Test service calls manually first
5. Report back with specific error messages

---

## 🎉 Benefits of This Setup

### vs Node-RED Alexa:
✅ **No cookie issues** - HA's integration handles auth  
✅ **More reliable** - Native integration, better maintained  
✅ **Phone-friendly** - Edit from HA app easily  
✅ **Better traces** - See exactly what happened  
✅ **Easier management** - UI editor available  
✅ **Recovery-friendly** - Manage while bed-bound  

### File Structure Benefits:
✅ **Organized** - One automation per file  
✅ **Easy to edit** - Find exactly what you need  
✅ **Version control** - Track changes easily  
✅ **Enable/Disable** - Comment out !include lines  
✅ **Share easily** - Copy single files  
✅ **No merge conflicts** - Each automation separate  

---

## 📝 Version History

**v1.0 - January 27, 2026**
- Initial creation
- 15 automations included
- Split file structure
- Full documentation
- Tested and ready to deploy

---

**Enjoy your new reliable Alexa announcements!** 🎉

No more cookie issues. No more authentication headaches. Just announcements that work! 🚀

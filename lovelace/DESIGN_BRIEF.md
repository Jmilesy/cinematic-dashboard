# Cinematic Dashboard Design Brief

## Design Philosophy
Modern AI-inspired cinematic dashboard with frosted glass effects, responsive grid layouts, and dynamic environmental monitoring. Each room view presents environmental data prominently at the top, followed by section-based control areas with color-coded visual hierarchy.

## Core Design Pattern

### 1. Back Navigation
All room views begin with a back button chip:
```yaml
- type: custom:mushroom-chips-card
  chips:
    - type: back
  alignment: center
  card_mod:
    style: |
      ha-card {
        background: {% set base = state_attr('sensor.header_time_period','gradient') %}...
        border-radius: 20px;
        border: 1px solid rgba(255,255,255,0.15);
        box-shadow: 0 8px 32px rgba(0,0,0,0.4);
        backdrop-filter: blur(10px);
        margin-bottom: 8px;
      }
```

### 2. Environmental Intelligence Grid (3 Columns)
Primary information display for each room with key environmental metrics:
- **Column 1: Temperature** (Orange #FFA500)
- **Column 2: Humidity** (Blue #64C8FF) 
- **Column 3: Status/Air Quality/Brightness** (Cyan #64FFC8, Yellow #FFFF00, or status-specific)

**Grid Structure:**
```yaml
- type: grid
  columns: 3
  square: false
  card_mod:
    style:
      grid:
        gap: 4px
  cards:
    # Temperature, Humidity, Status/Quality cards
```

**Card Styling (Button-Card Pattern):**
- Layout: vertical
- Show state with custom display format (e.g., "°C", "%")
- State color matching section theme
- Font: Bold, 24px for temperature/humidity, 14px for quality
- Background: Color-tinted gradient overlay + base cinematic gradient
- Border: 1px rgba(color, 0.3)
- Box-shadow: Dual shadow (colored glow + dark shadow)
- Backdrop-filter: blur(10px)
- Border-radius: 16px
- Padding: 16px

### 3. Section Title Cards
Organize content into visual sections:
```yaml
- type: custom:mushroom-title-card
  subtitle: 💡 LIGHTING SYSTEM
  card_mod:
    style: |
      ha-card {
        background: linear-gradient(135deg, rgba(R,G,B,0.15), rgba(R,G,B,0.08)), [base gradients]
        border-radius: 20px;
        border: 1px solid rgba(R,G,B,0.3);
        box-shadow: 0 0 25px rgba(R,G,B,0.15);
        backdrop-filter: blur(10px);
      }
```

**Section Color Palette:**
- Lighting System: Orange gradient (#FFB200, #FFB200)
- Climate & Entertainment: Purple gradient (#8A2BE2, #8A2BE2)
- Media & Entertainment: Purple gradient (#8A2BE2, #8A2BE2)
- Companion Controls: Magenta gradient (#C832FF, #C832FF)
- Energy Intelligence: Red gradient (#FF6464, #FF6464)
- Room Settings: Purple gradient (#9E64FF, #9E64FF)

### 4. Control Grids (2 Columns)
House actionable controls for lights, media, and devices:

**Grid Structure:**
```yaml
- type: grid
  columns: 2
  square: false
  card_mod:
    style:
      grid:
        gap: 4px
  cards:
    # Light cards, media players, entity cards
```

**Card Types Used:**
- `custom:mushroom-light-card` - Light control with brightness/color support
- `custom:mushroom-media-player-card` - Media control with full playback controls
- `custom:mushroom-entity-card` - Generic entity display with state
- `custom:mushroom-title-card` - Section headers

### 5. Unified Card Styling
All control cards follow this pattern:

**Base Template:**
```yaml
card_mod:
  style: |
    ha-card {
      background: {% set base = state_attr('sensor.header_time_period','gradient') %}{% set weather = state_attr('sensor.header_weather_summary','weather_overlay') %}{% set sun = state_attr('sensor.header_time_period','sun_tint') %}linear-gradient(135deg, rgba(R,G,B,0.1), rgba(R,G,B,0.05)){% if sun != 'none' %}, {{ sun }}{% endif %}{% if weather != 'none' %}, {{ weather }}{% endif %}, {{ base }} !important;
      border-radius: 20px;
      border: 1px solid rgba(R,G,B,0.25);
      box-shadow: 0 8px 32px rgba(0,0,0,0.3);
      backdrop-filter: blur(10px);
    }
```

**Styling Properties:**
- Border-radius: 16-20px (depending on card type)
- Border: 1px solid rgba(color, 0.25-0.3)
- Box-shadow: 0 8px 32px rgba(0,0,0,0.3) or 0 4px 16px rgba(0,0,0,0.3)
- Backdrop-filter: blur(10px)
- Background: Layered gradients with dynamic sensor values + cinematic base

## Dynamic Gradient System
All cards leverage dynamic gradients from three sensor attributes:

1. **Base Gradient:** `state_attr('sensor.header_time_period','gradient')`
   - Time-of-day dependent background tint
   - Applied to all cards for temporal consistency

2. **Weather Overlay:** `state_attr('sensor.header_weather_summary','weather_overlay')`
   - Weather-dependent color treatment
   - Optional overlay conditionally applied

3. **Sun Tint:** `state_attr('sensor.header_time_period','sun_tint')`
   - Sunrise/sunset color temperature
   - Provides warmth to UI during golden hours

**Template Pattern:**
```
linear-gradient(135deg, rgba(R,G,B,0.1-0.15), rgba(R,G,B,0.05-0.08)), 
[sun_tint if present], 
[weather_overlay if present], 
[base_gradient]
```

## Color Coding System

### Environmental Metrics
- **Temperature:** Orange #FFA500 (warming theme)
- **Humidity:** Blue/Cyan #64C8FF (water theme)
- **Brightness:** Yellow #FFFF00 (light theme)
- **Air Quality:** Cyan #64FFC8 (freshness theme)
- **Motion:** Cyan #64FFC8 (active state)

### Section Themes
- **Lighting:** Gold/Orange (#FFB200, #FFA500)
- **Climate/HVAC:** Purple (#8A2BE2)
- **Media/Entertainment:** Purple (#8A2BE2)
- **Companion Devices:** Magenta (#C832FF)
- **Energy:** Red (#FF6464)
- **General/Mixed:** Cyan (#64C8FF)

## Responsive Design
- **Grid Layout:** 3-column for sensors, 2-column for controls
- `square: false` - Allow natural aspect ratio
- `gap: 4px` - Minimal spacing between cards
- Minimum padding: 16px on cards for touch targets
- Works seamlessly on phone, tablet, and desktop

## Implemented Room Views

### boys_room.yaml (354 lines)
- Environmental grid: temp/humidity/room-status
- Lighting System: Main light + string lights
- Climate & Entertainment: A/C + media player
- Companion Controls: Joseph's light
- Energy Intelligence: Power monitoring graphs

### kitchen.yaml (365 lines)
- Environmental grid: temp/brightness/motion
- Lighting: Main light + counter LED
- Media & Devices: Kitchen Dot + microwave
- Monitoring: Motion + washing machine status
- Entertainment: Full media player + timer

### bedroom.yaml
- Environmental grid: temp/humidity/brightness
- Lighting: Bedroom main light + media player

### landing.yaml
- Environmental grid: temp/humidity/brightness
- Lighting: Hall light + makeup light

### living_room.yaml
- Environmental grid: temp/humidity/air quality
- Media & Entertainment: Living room TV
- Lighting: Main light + valance

### diningroom.yaml
- Environmental grid: temp/humidity/status
- Lighting System: Main dining light
- Room Settings: Configuration placeholder

## Navigation Structure
- **Path Pattern:** `/cinematic-dashboard/[path-name]`
- Each room view has `type: sidebar` with unique `path`
- No `/lovelace` prefix in tap_actions (already implied by dashboard path)

## Key Implementation Notes

1. **Card Mod Syntax:** All styling uses card_mod with inline style blocks
2. **Template Language:** Uses Home Assistant template syntax for dynamic values
3. **State Display:** Custom button-card state_display for formatted output
4. **Icons:** Mix of mdi icons and emoji for visual distinction
5. **Gradient Overlays:** Always layer color gradients before base gradients
6. **Box Shadow:** Dual shadow technique (colored glow + dark shadow) for depth

## Future Expansion
- Can be applied to specialized views (lights.yaml, security.yaml, weather.yaml, etc.)
- Environmental grid pattern scalable to any room with temp/humidity sensors
- Section title cards flexible for any control category
- Color palette extensible with additional gradients

---

**Created:** January 30, 2026
**Design Status:** Active - Implemented across all primary room views
**Last Updated:** After living_room.yaml, diningroom.yaml, and landing.yaml fixes

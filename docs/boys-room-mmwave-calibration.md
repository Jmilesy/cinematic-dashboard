# Boys Room mmWave Bunk-Bed Calibration

Experimental notes from labelled Home Assistant samples. These are diagnostic only and should not drive alerts until the zones have been checked against longer overnight history.

## Entities

- LD2450 target count: `sensor.mmwave_test_bed_ld2450_target_count`
- LD2450 presence: `binary_sensor.mmwave_test_bed_ld2450_presence`
- LD2450 targets: `sensor.mmwave_test_bed_ld2450_t1_x`, `t1_y`, `t1_speed`, and the same for T2/T3
- LD2410C presence: `binary_sensor.mmwave_test_bed_ld2410c_presence`
- LD2410C movement: `binary_sensor.mmwave_test_bed_ld2410c_moving`
- LD2410C stillness: `binary_sensor.mmwave_test_bed_ld2410c_still`
- LD2410C energy: `sensor.mmwave_test_bed_ld2410c_moving_energy`, `sensor.mmwave_test_bed_ld2410c_still_energy`

## Labelled Samples

| Time | Label | LD2450 count | T1 x | T1 y | T1 speed | LD2410C movement | Notes |
| --- | --- | ---: | ---: | ---: | ---: | --- | --- |
| 2026-05-20 16:30 | Joseph bottom | 1 | -1046 | 3233 | 0 | off / off / off | Bottom bunk sits deep on Y with negative X. |
| 2026-05-20 16:31 | Jacob top, bottom empty | 1 | 458 | 2578 | 160 | on / moving / not still | Top-only sample was positive-ish X and shallower Y. |
| 2026-05-20 16:32 | Both separate | 1 | -1163 | 2707 | 0 | on / not moving / still | LD2450 collapsed both children into one target. |
| 2026-05-20 16:33 | Both in top bunk | 1 | -903 | 2607 | 80 | on / not moving / still | Similar to both-separate, but a bit shallower and less negative. |
| 2026-05-20 16:36 | Jacob in bed, Joseph messing | 1 | -1512 | 3009 | -320 | on / moving / still | Movement energy was high; use movement over time for this state. |
| 2026-05-20 16:37 | Room empty | stale 1 | unknown | unknown | unknown | stale presence, zero energy | Empty is best detected from LD2450 presence off and target positions unknown. |

## Current Working Interpretation

- Do not trust `target_count` by itself. It can lag, and it often reports one target for two children.
- Empty room: LD2450 presence off, target positions unknown, LD2410C energy zero.
- Jacob top likely: positive-ish X, around `x 0..900`, `y 2300..2900`.
- Joseph bottom likely: negative X and deeper Y, roughly `x -1300..-700`, `y 3000+`.
- Both separate possible: one blended target around negative X and mid/deep Y, roughly `x -1400..-800`, `y 2550..2950`, with LD2410C still on.
- Both top possible: one blended target around `x -1100..-700`, `y 2450..2750`, with LD2410C still on and high still energy.
- Active/messing: nonzero LD2450 speed, LD2410C moving on, or moving energy above zero.

## Next Checks

- Capture settled samples after 5-10 minutes, especially both in top bunk and both separate.
- Review full overnight data before using this for alerts.
- Prefer a diagnostic dashboard/template sensor first; promote to notifications only after the false-positive behaviour is understood.

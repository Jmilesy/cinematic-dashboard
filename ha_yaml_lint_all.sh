#!/bin/bash
# ha_yaml_lint_all.sh

OUT="$HOME/ha_yaml_files.txt"
> "$OUT"  # clear previous output

# find all yaml files in the HA config folder
find /usr/share/hassio/homeassistant -type f -name "*.yaml" > "$OUT"

# loop through each YAML file and lint it
while IFS= read -r file; do
    echo "🔍 Checking $file..."
    yamllint "$file"
done < "$OUT"
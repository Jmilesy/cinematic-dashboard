#!/bin/bash
POLICY="$1"
PASSWORD="Chime768"
HOST="192.168.1.76:3000"
case "$POLICY" in
  boys)       DATA='{"name":"Kids-VLAN","data":{"name":"Kids-VLAN","ids":["10.0.30.0/24"],"use_global_settings":false,"filtering_enabled":true,"parental_enabled":true,"safebrowsing_enabled":true,"safesearch_enabled":true,"use_global_blocked_services":false,"blocked_services":["youtube"],"blocked_services_schedule":{"time_zone":"UTC"},"ignore_querylog":false,"ignore_statistics":false}}' ;;
  default)    DATA='{"name":"Kids-VLAN","data":{"name":"Kids-VLAN","ids":["10.0.30.0/24"],"use_global_settings":true,"filtering_enabled":true,"parental_enabled":false,"safebrowsing_enabled":true,"safesearch_enabled":false,"use_global_blocked_services":true,"blocked_services":[],"blocked_services_schedule":{"time_zone":"UTC"},"ignore_querylog":false,"ignore_statistics":false}}' ;;
  unfiltered) DATA='{"name":"Kids-VLAN","data":{"name":"Kids-VLAN","ids":["10.0.30.0/24"],"use_global_settings":true,"filtering_enabled":true,"parental_enabled":false,"safebrowsing_enabled":false,"safesearch_enabled":false,"use_global_blocked_services":true,"blocked_services":[],"blocked_services_schedule":{"time_zone":"UTC"},"ignore_querylog":false,"ignore_statistics":false}}' ;;
  *) echo "Unknown policy: $POLICY" && exit 1 ;;
esac
HTTP=$(curl -s -o /tmp/adguard_resp.txt -w "%{http_code}" -u "jon:$PASSWORD" -X POST "http://$HOST/control/clients/update" -H 'Content-Type: application/json' -d "$DATA")
echo "Set $POLICY http=$HTTP body=$(cat /tmp/adguard_resp.txt)"

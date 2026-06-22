#!/bin/bash
POLICY="$1"
PASSWORD="Chime768"
HOST="192.168.1.76:3000"

case "$POLICY" in
  kids)
    KIDS_DATA='{"name":"Kids-VLAN","data":{"name":"Kids-VLAN","ids":["10.0.30.0/24"],"use_global_settings":false,"filtering_enabled":true,"parental_enabled":true,"safebrowsing_enabled":true,"safesearch_enabled":true,"use_global_blocked_services":true,"blocked_services":[],"blocked_services_schedule":{"time_zone":"UTC"},"ignore_querylog":false,"ignore_statistics":false}}'
    GAMES_DATA='{"name":"GamesPC","data":{"name":"GamesPC","ids":["192.168.1.108"],"use_global_settings":false,"filtering_enabled":true,"parental_enabled":true,"safebrowsing_enabled":true,"safesearch_enabled":true,"use_global_blocked_services":true,"blocked_services":[],"blocked_services_schedule":{"time_zone":"UTC"},"ignore_querylog":false,"ignore_statistics":false}}'
    ;;
  boys)
    KIDS_DATA='{"name":"Kids-VLAN","data":{"name":"Kids-VLAN","ids":["10.0.30.0/24"],"use_global_settings":false,"filtering_enabled":true,"parental_enabled":true,"safebrowsing_enabled":true,"safesearch_enabled":true,"use_global_blocked_services":false,"blocked_services":["youtube"],"blocked_services_schedule":{"time_zone":"UTC"},"ignore_querylog":false,"ignore_statistics":false}}'
    GAMES_DATA='{"name":"GamesPC","data":{"name":"GamesPC","ids":["192.168.1.108"],"use_global_settings":false,"filtering_enabled":true,"parental_enabled":true,"safebrowsing_enabled":true,"safesearch_enabled":true,"use_global_blocked_services":false,"blocked_services":["youtube"],"blocked_services_schedule":{"time_zone":"UTC"},"ignore_querylog":false,"ignore_statistics":false}}'
    ;;
  default)
    KIDS_DATA='{"name":"Kids-VLAN","data":{"name":"Kids-VLAN","ids":["10.0.30.0/24"],"use_global_settings":true,"filtering_enabled":true,"parental_enabled":false,"safebrowsing_enabled":true,"safesearch_enabled":false,"use_global_blocked_services":true,"blocked_services":[],"blocked_services_schedule":{"time_zone":"UTC"},"ignore_querylog":false,"ignore_statistics":false}}'
    GAMES_DATA=""
    ;;
  unfiltered)
    KIDS_DATA='{"name":"Kids-VLAN","data":{"name":"Kids-VLAN","ids":["10.0.30.0/24"],"use_global_settings":true,"filtering_enabled":true,"parental_enabled":false,"safebrowsing_enabled":false,"safesearch_enabled":false,"use_global_blocked_services":true,"blocked_services":[],"blocked_services_schedule":{"time_zone":"UTC"},"ignore_querylog":false,"ignore_statistics":false}}'
    GAMES_DATA=""
    ;;
  *) echo "Unknown policy: $POLICY" && exit 1 ;;
esac

HTTP1=$(curl -s -o /tmp/adguard_resp1.txt -w "%{http_code}" -u "jon:$PASSWORD" -X POST "http://$HOST/control/clients/update" -H 'Content-Type: application/json' -d "$KIDS_DATA")
echo "Kids-VLAN $POLICY http=$HTTP1 $(cat /tmp/adguard_resp1.txt)"

if [ -n "$GAMES_DATA" ]; then
  HTTP2=$(curl -s -o /tmp/adguard_resp2.txt -w "%{http_code}" -u "jon:$PASSWORD" -X POST "http://$HOST/control/clients/update" -H 'Content-Type: application/json' -d "$GAMES_DATA")
  echo "GamesPC $POLICY http=$HTTP2 $(cat /tmp/adguard_resp2.txt)"
fi

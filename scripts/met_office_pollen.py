#!/usr/bin/env python3
import json
import re
import sys
import urllib.request


URL = "https://weather.metoffice.gov.uk/warnings-and-advice/seasonal-advice/pollen-forecast"
REGION = "London & South East England"
LEVELS = {
    "l": "low",
    "m": "moderate",
    "h": "high",
    "vh": "very_high",
}


def main():
    req = urllib.request.Request(
        URL,
        headers={"User-Agent": "HomeAssistant Met Office pollen sensor"},
    )
    with urllib.request.urlopen(req, timeout=20) as response:
        page = response.read().decode("utf-8", errors="replace")

    match = re.search(
        r'<div id="se" class="pollen-forecast-card"[^>]*>(.*?)</div>\s*<div id="sw"',
        page,
        flags=re.S,
    )
    if not match:
        raise RuntimeError(f"Region block not found: {REGION}")

    block = match.group(1)
    summary_match = re.search(r'<div class="paragraph-block body-s">\s*<p>(.*?)</p>', block, flags=re.S)
    issued_match = re.search(r'<p class="last-issued body-s">(.*?)</p>', block, flags=re.S)
    forecast = re.findall(r'data-category="(l|m|h|vh)"', block)

    summary = re.sub(r"<[^>]+>", "", summary_match.group(1)).strip() if summary_match else ""
    issued = re.sub(r"<[^>]+>", "", issued_match.group(1)).strip() if issued_match else ""
    today_level = LEVELS.get(forecast[0], "unknown") if forecast else "unknown"

    print(json.dumps({
        "region": REGION,
        "today_level": today_level,
        "summary": summary,
        "forecast_codes": forecast,
        "forecast_levels": [LEVELS.get(item, "unknown") for item in forecast],
        "issued": issued,
        "source": URL,
    }))


if __name__ == "__main__":
    try:
        main()
    except Exception as exc:
        print(json.dumps({"today_level": "unknown", "error": str(exc), "source": URL}))
        sys.exit(1)

from datetime import datetime

import requests
from waste_collection_schedule import Collection  # type: ignore[attr-defined]

TITLE = "Dover District Council"
DESCRIPTION = "Source for Dover District Council."
URL = "https://www.dover.gov.uk"
TEST_CASES = {
    "200002423404": {"uprn": 200002423404},
    "100060905828": {"uprn": "100060905828"},
}


ICON_MAP = {
    "Garden Waste Collection": "mdi:leaf",
    "Food Collection": "mdi:food-apple",
    "Refuse Collection": "mdi:trash-can",
    "Paper/Card Collection": "mdi:package-variant",
    "Recycling Collection": "mdi:recycle",
}


API_URL = "https://portal.waste.dover.gov.uk"
COUNCIL_ID = "39"


class Source:
    def __init__(self, uprn: str | int):
        self._uprn: str | int = uprn

    def fetch(self) -> list[Collection]:
        session = requests.Session()
        headers = {
            "Accept": "application/json, text/plain, */*",
            "Content-Type": "application/json",
            "Origin": API_URL,
            "Referer": f"{API_URL}/recycling-rubbish/property-search/{self._uprn}/your-collection-days",
            "User-Agent": "Mozilla/5.0",
            "x-recaptcha-token": "",
        }

        # The old collections.dover.gov.uk HTML endpoint now redirects to a
        # Next.js portal. The portal's calendar endpoint returns future
        # collection records directly for the UPRN.
        session.get(headers["Referer"], headers=headers, timeout=20)
        response = session.post(
            f"{API_URL}/api/getCalendarData",
            json={"uprn": str(self._uprn), "councilId": COUNCIL_ID},
            headers=headers,
            timeout=30,
        )
        response.raise_for_status()

        entries = []
        for collection_group in response.json().get("data", []):
            for record in collection_group.get("records", []):
                service_name = record.get("service")
                service_date = record.get("actual_scheduled_date")
                if not service_name or not service_date:
                    continue

                entries.append(
                    Collection(
                        date=datetime.fromisoformat(
                            service_date.replace("Z", "+00:00")
                        ).date(),
                        t=service_name,
                        icon=ICON_MAP.get(service_name),
                    )
                )

        return entries

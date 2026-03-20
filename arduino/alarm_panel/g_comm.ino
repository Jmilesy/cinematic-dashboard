// g_comm.ino
// WiFi diagnostics (reconnect is handled non-blocking in main loop)

void printWifiData() {
  IPAddress ip = WiFi.localIP();
  Serial.print("IP: ");
  Serial.println(ip);
  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC: ");
  for (int i = 5; i >= 0; i--) {
    Serial.print(mac[i], HEX);
    if (i > 0) Serial.print(":");
  }
  Serial.println();
}

void printCurrentNet() {
  snprintf(lcdbuffer, 21, "SSID: %s", WiFi.SSID());
  lcdprint(lcdbuffer);
  long rssi = WiFi.RSSI();
  snprintf(lcdbuffer, 21, "Signal: %ld dBm", rssi);
  lcdprint(lcdbuffer);
}

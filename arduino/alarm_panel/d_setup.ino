// d_setup.ino

void setup() {
  wdt_disable();

  // ---- Pin modes ----
  pinMode(redLed,   OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed,  OUTPUT);
  pinMode(buzzer,   OUTPUT);
  pinMode(armed,    OUTPUT);
  pinMode(unarmed,  OUTPUT);
  pinMode(mqttgood, OUTPUT);
  pinMode(mqttbad,  OUTPUT);
  pinMode(strobe,   OUTPUT);
  pinMode(siren,    OUTPUT);
  pinMode(relay,    OUTPUT);
  pinMode(wipeB,    INPUT_PULLUP);
  pinMode(up,       INPUT_PULLUP);
  pinMode(down,     INPUT_PULLUP);
  pinMode(clears,   INPUT_PULLUP);

  // ---- Initial output states ----
  digitalWrite(relay,    HIGH);    // Door locked
  digitalWrite(redLed,   LED_OFF);
  digitalWrite(greenLed, LED_OFF);
  digitalWrite(blueLed,  LED_OFF);
  digitalWrite(buzzer,   HIGH);    // Buzzer off (active low)
  digitalWrite(mqttgood, LOW);     // off - not connected yet
  digitalWrite(mqttbad,  HIGH);    // on  - not connected yet
  digitalWrite(unarmed,  HIGH);
  digitalWrite(armed,    LOW);
  digitalWrite(strobe,   LOW);
  digitalWrite(siren,    LOW);

  Serial.begin(115200);

  // ---- WiFi via ESP8266 on Serial3 ----
  Serial3.begin(115200);
  WiFi.init(&Serial3);

  if (WiFi.checkFirmwareVersion("1.1.0")) {
    WiFi.resetESP();
    delay(500);
  }

  // ---- LCD ----
  Wire.begin();
  lcd.begin(20, 4);
  lcd.clear();
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.setCursor(2, 0);
  lcd.print("**Alarm Panel**");

  if (WiFi.status() == WL_NO_WIFI_MODULE_COMM) {
    lcdprint("WiFi module error");
  }

  // ---- Connect to WiFi ----
  while (status != WL_CONNECTED) {
    tries++;
    if (tries > 3) {
      tries = 1;
      softReset();
    }
    snprintf(lcdbuffer, 21, "WiFi: (%d/3)", tries);
    lcdprint(lcdbuffer);
    status = WiFi.begin(WIFI_SSID, WIFI_PASS);
    delay(10000);
  }
  lcdprint("WiFi connected");
  printCurrentNet();

  // ---- MQTT ----
  client.setServer(MQTT_SERVER, 1883);
  client.setCallback(callback);

  // ---- NTP ----
  timeClient.begin();

  // ---- RFID ----
  SPI.begin();
  mfrc522.PCD_Init();
  ShowReaderDetails();

  // ---- Wipe button held on power-up = wipe EEPROM ----
  if (digitalRead(wipeB) == LOW) {
    digitalWrite(redLed, LED_ON);
    lcdprint("Wipe button held");
    lcdprint("10s to cancel...");
    bool buttonState = monitorWipeButton(10000);
    if (buttonState && digitalRead(wipeB) == LOW) {
      for (uint16_t x = 0; x < EEPROM.length(); x++) {
        if (EEPROM.read(x) != 0) EEPROM.write(x, 0);
      }
      lcdprint("EEPROM wiped");
    } else {
      lcdprint("Wipe cancelled");
    }
    digitalWrite(redLed, LED_OFF);
  }

  // ---- Master card setup ----
  if (EEPROM.read(1) != 143) {
    lcdprint("No master card!");
    lcdprint("Scan to set one");
    do {
      successRead = getID();
      digitalWrite(blueLed, LED_ON);  delay(200);
      digitalWrite(blueLed, LED_OFF); delay(200);
    } while (!successRead);
    for (uint8_t j = 0; j < 4; j++) {
      EEPROM.write(2 + j, readCard[j]);
    }
    EEPROM.write(1, 143);
    lcdprint("Master card set");
  }

  for (uint8_t i = 0; i < 4; i++) {
    masterCard[i] = EEPROM.read(2 + i);
  }

  lcdprint("System ready");
  cycleLeds();
  wdt_enable(WDTO_4S);
}

// f_access_control.ino
// RFID card management and door relay control

void granted(uint16_t setDelay) {
  digitalWrite(blueLed,  LED_OFF);
  digitalWrite(redLed,   LED_OFF);
  digitalWrite(greenLed, LED_ON);
  digitalWrite(buzzer,   LOW);
  digitalWrite(relay,    LOW);    // Unlock door
  delay(setDelay);
  digitalWrite(relay,    HIGH);   // Relock door
  digitalWrite(buzzer,   HIGH);
  delay(1000);
}

void denied() {
  digitalWrite(greenLed, LED_OFF);
  digitalWrite(blueLed,  LED_OFF);
  digitalWrite(redLed,   LED_ON);
  digitalWrite(buzzer,   LOW);
  lcdprint("** ACCESS DENIED **");
  delay(1000);
  digitalWrite(buzzer,   HIGH);
  digitalWrite(redLed,   LED_OFF);
}

uint8_t getID() {
  if (!mfrc522.PICC_IsNewCardPresent()) return 0;
  if (!mfrc522.PICC_ReadCardSerial())   return 0;
  for (uint8_t i = 0; i < 4; i++) {
    readCard[i] = mfrc522.uid.uidByte[i];
  }
  mfrc522.PICC_HaltA();
  return 1;
}

void ShowReaderDetails() {
  byte v = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  if ((v == 0x00) || (v == 0xFF)) {
    lcdprint("RFID reader error!");
    digitalWrite(redLed, LED_ON);
    while (true);
  }
}

void cycleLeds() {
  cyclepreviousMillis = millis();
  switch (cycle) {
    case 0: digitalWrite(redLed, LED_OFF); digitalWrite(greenLed, LED_ON);  digitalWrite(blueLed, LED_OFF); cycle = 1; break;
    case 1: digitalWrite(redLed, LED_OFF); digitalWrite(greenLed, LED_OFF); digitalWrite(blueLed, LED_ON);  cycle = 2; break;
    case 2: digitalWrite(redLed, LED_ON);  digitalWrite(greenLed, LED_OFF); digitalWrite(blueLed, LED_OFF); cycle = 0; break;
  }
}

void normalModeOn() {
  digitalWrite(blueLed,  LED_ON);
  digitalWrite(redLed,   LED_OFF);
  digitalWrite(greenLed, LED_OFF);
  digitalWrite(relay,    HIGH);   // Ensure door stays locked
}

void readID(uint8_t number) {
  uint8_t start = (number * 4) + 2;
  for (uint8_t i = 0; i < 4; i++) {
    storedCard[i] = EEPROM.read(start + i);
  }
}

void writeID(byte a[]) {
  if (!findID(a)) {
    uint8_t num   = EEPROM.read(0);
    uint8_t start = (num * 4) + 6;
    num++;
    EEPROM.write(0, num);
    for (uint8_t j = 0; j < 4; j++) {
      EEPROM.write(start + j, a[j]);
    }
    successWrite();
    lcdprint("Card added");
  } else {
    failedWrite();
    lcdprint("Card add failed");
  }
}

void deleteID(byte a[]) {
  if (!findID(a)) {
    failedWrite();
    lcdprint("Card not found");
  } else {
    uint8_t num     = EEPROM.read(0);
    uint8_t slot    = findIDSLOT(a);
    uint8_t start   = (slot * 4) + 2;
    uint8_t looping = (num - slot) * 4;
    num--;
    EEPROM.write(0, num);
    for (uint8_t j = 0; j < looping; j++) {
      EEPROM.write(start + j, EEPROM.read(start + 4 + j));
    }
    for (uint8_t k = 0; k < 4; k++) {
      EEPROM.write(start + looping + k, 0);
    }
    successDelete();
    lcdprint("Card removed");
  }
}

bool checkTwo(byte a[], byte b[]) {
  for (uint8_t k = 0; k < 4; k++) {
    if (a[k] != b[k]) return false;
  }
  return true;
}

uint8_t findIDSLOT(byte find[]) {
  uint8_t count = EEPROM.read(0);
  for (uint8_t i = 1; i <= count; i++) {
    readID(i);
    if (checkTwo(find, storedCard)) return i;
  }
  return 0;
}

bool findID(byte find[]) {
  uint8_t count = EEPROM.read(0);
  for (uint8_t i = 1; i <= count; i++) {
    readID(i);
    if (checkTwo(find, storedCard)) return true;
  }
  return false;
}

void successWrite() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(greenLed, LED_ON);  delay(200);
    digitalWrite(greenLed, LED_OFF); delay(200);
  }
}

void failedWrite() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(redLed, LED_ON);  delay(200);
    digitalWrite(redLed, LED_OFF); delay(200);
  }
}

void successDelete() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(blueLed, LED_ON);  delay(200);
    digitalWrite(blueLed, LED_OFF); delay(200);
  }
}

bool isMaster(byte test[]) {
  return checkTwo(test, masterCard);
}

bool monitorWipeButton(uint32_t interval) {
  uint32_t start = (uint32_t)millis();
  while ((uint32_t)millis() - start < interval) {
    wdt_reset();
    if (((uint32_t)millis() % 500) == 0) {
      if (digitalRead(wipeB) != LOW) return false;
    }
  }
  return true;
}

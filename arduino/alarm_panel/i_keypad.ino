// i_keypad.ino
// 4x4 keypad PIN entry - publishes to alarm/pin for HA to validate

void keypadd(char key) {
  // * = cancel/clear
  if (key == '*') {
    data_count = 0;
    memset(Data, 0, sizeof(Data));
    lastact();
    return;
  }

  // Store digit and show * on LCD
  Data[data_count] = key;
  lcd.setCursor(data_count, 1);
  lcd.print("*");
  data_count++;

  // Submit on 4 digits or 'A' (enter)
  if (data_count == 4 || key == 'A') {
    data_count = 0;
    delay(400);
    lastact();
    client.publish("alarm/pin", Data);  // HA validates the PIN
    memset(Data, 0, sizeof(Data));
  }

  lastaction = millis();
}

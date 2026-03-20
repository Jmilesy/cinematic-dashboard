// k_led_patterns.ino
// LED flash patterns for feedback

// Cycles armed/unarmed LEDs when armed_home mode is active
void cycleLedsSetting() {
  cyclepreviousMillis = millis();
  if (cycle == 0) {
    digitalWrite(armed,   LOW);
    digitalWrite(unarmed, HIGH);
    cycle = 1;
  } else {
    digitalWrite(armed,   HIGH);
    digitalWrite(unarmed, LOW);
    cycle = 0;
  }
}

// Wrong PIN feedback - red flash + buzzer
void wrong() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(redLed,   LED_ON);
    digitalWrite(greenLed, LED_OFF);
    digitalWrite(blueLed,  LED_OFF);
    digitalWrite(buzzer,   LOW);
    delay(100);
    digitalWrite(redLed,   LED_OFF);
    digitalWrite(blueLed,  LED_ON);
    digitalWrite(buzzer,   HIGH);
    delay(100);
  }
  digitalWrite(blueLed, LED_OFF);
}

// Right PIN feedback - green flash + buzzer
void right() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(greenLed, LED_ON);
    digitalWrite(redLed,   LED_OFF);
    digitalWrite(blueLed,  LED_OFF);
    digitalWrite(buzzer,   LOW);
    delay(100);
    digitalWrite(greenLed, LED_OFF);
    digitalWrite(blueLed,  LED_ON);
    digitalWrite(buzzer,   HIGH);
    delay(100);
  }
  digitalWrite(blueLed, LED_OFF);
}

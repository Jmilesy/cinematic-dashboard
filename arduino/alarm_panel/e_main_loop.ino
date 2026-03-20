// e_main_loop.ino

void loop() {
  wdt_reset();

  // ---- Backlight timeout ----
  if (millis() - lastaction >= (unsigned long)timeoutdisplay) {
    lastact();
    lcd.setBacklight(LOW);
  }

  // ---- Heartbeat watchdog ----
  hbeat++;
  if (hbeat > 3600) {
    digitalWrite(mqttgood, LOW);
    digitalWrite(mqttbad,  HIGH);
  }

  // ---- Armed home LED cycling ----
  if (armed_home == 1) {
    if (millis() - cyclepreviousMillis >= (unsigned long)cycleinterval) {
      cycleLedsSetting();
    }
  }

  // ---- MQTT - non-blocking reconnect ----
  if (!client.connected()) {
    unsigned long now = millis();
    if (now - lastReconnectAttempt > 5000) {
      lastReconnectAttempt = now;
      if (client.connect("AlarmPanel")) {
        client.publish("alarm/status", "connected");
        client.subscribe("alarm/#");
        lastReconnectAttempt = 0;
        digitalWrite(mqttgood, HIGH);
        digitalWrite(mqttbad,  LOW);
        lcdprint("MQTT connected");
      } else {
        digitalWrite(mqttgood, LOW);
        digitalWrite(mqttbad,  HIGH);
      }
    }
  } else {
    client.loop();
  }

  // ---- RFID ----
  successRead = getID();

  // ---- Wipe button held during operation ----
  if (digitalRead(wipeB) == LOW) {
    digitalWrite(redLed,   LED_ON);
    digitalWrite(greenLed, LED_OFF);
    digitalWrite(blueLed,  LED_OFF);
    lcdprint("Hold 10s to wipe");
    bool buttonState = monitorWipeButton(10000);
    if (buttonState && digitalRead(wipeB) == LOW) {
      EEPROM.write(1, 0);
      lcdprint("Master erased");
      lcdprint("Restart to re-set");
      while (1);
    }
    lcdprint("Wipe cancelled");
    digitalWrite(redLed, LED_OFF);
  }

  // ---- Program mode LED cycling ----
  if (programMode) {
    if (millis() - cyclepreviousMillis >= (unsigned long)cycleinterval) {
      cycleLeds();
    }
  } else {
    normalModeOn();
  }

  // ---- Keypad ----
  char myKey = myKeypad.getKey();
  if (myKey != NULL) {
    lcd.setBacklight(HIGH);
    keypadd(myKey);
    lastaction = millis();
  }

  // ---- Clear button ----
  if (digitalRead(clears) == LOW) {
    if ((millis() - lastDebounceTime) > debounceDelay) {
      lastDebounceTime = millis();
      lcd.setBacklight(HIGH);
      lastline = 0;
      lastact();
    }
  }

  // ---- Scroll up ----
  if (digitalRead(up) == LOW) {
    if ((millis() - lastDebounceTime) > debounceDelay) {
      lastDebounceTime = millis();
      lcd.setBacklight(HIGH);
      scroll(1);
    }
  }

  // ---- Scroll down ----
  if (digitalRead(down) == LOW) {
    if ((millis() - lastDebounceTime) > debounceDelay) {
      lastDebounceTime = millis();
      lcd.setBacklight(HIGH);
      scroll(-1);
    }
  }

  // ---- Process RFID card ----
  if (successRead) {
    read_card(successRead);
  }
}

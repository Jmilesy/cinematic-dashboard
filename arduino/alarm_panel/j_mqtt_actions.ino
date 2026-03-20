// j_mqtt_actions.ino
// All actions triggered by incoming MQTT messages from HA

void actions(char* topic, char* payload) {
  if      (strcmp_P(topic, PSTR("alarm/info"))       == 0) message(payload);
  else if (strcmp_P(topic, PSTR("alarm/sound"))      == 0) soundalarm(payload);
  else if (strcmp_P(topic, PSTR("alarm/buzzer"))     == 0) soundbuzzer(payload);
  else if (strcmp_P(topic, PSTR("alarm/state"))      == 0) alarmstate(payload);
  else if (strcmp_P(topic, PSTR("alarm/hbeat"))      == 0) heartbeat(payload);
  else if (strcmp_P(topic, PSTR("alarm/pinin"))      == 0) pinfeedback(payload);
  else if (strcmp_P(topic, PSTR("alarm/poverride"))  == 0) poverride(payload);
  else if (strcmp_P(topic, PSTR("alarm/strobe"))     == 0) strobes(payload);
  else if (strcmp_P(topic, PSTR("alarm/screen"))     == 0) screen(payload);
  else if (strcmp_P(topic, PSTR("alarm/armed_home")) == 0) armed_homefunc(payload);
}

// Siren + strobe: "on" / "off"
void soundalarm(String p) {
  bool on = (p == "on");
  digitalWrite(strobe, on ? HIGH : LOW);
  digitalWrite(siren,  on ? HIGH : LOW);
}

// Buzzer + strobe: "on" / "off"
void soundbuzzer(String p) {
  bool on = (p == "on");
  digitalWrite(buzzer, on ? LOW  : HIGH);  // Active low
  digitalWrite(strobe, on ? HIGH : LOW);
}

// Alarm state from HA alarm_control_panel
// Payloads: disarmed / armed_home / armed_away / triggered / pending
void alarmstate(String p) {
  if (p == "armed_away" || p == "armed_home") {
    digitalWrite(unarmed, LOW);
    digitalWrite(armed,   HIGH);
    lcdprint("System ARMED");
  } else if (p == "disarmed") {
    digitalWrite(unarmed, HIGH);
    digitalWrite(armed,   LOW);
    lcdprint("System disarmed");
  } else if (p == "triggered") {
    lcdprint("** ALARM TRIGGERED **");
  } else if (p == "pending") {
    lcdprint("Entry delay...");
  } else if (p == "arming") {
    lcdprint("Arming - exit now");
  }
}

// PIN feedback from HA: "right" / "wrong"
void pinfeedback(String p) {
  if      (p == "wrong") wrong();
  else if (p == "right") right();
}

// Parent override - flash panel LEDs and notify HA to turn on boys white light
void poverride(String p) {
  for (uint8_t i = 0; i < 4; i++) {
    digitalWrite(greenLed, LED_ON);
    digitalWrite(buzzer,   LOW);
    delay(100);
    digitalWrite(greenLed, LED_OFF);
    digitalWrite(buzzer,   HIGH);
    delay(100);
  }
  client.publish("alarm/poverride_ack", "on");  // HA handles the light
  parentscreen(p.c_str());
}

// Strobe only: "on" / "off"
void strobes(String p) {
  digitalWrite(strobe, (p == "on") ? HIGH : LOW);
}

// LCD backlight: "on" / "off"
void screen(String p) {
  if (p == "on") {
    lcd.setBacklight(HIGH);
    lastaction = millis();
  } else {
    lcd.setBacklight(LOW);
  }
}

// Armed home mode (cycles armed/unarmed LEDs when home is armed)
void armed_homefunc(String p) {
  armed_home = (p == "ARM_HOME") ? 1 : 0;
}

// Heartbeat from HA - proves connection is alive
void heartbeat(char* p) {
  client.publish("alarm/hbeatret", "here");
  wdt_reset();
  digitalWrite(mqttgood, LOW);
  delay(100);
  digitalWrite(mqttgood, HIGH);
  hbeat = 0;
}

// Parent screen display
void parentscreen(const char* msg) {
  wdt_reset();
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("**Parent Panel**");
  lcd.setCursor(1, 2);
  lcd.print(msg);
  lastaction = millis();
}

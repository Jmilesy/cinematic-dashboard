// h_lcd.ino
// LCD display functions with UK GMT/BST time support

// Returns UTC epoch adjusted for UK time (GMT or BST)
time_t ukTime() {
  timeClient.update();
  time_t utc = timeClient.getEpochTime();
  int m = month(utc);

  if (m > 3 && m < 10) return utc + 3600;  // Summer - always BST
  if (m < 3 || m > 10) return utc;          // Winter - always GMT

  // March or October - check if we've passed the last Sunday at 1am UTC
  int d   = day(utc);
  int h   = hour(utc);
  int dow = weekday(utc);  // TimeLib: 1=Sun, 2=Mon ... 7=Sat

  // Calculate weekday of last day of month (both March and October have 31 days)
  int dowLastDay  = ((dow - 1) + (31 - d)) % 7;  // 0=Sun, 1=Mon ...
  int lastSunday  = 31 - dowLastDay;

  if (m == 3) {
    // BST starts last Sunday March at 1am UTC
    if (d > lastSunday || (d == lastSunday && h >= 1)) return utc + 3600;
    return utc;
  } else {
    // BST ends last Sunday October at 1am UTC
    if (d < lastSunday || (d == lastSunday && h < 1)) return utc + 3600;
    return utc;
  }
}

// Print a message to the LCD and store it in the scrollable log
void lcdprint(String text) {
  // Shift log buffer down
  for (int i = 49; i > 0; i--) {
    line[i]     = line[i - 1];
    linetime[i] = linetime[i - 1];
  }
  line[0]     = text;
  linetime[0] = timeClient.getEpochTime();

  time_t t = ukTime();
  snprintf(lcdtime, 31, "%02d/%02d/%4d %02d:%02d:%02d",
           day(t), month(t), year(t), hour(t), minute(t), second(t));

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("**Alarm Panel**");
  lcd.setCursor(0, 1);
  lcd.print("--------------------");
  lcd.setCursor(0, 2);
  lcd.print(lcdtime);
  lcd.setCursor(0, 3);
  lcd.print(text);
  lastaction = millis();
}

// Default idle screen - shows current time and date
void lastact() {
  wdt_reset();
  time_t t = ukTime();

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("**Alarm Panel**");
  lcd.setCursor(0, 1);
  lcd.print("--------------------");

  snprintf(lcdtime, 31, "Time: %02d:%02d", hour(t), minute(t));
  lcd.setCursor(0, 2);
  lcd.print(lcdtime);

  snprintf(lcdtime, 31, "Date: %02d/%02d/%4d", day(t), month(t), year(t));
  lcd.setCursor(0, 3);
  lcd.print(lcdtime);

  lastaction = millis();
}

// Scroll through the log buffer
// dir: 1 = older (up), -1 = newer (down)
void scroll(int dir) {
  lastaction = millis();

  if (dir == 1 && lastline < 49) {
    lastline++;
  } else if (dir == -1 && lastline > 0) {
    lastline--;
  }

  if (lastline < 0) lastline = 0;

  time_t utcCalc = linetime[lastline];
  // Show short timestamp for log entries (date + time on one line)
  snprintf(lcdtime, 31, "%02d/%02d %02d:%02d:%02d",
           day(utcCalc), month(utcCalc), hour(utcCalc), minute(utcCalc), second(utcCalc));

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("**Alarm Panel**");
  lcd.setCursor(0, 1);
  lcd.print("--------------------");
  lcd.setCursor(0, 2);
  lcd.print(lcdtime);
  lcd.setCursor(0, 3);
  lcd.print(line[lastline]);
}

void message(char* msg) {
  lcdprint(String(msg));
}

// l_read_card.ino
// RFID card processing - program mode and normal access

void read_card(uint8_t successRead) {
  lcd.setBacklight(HIGH);

  if (programMode) {
    // Program mode - scan master card to exit, or add/remove cards
    if (isMaster(readCard)) {
      lcdprint("Exiting prog mode");
      programMode = false;
      return;
    }
    if (findID(readCard)) {
      deleteID(readCard);
    } else {
      writeID(readCard);
    }
    return;
  }

  // Normal mode
  if (isMaster(readCard)) {
    programMode = true;
    uint8_t count = EEPROM.read(0);
    snprintf(lcdbuffer, 21, "Prog: %d cards", count);
    lcdprint(lcdbuffer);
    lcdprint("Scan to add/remove");
    return;
  }

  // Publish card UID regardless of result (HA can log all attempts)
  char cardid[9];
  snprintf(cardid, 9, "%X%X%X%X", readCard[0], readCard[1], readCard[2], readCard[3]);

  if (findID(readCard)) {
    client.publish("alarm/rfidsucess", cardid);  // Keeping original topic name for HA compatibility
    lcdprint("Access granted");
    granted(300);
  } else {
    client.publish("alarm/rfidfail", cardid);
    lcdprint("Access denied");
    denied();
  }
}

// b_config.ino
// Includes, pin definitions, global objects, credentials

// ==================== LIBRARIES ====================
#include <EEPROM.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <PubSubClient.h>
#include <WiFiLink.h>
#include <TimeLib.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <avr/wdt.h>

#include "secrets.h"  // WIFI_SSID, WIFI_PASS, MQTT_SERVER

// ==================== NETWORK ====================
int status = WL_IDLE_STATUS;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 0);  // UTC - offset applied in display

// ==================== MQTT ====================
WiFiClient espClient;

void callback(char* topic, byte* payload, unsigned int length) {
  payload[length] = '\0';
  actions(topic, (char*)payload);
}

PubSubClient client(MQTT_SERVER, 1883, callback, espClient);

// ==================== LCD (20x4 I2C) ====================
#define I2C_ADDR      0x3F
#define BACKLIGHT_PIN 3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
LiquidCrystal_I2C lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin, BACKLIGHT_PIN, POSITIVE);

// ==================== LEDs (common anode) ====================
#define COMMON_ANODE
#ifdef COMMON_ANODE
  #define LED_ON  LOW
  #define LED_OFF HIGH
#endif

// ==================== PIN DEFINITIONS ====================
#define redLed   24
#define greenLed 23
#define blueLed  22
#define buzzer   46   // Active LOW
#define armed    32
#define unarmed  33
#define mqttgood 34
#define mqttbad  35
#define relay    30
#define wipeB    31
#define up       26
#define down     27
#define clears   28
#define strobe   37
#define siren    36

// ==================== RFID ====================
#define SS_PIN  53
#define RST_PIN  9
MFRC522 mfrc522(SS_PIN, RST_PIN);

bool     programMode = false;
uint8_t  successRead;
byte     storedCard[4];
byte     readCard[4];
byte     masterCard[4];

// ==================== KEYPAD ====================
const byte n_rows = 4;
const byte n_cols = 4;
char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[n_rows] = {45, 44, 43, 42};
byte colPins[n_cols] = {41, 40, 39, 38};
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, n_rows, n_cols);

// ==================== SOFT RESET ====================
void softReset() {
  asm volatile ("  jmp 0");
}

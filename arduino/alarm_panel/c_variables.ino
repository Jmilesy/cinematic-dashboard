// c_variables.ino
// All global variables

// Log buffer - last 50 messages with UTC timestamps
String line[51];
long   linetime[51];

// LCD scratch buffer
char lcdbuffer[31];
char lcdtime[31];

// LED cycle state
int  cycle = 0;
long cyclepreviousMillis = 0;
const long cycleinterval = 200;

// Inactivity backlight timeout (10 seconds)
long timeoutdisplay = 10000;
long lastaction     = 0;

// Button debounce
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay    = 200;

// Log scroll position
int lastline = -1;

// Armed home mode flag
int armed_home = 0;

// Parent override flag
int parentoverride = 0;

// MQTT heartbeat counter (resets on each heartbeat from HA)
int hbeat = 0;

// PIN entry
char Data[6];
byte data_count = 0;

// WiFi connection retries
int tries = 0;

// MQTT non-blocking reconnect timer
unsigned long lastReconnectAttempt = 0;

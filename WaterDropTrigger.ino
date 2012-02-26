#define FOCUS 0
#define SHUTTER 1
#define SENSOR 2
#define SPEAKER 4

#define DROP_DELAY 200
#define INTER_PHOTO_DELAY 1000

#define SERIAL_BAUD 57600
#define SERIAL_READ_TIMEOUT 100
#define SERIAL_MAX_CMD_LEN 128

void playTune() {
  int i = 0;
  for (i = 0; i <= 2; i++) {
    tone(SPEAKER, 1000, 100);
    delay(100);
  }
}

inline void takePhoto() {
  delay(DROP_DELAY);
  digitalWrite(SHUTTER, HIGH);
  delay(50);
  digitalWrite(SHUTTER, LOW);
}

void resetCamera() {
  digitalWrite(FOCUS, LOW);
  digitalWrite(SHUTTER, LOW);
  delay(1000);
  digitalWrite(FOCUS, HIGH);
}

String serialRead() {
  int read_size = 0;
  static char buf[SERIAL_MAX_CMD_LEN + 1];

  if (Serial.available()) {
    read_size = Serial.readBytesUntil('\n', buf, SERIAL_MAX_CMD_LEN);
    buf[read_size] = 0;
    return String(buf);
  } else {
    return String();
  }
}

void serialSync() {
  while (1) {
    String command = serialRead();
    if (command.equals("ArduinoStartup")) {
      Serial.println(command);
      break;
    } else {
      Serial.println("ArduinoSyncRequired\n");
    }
  }
}

void setup() {
  pinMode(SENSOR, INPUT);
  pinMode(FOCUS, OUTPUT);
  pinMode(SHUTTER, OUTPUT);
  pinMode(SPEAKER, OUTPUT);

  Serial.begin(SERIAL_BAUD);
  Serial.setTimeout(SERIAL_READ_TIMEOUT);
  serialSync();

  digitalWrite(FOCUS, HIGH);
}

void loop() {
  if (! digitalRead(SENSOR)) {
    takePhoto();
    playTune();
    resetCamera();
  }

  String command = serialRead();
  if (command.length()) {
    Serial.print("Received: ");
    Serial.println(command);
  }
}


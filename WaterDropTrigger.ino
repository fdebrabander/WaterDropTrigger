#define FOCUS 0
#define SHUTTER 1
#define SENSOR 2
#define SENSOR_INT 0 // Digital PIN 2 == Interrupt line 0
#define SPEAKER 4

#define DROP_DELAY 200
#define INTER_PHOTO_DELAY 1000


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

inline void resetCamera() {
  digitalWrite(FOCUS, LOW);
  digitalWrite(SHUTTER, LOW);
  delay(1000);
  digitalWrite(FOCUS, HIGH);
}

void sensorTriggered() {
    takePhoto();
    playTune();
    resetCamera();
}

void setup() {
  pinMode(SENSOR, INPUT);
  pinMode(FOCUS, OUTPUT);
  pinMode(SHUTTER, OUTPUT);
  pinMode(SPEAKER, OUTPUT);

  digitalWrite(FOCUS, HIGH);
  attachInterrupt(SENSOR_INT, sensorTriggered, FALLING);
}

void loop() {
  // TODO: serial communication
}


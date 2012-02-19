#define SENSOR 0
#define FOCUS 1
#define SHUTTER 2
#define SPEAKER 3

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

void setup() {
  pinMode(SENSOR, INPUT);
  pinMode(FOCUS, OUTPUT);
  pinMode(SHUTTER, OUTPUT);
  pinMode(SPEAKER, OUTPUT);

  digitalWrite(FOCUS, HIGH);
}

void loop() {
  if (! digitalRead(SENSOR)) {
    takePhoto();
    playTune();
    resetCamera();
  }
}


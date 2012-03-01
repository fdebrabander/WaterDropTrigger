#include "Camera.h"

#define FOCUS_PIN 8
#define SHUTTER_PIN 9
#define SENSOR_PIN 10
#define SPEAKER_PIN 11

#define DROP_DELAY 200

Camera D90(FOCUS_PIN, SHUTTER_PIN);

void playTune() {
  int i = 0;
  for (i = 0; i <= 2; i++) {
    tone(SPEAKER_PIN, 1000, 100);
    delay(100);
  }
}

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
  if (! digitalRead(SENSOR_PIN)) {
    D90.takePhoto();
    playTune();
    D90.resetCamera();
  }
}


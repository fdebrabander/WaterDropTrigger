#include "Camera.h"
#include <Arduino.h>

Camera::Camera(uint8_t focusPin, uint8_t shutterPin)
 : _focusPin(focusPin), _shutterPin(shutterPin), _shutterDelay(0)
{
  pinMode(_focusPin, OUTPUT);
  pinMode(_shutterPin, OUTPUT);
  digitalWrite(_focusPin, HIGH);
}

void Camera::takePhoto() {
  delay(_shutterDelay);
  digitalWrite(_shutterPin, HIGH);
  delay(50);
  digitalWrite(_shutterPin, LOW);  
}

void Camera::resetCamera() {
  digitalWrite(_focusPin, LOW);
  digitalWrite(_shutterPin, LOW);
  delay(1000);
  digitalWrite(_focusPin, HIGH);  
}

void Camera::setShutterDelay(uint32_t shutterDelay) {
  _shutterDelay = shutterDelay;
}

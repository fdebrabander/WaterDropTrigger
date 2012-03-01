#ifndef INCLUDED_CAMERA_H
#define INCLUDED_CAMERA_H

#include <inttypes.h>

class Camera {
public:
  Camera(uint8_t focusPin, uint8_t shutterPin);

  void takePhoto();
  void resetCamera();
  void setShutterDelay(uint32_t shutterDelay);

private:
  uint8_t _focusPin;
  uint8_t _shutterPin;
  uint32_t _shutterDelay;
};

#endif

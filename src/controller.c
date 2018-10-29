#include "controller.h"
#include "API.h"
#include "drive.h"

int joystickGetAnalogA(unsigned char joystick, unsigned char channel) {
  return joystickGetAnalog(joystick, channel)? abs(joystickGetAnalog(joystick, channel)) > THRESHOLD: 0;
}

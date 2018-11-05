#include "controller.h"
#include "API.h"
#include "drive.h"

int joystickGetAnalogA(unsigned char joystick, unsigned char channel) {
  return abs(joystickGetAnalog(joystick, channel)) > THRESHOLD? joystickGetAnalog(joystick, channel): 0;
}

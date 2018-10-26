#include "drive.h"
#include <API.h>

void motorSpeedStick(unsigned char channel, int speed) {
  motorSet(channel, abs(speed) > THRESHOLD? speed: 0);
}

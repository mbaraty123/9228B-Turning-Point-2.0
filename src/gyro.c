#include "gyro.h"
#include "drive.h"

static Gyro main_gyro;

bool init_main_gyro() {
  main_gyro = gyroInit(GYRO_PORT, GYRO_MULTIPLIER);
  return main_gyro != NULL;
}

int getGyro() {
  return gyroGet(main_gyro);
}

void gyroTurn(int degrees, int minSpeed)
{
  int direction;
  //postive direction means turning right (positive degrees)
  if (degrees > 0)
  {
    direction = -1;
  }
  else
  {
    direction = 1;
  }
  degrees -= degrees / 10;
  int initial = getGyro();
  int slowDown = 0;
  //turn while the difference is less than the target degrees
  while (abs(initial - getGyro()) <= abs(degrees))
  {
    //if less than 38 degs to target, slow down
    int degsRemaining = abs(degrees) - abs(initial - getGyro());
    if (degsRemaining <= 38)
    {
      //slow down by a fraction of degrees remaining;
      slowDown += degsRemaining / 3;
    }
    motorSetLeft(max(-80, GYRO_TURN_SPEED - slowDown) * direction);
    motorSetRight(max(-80, GYRO_TURN_SPEED - slowDown) * direction);
    wait(20);
  }
  robotStop();
}

int max(int a, int b)
{
  if (a > b) {return a;}
  return b;
}

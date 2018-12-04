#include "drive.h"
#include "main.h"

 static bool firingSpeed = false;
 static bool firingMode = false;

void robotStop() {
  motorSet(MOTOR_BACK_LEFT, 0);
  motorSet(MOTOR_BACK_RIGHT, 0);
  motorSet(MOTOR_FRONT_RIGHT, 0);
  motorSet(MOTOR_FRONT_LEFT, 0);
}

void flywheelSet(int speed) {
  motorSet(MOTOR_FLYWHEEL_A, -speed);
  motorSet(MOTOR_FLYWHEEL_B, -speed);
}

void flywheelStop() {
  flywheelSet(0);
}

void intakeSet(Direction dir) {
  if(dir == forward) {
    motorSet(MOTOR_INTAKE, MIN_SPEED);
    motorSet(MOTOR_BELT, MAX_SPEED);
  } else if (dir == reverse) {
    motorSet(MOTOR_INTAKE, MAX_SPEED);
    motorSet(MOTOR_BELT, MIN_SPEED);
  } else {
    motorSet(MOTOR_INTAKE, 0);
    motorSet(MOTOR_BELT, 0);
  }
}

void intakeStop() {
  motorSet(MOTOR_INTAKE, 0);
  motorSet(MOTOR_BELT, 0);
}

void drive() {


  int stickLX = joystickGetAnalogA(JOYSTICK_MAIN, JOYSTICK_LEFT_X);
  int stickLY = joystickGetAnalogA(JOYSTICK_MAIN, JOYSTICK_LEFT_Y);
  int stickRX = joystickGetAnalogA(JOYSTICK_MAIN, JOYSTICK_RIGHT_X);

  motorSet(MOTOR_FRONT_RIGHT, -(stickLY - stickRX - stickLX) * .99);
  motorSet(MOTOR_BACK_RIGHT, -(stickLY - stickRX + stickLX) * .99);
  motorSet(MOTOR_FRONT_LEFT, -(stickLY + stickRX + stickLX) * .99);
  motorSet(MOTOR_BACK_LEFT, (stickLY + stickRX - stickLX) * .99);

  if(joystickGetDigital(JOYSTICK_MAIN, 6, JOY_UP)) {
    intakeSet(forward);
  } else if(joystickGetDigital(JOYSTICK_MAIN, 6, JOY_DOWN)) {
    intakeSet(reverse);
  } else {
    intakeStop();
  }

  if(joystickGetDigital(JOYSTICK_MAIN, 5, JOY_UP)) {
    firingMode = true;
  }
  if(joystickGetDigital(JOYSTICK_MAIN, 5, JOY_DOWN)) {
    firingMode = false;
  }

  if(firingMode && joystickGetDigital(JOYSTICK_MAIN, 7, JOY_LEFT)) {
    firingSpeed = true;
  } else if(firingMode && joystickGetDigital(JOYSTICK_MAIN, 7, JOY_DOWN)) {
    firingSpeed = false;
  }

  if(firingMode && firingSpeed) {
    flywheelSet(110);
  } else if(firingMode && !firingSpeed) {
    flywheelSet(60);
  } else {
    flywheelSet(motorGet(MOTOR_FLYWHEEL_A) / 3 >= 1? motorGet(MOTOR_FLYWHEEL_A) / 3: 0);
  }

  if(joystickGetDigital(JOYSTICK_MAIN, 8, JOY_UP)) {
    motorSet(MOTOR_FLIPPER, MIN_SPEED);
  }  else if(joystickGetDigital(JOYSTICK_MAIN, 8, JOY_LEFT)) {
  motorSet(MOTOR_FLIPPER, MAX_SPEED);
  } else {
    motorSet(MOTOR_FLIPPER, 0);
  }

  if(joystickGetDigital(JOYSTICK_MAIN, 8, JOY_DOWN)){
    autonomous();
  }

}

void robotSpin(Direction dir, int speed) {
  if(dir == clockwise) {
    motorSet(MOTOR_FRONT_RIGHT, -speed);
    motorSet(MOTOR_FRONT_LEFT, speed);
    motorSet(MOTOR_BACK_RIGHT, -speed);
    motorSet(MOTOR_FRONT_LEFT, speed);
  } else if(dir == counterclockwise) {
    motorSet(MOTOR_FRONT_RIGHT, speed);
    motorSet(MOTOR_FRONT_LEFT, -speed);
    motorSet(MOTOR_BACK_RIGHT, speed);
    motorSet(MOTOR_FRONT_LEFT, -speed);
  } else {
    robotStop();
  }
}

void robotStraighten() {
//  gyroTurn(0);
}

void robotDriveForward() {
  motorSet(MOTOR_BACK_LEFT, MAX_SPEED / 2);
  motorSet(MOTOR_BACK_RIGHT, MIN_SPEED / 2);
  motorSet(MOTOR_FRONT_RIGHT, MIN_SPEED / 2);
  motorSet(MOTOR_FRONT_LEFT, MIN_SPEED / 2);
}

void robotDriveReverse() {
  motorSet(MOTOR_BACK_LEFT, MIN_SPEED / 2);
  motorSet(MOTOR_BACK_RIGHT, MAX_SPEED / 2);
  motorSet(MOTOR_FRONT_RIGHT, MAX_SPEED / 2);
  motorSet(MOTOR_FRONT_LEFT, MAX_SPEED / 2);
}

void robotDriveStraight(Direction dir) {
  if(dir == forward) {
    robotDriveForward();
  } else if(dir == reverse) {
    robotDriveReverse();
  } else {
    robotStop();
  }
}

void flipperMove(FlipperDirection dir) {
  if(dir == up) {
    motorSet(MOTOR_FLIPPER, MIN_SPEED);
  } else {
    motorSet(MOTOR_FLIPPER, MAX_SPEED);
  }
}

void flipperStop() {
  motorSet(MOTOR_FLIPPER, 0);
}

void motorSetLeft(int speed) {
  motorSet(MOTOR_FRONT_LEFT, speed);
  motorSet(MOTOR_BACK_LEFT, -speed);
}

void motorSetRight(int speed) {
  motorSet(MOTOR_FRONT_RIGHT, -speed);
  motorSet(MOTOR_BACK_RIGHT, -speed);
}

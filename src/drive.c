#include "C:\Users\mbara\Documents\9228B Turning Point 2.0\include\drive.h"

void robotStop() {
  motorSet(MOTOR_BACK_LEFT, 0);
  motorSet(MOTOR_BACK_RIGHT, 0);
  motorSet(MOTOR_FRONT_RIGHT, 0);
  motorSet(MOTOR_FRONT_LEFT, 0);
}

void robotDriveForward(int speed, double time) {
  motorSet(MOTOR_BACK_LEFT, MAX_SPEED);
  motorSet(MOTOR_BACK_RIGHT, MAX_SPEED);
  motorSet(MOTOR_FRONT_RIGHT, MAX_SPEED);
  motorSet(MOTOR_FRONT_LEFT, MAX_SPEED);
  wait(time * 1000);
  robotStop();
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

  motorSet(MOTOR_FRONT_RIGHT, -(stickLY - stickRX - stickLX) / 2);
  motorSet(MOTOR_BACK_RIGHT, -(stickLY - stickRX + stickLX) / 2);
  motorSet(MOTOR_FRONT_LEFT, -(stickLY + stickRX + stickLX) / 2);
  motorSet(MOTOR_BACK_LEFT, (stickLY + stickRX - stickLX) / 2);

  bool firingMode = false;
  bool firingSpeed = false;

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
    flywheelSet(motorGet(MOTOR_FLYWHEEL_A) / 3);
  }

  if(joystickGetDigital(JOYSTICK_MAIN, 8, JOY_DOWN)) {
    robotStraighten();
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
  gyroTurn(0);
}

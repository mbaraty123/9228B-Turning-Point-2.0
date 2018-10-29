#include "drive.h"
#include <API.h>
#include "motor_ports.h"
#include "controller.h"

void motorSpeedStick(unsigned char channel, int speed) {
  motorSet(channel, abs(speed) > THRESHOLD? speed: 0);
}

void driveStop() {
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
  driveStop();
}

void flywheelSet(int speed) {
  motorSet(MOTOR_FLYWHEEL_A, -speed);
  motorSet(MOTOR_FLYWHEEL_B, -speed);
}

void flywheelStop() {
  flywheelSet(0);
}

void enableIntake() {
  motorSet(MOTOR_INTAKE, MIN_SPEED);
  motorSet(MOTOR_BELT, MAX_SPEED);
}

void disableIntake() {
  motorSet(MOTOR_INTAKE, 0);
  motorSet(MOTOR_BELT, 0);
}

void drive() {


  int stickLX = abs(joystickGetAnalog(JOYSTICK_MAIN, JOYSTICK_LEFT_X)) > THRESHOLD? joystickGetAnalog(JOYSTICK_MAIN, JOYSTICK_LEFT_X): 0;
  int stickLY = abs(joystickGetAnalog(JOYSTICK_MAIN, JOYSTICK_LEFT_Y)) > THRESHOLD? joystickGetAnalog(JOYSTICK_MAIN, JOYSTICK_LEFT_Y): 0;
  int stickRX = abs(joystickGetAnalog(JOYSTICK_MAIN, JOYSTICK_RIGHT_X)) > THRESHOLD? joystickGetAnalog(JOYSTICK_MAIN, JOYSTICK_RIGHT_X): 0;

  motorSet(MOTOR_FRONT_RIGHT, -(stickLY - stickRX - stickLX) / 2);
  motorSet(MOTOR_BACK_RIGHT, -(stickLY - stickRX + stickLX) / 2);
  motorSet(MOTOR_FRONT_LEFT, -(stickLY + stickRX + stickLX) / 2);
  motorSet(MOTOR_BACK_LEFT, (stickLY + stickRX - stickLX) / 2);

  bool intakeIsToggled = false;
  bool firingMode = false;
  bool firingSpeed = false;

  if(joystickGetDigital(JOYSTICK_MAIN, 6, JOY_UP)) {
    intakeIsToggled = true;
  }
  if(joystickGetDigital(JOYSTICK_MAIN, 6, JOY_DOWN)) {
    intakeIsToggled = false;
  }

  if(intakeIsToggled) {
    motorSet(MOTOR_INTAKE, -127);
    motorSet(MOTOR_BELT, 127);
  } else {
    motorSet(MOTOR_INTAKE, 0);
    motorSet(MOTOR_BELT, 0);
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
    motorSet(MOTOR_FLYWHEEL_A, -127);
    motorSet(MOTOR_FLYWHEEL_B, -127);
  } else if(firingMode && !firingSpeed) {
    motorSet(MOTOR_FLYWHEEL_A, -60);
    motorSet(MOTOR_FLYWHEEL_B, -60);
  } else {
    motorSet(MOTOR_FLYWHEEL_A, 0);
    motorSet(MOTOR_FLYWHEEL_B, 0);
  }

}

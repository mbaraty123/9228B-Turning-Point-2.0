/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include <main.h>
#include "drive.h"
#include "auton.h"
#include "encoders.h"

/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */
void autonomous() {

  routine = near;
  color = blue;

  if(routine == near && color == blue) {
    nearRoutineBlue();
  } else if(routine == near && color == red) {
    nearRoutineRed();
  } else if(routine == far) {
    farRoutine();
  } else if(routine == skills) {
    skillsRoutine();
  }
}

void skillsRoutine() {
  flywheelSet(70);
  taskDelay(4000);
  intakeSet(forward);
  taskDelay(1800);
  motorStopAll();

  gyroTurn(1, 5);
  moveSteps(1500, 127);
  imeResetAll();


}

void nearRoutineBlue() {
  //fire up the flywheels
  flywheelSet(70);
  taskDelay(4000);
  intakeSet(forward);
  taskDelay(1800);
  motorStopAll();

  //drive for bottom flag
  motorSet(MOTOR_BACK_LEFT, MAX_SPEED / 2);
  motorSet(MOTOR_BACK_RIGHT, MIN_SPEED / 2);
  motorSet(MOTOR_FRONT_RIGHT, MIN_SPEED / 2 + 25);
  motorSet(MOTOR_FRONT_LEFT, MIN_SPEED / 2);
  taskDelay(2000);
  robotStop();
  taskDelay(500);

  //prepare for tele-op
  motorSet(MOTOR_BACK_LEFT, -MAX_SPEED / 2);
  motorSet(MOTOR_BACK_RIGHT, -MIN_SPEED / 2);
  motorSet(MOTOR_FRONT_RIGHT, -MIN_SPEED / 2);
  motorSet(MOTOR_FRONT_LEFT, -MIN_SPEED / 2);
  taskDelay(1500);
  robotStop();

}

void nearRoutineRed() {
    //fire up the flywheels
    flywheelSet(70);
    taskDelay(4000);
    intakeSet(forward);
    taskDelay(1800);
    motorStopAll();

    //drive for bottom flag
    motorSet(MOTOR_BACK_LEFT, MAX_SPEED / 2);
    motorSet(MOTOR_BACK_RIGHT, MIN_SPEED / 2);
    motorSet(MOTOR_FRONT_RIGHT, MIN_SPEED / 2);
    motorSet(MOTOR_FRONT_LEFT, MIN_SPEED / 2 + 25);
    taskDelay(2000);
    robotStop();
    taskDelay(500);

    //prepare for tele-op
    motorSet(MOTOR_BACK_LEFT, -MAX_SPEED / 2);
    motorSet(MOTOR_BACK_RIGHT, -MIN_SPEED / 2);
    motorSet(MOTOR_FRONT_RIGHT, -MIN_SPEED / 2);
    motorSet(MOTOR_FRONT_LEFT, -MIN_SPEED / 2);
    taskDelay(1500);
    robotStop();
  }


void farRoutine() {
  flywheelSet(120);
  taskDelay(4000);
  intakeSet(forward);
  taskDelay(1800);
  motorStopAll();
  }

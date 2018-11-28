/** @file init.c
 * @brief File for initialization code
 *
 * This file should contain the user initialize() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "gyro.h"
#include "potentiometer.h"
#include "encoders.h"

/*
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO() {
}

/*
 * Runs user initialization code. This function will be started in its own task with the default
 * priority and stack size once when the robot is starting up. It is possible that the VEXnet
 * communication link may not be fully established at this time, so reading from the VEX
 * Joystick may fail.
 *
 * This function should initialize most sensors (gyro, encoders, ultrasonics), LCDs, global
 * variables, and IMEs.
 *
 * This function must exit relatively promptly, or the operatorControl() and autonomous() tasks
 * will not start. An autonomous mode selection menu like the pre_auton() in other environments
 * can be implemented in this task if desired.
 */
void initialize() {
  init_main_gyro();
  //imeInitializeAll();
  setTeamName("9228B");


/*  init_main_lcd(uart2);



lcdSetBacklight(uart2, false);

lcdSetText(uart2, 1, "Auton Routine");
lcdSetText(uart2, 2, "NEAR   FAR   NONE");


//lcdPrint(uart1, 1, "Auton Routine");
//lcdPrint(uart1, 2, "NEAR       FAR       NONE");

unsigned int btnsPressed = lcdReadButtons(uart2);

  if(btnsPressed & 0x1) {
    routine = near;
    lcdClear(uart2);
    lcdPrint(uart2, 1, "left pressed");
  } else if (btnsPressed & 0x2) {
    routine = far;
    lcdClear(uart2);
    lcdPrint(uart2, 1, "middle pressed");
  } else if (btnsPressed & 0x4) {
    routine = none;
    lcdClear(uart2);
    lcdPrint(uart2, 1, "right pressed");
  }


  lcdShutdown(uart2);


  //lcdSetBacklight(uart2, false);*/




}

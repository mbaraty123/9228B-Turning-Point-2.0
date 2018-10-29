/**
 * @brief Controller macro declarations
 * @file controller.h
 * @author Michael Baraty
 * @date 1026/2018
 **/
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

/**
 * @brief The main joystick
 * @author Michael Baraty
 * @date 10/26/2018
 **/
#define JOYSTICK_MAIN 1

/**
 * @brief The paartner joystick
 * @author Michael Baraty
 * @date 10/26/2018
 **/
#define JOYSTICK_PARTNER 2

/**
 * @brief The x-axis on the right joystick
 * @author Michael Baraty
 * @date 10/26/2018
 **/
#define JOYSTICK_RIGHT_X 1

/**
 * @brief The y-axis on the right joystick
 * @author Michael Baraty
 * @date 10/26/2018
 **/
#define JOYSTICK_RIGHT_Y 2

/**
 * @brief The x-axis on the left joystick
 * @author Michael Baraty
 * @date 10/26/2018
 **/
#define JOYSTICK_LEFT_X 4

/**
 * @brief The y-axis on the left joystick
 * @author Michael Baraty
 * @date 10/26/2018
 **/
#define JOYSTICK_LEFT_Y 3

/**
 * @brief reads the joysticks leaving a tolerance for a given THRESHOLD
 * @param joystick
 * @param channel
 * @author Michael Baraty
 * @date 10/26/2018
 */
int joystickGetAnalogA(unsigned char joystick, unsigned char channel);



#endif

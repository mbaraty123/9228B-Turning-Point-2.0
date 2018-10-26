/**
 * @brief Basic drive definitions and functions
 * @file drive.h
 **/
 #ifndef _DRIVE_H_
 #define _DRIVE_H_

/**
 * @brief defines the minimum reading from the joysticks to avoid underpowering the motors
 * @author Michael Baraty
 * @date 10/25/2018
**/
#define THRESHOLD 10

/**
 * @brief sets the spped of the motors according to a joystick taking into account the threshold
 * @param channel
 * @param speed
 * @author Michael Baraty
 * @date 10/25/2018
 */
void motorSpeedStick(unsigned char channel, int speed);

#endif

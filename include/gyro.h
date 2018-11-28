/**
 * @file gyro.h
 * @brief Declarations and macros for the VEX gyroscope.
 *  @author Michael Baraty
 *  @date 10/31/18
 */
#ifndef _GYRO_H_
#define _GYRO_H_

#include "API.h"
#include "drive.h"

/**
 * @brief Port the Gyroscope plugs into.
 * @author Michael Baraty
 * @date 11/10/2018
 */
#define GYRO_PORT 1

/**
  * @brief returns the main gyroscope reading
  * @return gyro direction
  * @author Michael Baraty
  * @date 11/10/2018
  */
int getGyro();

/**
 * Special Gyro multiplier for tuning in Gyro
 * @todo
 */
#define GYRO_MULTIPLIER 196
#define GYRO_TURN_SPEED 100

/**
 * @brief Initializes the main robot gryoscope/
 * Only call function when robot still and ready to start autonomous. Robot
 * should not move for five seconds while Gyro calibrates
 * @return if the Gyro was successfully calibrated
 * @author Michael Baraty
 * @date 10/31/18
 */
bool init_main_gyro();

/**
 *  @brief Spins the robot to face a certain degree.
 *  @author Michael Baraty
 *  @date 10/31/18
 */
void gyroTurn(int degrees, int minSpeed);

int max(int a, int b);

#endif

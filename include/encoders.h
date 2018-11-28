/**
 * @file encoders.h
 * @author Michael Baraty
 * @date 11/2/2018
 * @brief wrapper around encoder functions
 **/
#ifndef _ENCODERS_H_
#define _ENCODERS_H_

#include "API.h"
#include "drive.h"

/**
 * @brief The number of IMEs.
 * This number is compared against the number detect in init_encoders
 * @see init_encoders()
 * @author Michael Baraty
 * @date 10/25/2018
 * @see IME_NUMBER
 **/
#define IME_NUMBER 4

/**
   * @brief defines the distance the robot needs to drive in encoder ticks
   * @author Michael Baraty
   * @date 11/10/2018
  */
#define ENCODER_TILE (392 / 4 * 3.14 * 12)

/**
  * @brief defines the front left IME in the order
  * @author Michael Baraty
  * @date 11/10/2018
  */
#define IME_FRONT_LEFT 1

/**
  * @brief defines the front right IME in the order
  * @author Michael Baraty
  * @date 11/10/2018
  */
#define IME_FRONT_RIGHT 2

/**
  * @brief defines the back left IME in the order
  * @author Michael Baraty
  * @date 11/10/2018
  */
#define IME_BACK_LEFT 0

/**
  * @brief defines the back right IME in the order
  * @author Michael Baraty
  * @date 11/10/2018
  */
#define IME_BACK_RIGHT 3

/**
 * @brief Initializes all motor encoders
 * @author Michael Baraty
 * @date 10/25/2018
 * @see IME_NUMBER
 **/
bool imeInit();

/**
 * @brief Gets the encoder ticks since last reset
 * @param address
 * @author Michael Baraty
 * @date 10/25/2018
 **/
int imeGetTicks(const unsigned char address);

/**
 * @brief Gets the encoder velocity
 * @return velocity
 * @param address
 * @author Michael Baraty
 * @date 11/8/2018
 **/
int imeGetVelocityA(const unsigned char address);

/**
 * @brief moves at a given velocity for a certain number of ticks
 * @param ticks
 * @param dir
 * @author Michael Baraty
 * @date 11/8/2018
 **/
void imeMoveFor(int ticks, Direction dir);

/**
 * @brief Gets the average encoder ticks since the last reset
 * @author Michael Baraty
 * @date 11/8/2018
 **/
int imeGetAverageTicks();

/**
 * @brief Resets all the encoders
 * @author Michael Baraty
 * @date 11/8/2018
 **/
void imeResetAll();

void moveSteps(int steps, int speed);

#endif

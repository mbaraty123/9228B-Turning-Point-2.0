/**
  * @brief Defines different pieces and functions for the autonomous
  * @file auton.h
  * @date 11/10/2018
  * @author Michael Baraty
  */

#ifndef _AUTON_H_
#define _AUTON_H_

#include "API.h"

/**
  * @brief defines the different possible autonomous routines
  * @date 11/10/2018
  * @author Michael Baraty
  */
typedef enum {
  far = 0,
  near = 1,
  none = 2
} AutonRoutine;

/**
  * @brief defines the autonomous routine
  * @author Michael Baraty
  * @date 11/10/2018
  */
static AutonRoutine routine = none;


/**
  * @brief begins the autonomous routine from the square nearest to the flag
  * @date 11/10/2018
  * @author Michael Baraty
  */
void nearRoutine();

/**
  * @brief begins the autonomous routine from the square farthest from the flag
  * @date 11/10/2018
  * @author Michael Baraty
  */
void farRoutine();



#endif

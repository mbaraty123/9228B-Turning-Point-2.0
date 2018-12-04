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
  skills = 2,
  none = 3
} AutonRoutine;

/**
  * @brief defines the different possible autonomous colors for the routines
  * @date 12/4/2018
  * @author Michael Baraty
  */
typedef enum {
  blue = 0,
  red = 1
} Color;


/**
  * @brief defines the autonomous routine
  * @author Michael Baraty
  * @date 11/10/2018
  */
static AutonRoutine routine = none;

/**
  * @brief defines the autonomous color
  * @author Michael Baraty
  * @date 11/10/2018
  */
static Color color;


/**
  * @brief begins the autonomous routine from the blue square nearest to the flag
  * @date 12/4/2018
  * @author Michael Baraty
  */
void nearRoutineBlue();

/**
  * @brief begins the autonomous routine from the red square nearest to the flag
  * @date 12/4/2018
  * @author Michael Baraty
  */
void nearRoutineRed();

/**
  * @brief begins the autonomous routine from the blue square farthest from the flag
  * @date 12/4/2018
  * @author Michael Baraty
  */
void farRoutineRed();

/**
  * @brief begins the autonomous routine from the red square farthest from the flag
  * @date 12/4/2018
  * @author Michael Baraty
  */
void farRoutineBlue();

/**
  * @brief begins the autonomous skills routine
  * @date 12/4/2018
  * @author Michael Baraty
  */
void skillsRoutine();



#endif

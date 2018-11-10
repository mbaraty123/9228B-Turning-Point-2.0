#ifndef _POTENTIOMETER_H_
#define _POTENTIOMETER_H_

#include "API.h"

/**
  * @brief defines the port the potentiometer for the flipper is plugged into
  * @author Michael Baraty
  * @date 11/10/2018
  */
#define POTENTIOMETER_FLIPPER 2

/**
  * @brief calibrates the main potentiometer
  * @author Michael Baraty
  * @date 11/10/2018
  */
void potentiometerInit();

/**
  * @brief returns the calibrated reading on the flipper potentiometer
  * @return flipper potentiometer calibrated reading
  * @author Michael Baraty
  * @date 11/10/2018
  */
int flipperPosition();

/**
  * @brief prints the flipper potentiometer calibrated reading
  * @author Michael Baraty
  * @date 11/10/2018
  */
void printFlipper();

#endif

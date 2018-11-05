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

#define COUNTS_PER_ROTATION 392

#define WHEEL_DIAMETER_INCHES 4

#define ENCODER_INCH (COUNTS_PER_ROTATION / WHEEL_DIAMETER_INCHES * M_PI)

#define ENCODER_TILE (ENCODER_INCH * 12)

#define IME_FRONT_LEFT 0

#define IME_FRONT_RIGHT 1

#define IME_BACK_LEFT 2

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
 * @author Michael Baraty
 * @date 10/25/2018
 **/
int imeGetTicks(const unsigned char address);

/**
 * @brief Gets the encoder reads
 * @author Michael Baraty
 * @date 10/25/2018
 **/
int imeGetVelocityA(const unsigned char address);

void imeMoveFor(int ticks, Direction dir);

int imeGetAverageTicks();

void imeResetAll();

#endif

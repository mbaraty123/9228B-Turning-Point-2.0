/**
 * @file encoders.h
 * @author Michael Baraty
 * @date 10/25/2018
 * @brief wrapper around encoder functions
 **/
#ifndef _ENCODERS_H_
#define _ENCODERS_H_

#include <API.h>

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
 * @brief Initializes all motor encoders
 * @author Michael Baraty
 * @date 10/25/2018
 * @see IME_NUMBER
 **/
bool init_encoders();

/**
 * @brief Gets the encoder ticks since last reset
 * @author Michael Baraty
 * @date 10/25/2018
 **/
int get_encoder_ticks(const unsigned char address);

/**
 * @brief Gets the encoder reads
 * @author Michael Baraty
 * @date 10/25/2018
 **/
int get_encoder_velocity(const unsigned char address);

/**
 * @brief Gets the average of four encoders or the value of one encoder
 * @author Michael Baraty
 * @date 10/25/2018
 **/
int ime_get_average(bool multi);

int ime_get_right_dist();

int ime_get_left_dist();

int ime_get_right_vel();

int ime_get_left_vel();

#endif

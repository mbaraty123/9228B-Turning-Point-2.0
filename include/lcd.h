/**
 * @file lcd.h
 * @author Michael Baraty
 * @date 11/2/2018
 * @brief LCD wrapper functions and macros
 **/

#ifndef _LCD_H_
#define _LCD_H_

#include <API.h>

/**
 * @brief The top row on the lcd screen
 * @author Michael Baraty
 * @date 11/2/2018
 **/
#define TOP_ROW 1

/**
 * @brief The bottom row on the lcd screen
 * @author Michael Baraty
 * @date 11/2/2018
 **/
#define BOTTOM_ROW 2

/**
 * @brief Represents the state of a button
 *
 * A button can be pressed of RELEASED. Release is false which is also 0.
 * PRESSED is true or 1.
 *
 * @author Michael Baraty
 * @date 11/2/2018
 **/
typedef enum {
  /** A released button **/
  RELEASED = false,
  /** A pressed button **/
  PRESSED = true,
} button_state;

/**
 * @brief represents the state of the lcd buttons
 * @author Michael Baraty
 * @date 11/2/2018
 **/
typedef struct {
  button_state left;
  button_state middle;
  button_state right;
} lcd_buttons;

/**
 * @brief Returns the pressed buttons
 * @return a struct containing the states of all three buttons.
 * @author Michael Baraty
 * @date 11/2/2018
 * @see lcd_buttons
 **/
lcd_buttons lcd_get_pressed_buttons();

/**
 * @brief Clears the lcd
 * @author Michael Baraty
 * @date 11/2/2018
 **/
void lcd_clear();

/**
 * @brief Initializes the lcd screen.
 * Also will initialize the lcd_port var. Must be called before any lcd function
 *can be called.
 * @param lcd the urart port of the lcd screen
 * @see uart1
 * @see uart2
 * @author Michael Baraty
 * @date 11/2/2018
 **/
void init_main_lcd(FILE *lcd);

/**
 * @brief prints a string to a line on the lcd
 * @param line the line to print on
 * @param str string to print
 * @author Michael Baraty
 * @date 11/2/2018
 **/
void lcd_print(unsigned int line, const char *str);

/**
 * @brief prints a formatted string to a line on the lcd. Similar to printf
 * @param line the line to print on
 * @param format_str format string string to print
 * @author Michael Baraty
 * @date 11/2/2018
 **/
void lcd_printf(unsigned int line, const char *format_str, ...);

/**
 * @brief sets the backlight of the lcd
 * @param state a boolean representing the state of the backlight. true = on,
 *false = off.
 * @author Michael Baraty
 * @date 11/2/2018
 **/
void lcd_set_backlight(bool state);

/**
 * @brief Prompts the user to confirm a string.
 * User must press middle button to confirm.
 * Function is not thread safe and will stall a thread.
 *
 * @param confirm_text the text for the user to confirm.
 * @author Michael Baraty
 * @date 11/2/2018
 **/
void promt_confirmation(const char *confirm_text);

#endif

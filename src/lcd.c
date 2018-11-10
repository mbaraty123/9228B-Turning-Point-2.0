#include "lcd.h"
#include "API.h"

static FILE *lcd_port = NULL;

static bool lcd_assert() {
  if (lcd_port == NULL) {
    printf("LCD NULL!");
    return false;
  }
  return true;
}

lcd_buttons lcd_get_pressed_buttons() {
  lcd_assert();
  unsigned int btn_binary = lcdReadButtons(lcd_port);
  bool left = btn_binary & 0x1;   // 0001
  bool middle = btn_binary & 0x2; // 0010
  bool right = btn_binary & 0x4;  // 0100
  lcd_buttons btns;
  btns.left = left ? PRESSED : RELEASED;
  btns.middle = middle ? PRESSED : RELEASED;
  btns.right = right ? PRESSED : RELEASED;

  return btns;
}

void lcd_clear() {
  lcd_assert();
  lcdClear(lcd_port);
}

void init_main_lcd(FILE *lcd) {
  lcd_port = lcd;
  lcdInit(lcd);
  lcd_clear();
}

void lcd_print(const unsigned int line, const char *str) {
  lcd_assert();
  lcdSetText(lcd_port, line, str);
}

void lcd_set_backlight(const bool state) {
  lcd_assert();
  lcdSetBacklight(lcd_port, state);
}

void promt_confirmation(const char *confirm_text) {
  lcd_assert();
  lcd_print(1, confirm_text);
  while (lcd_get_pressed_buttons().middle != PRESSED) {
    delay(200);
  }
}

#ifndef __GENESIS_H
#define __GENESIS_H
#include "libgenesis.c"

void lcd_print(const char *message, int line);
void sleep(int seconds);
void set_pin_on(uint8_t pin);
void set_pin_off(uint8_t pin);

#endif
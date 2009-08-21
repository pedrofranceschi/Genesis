#ifndef __GENESIS_H
#define __GENESIS_H
#include "libgenesis.c"

void lcd_print(const char *message, int line);
void set_pin_on(int pin);
void set_pin_off(int pin);
void sleep(int seconds);

#endif
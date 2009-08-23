/* 
 * libgenesis.h
 * Genesis - A Library for simple MCU programming in C.
 *
 * by pH (Pedro Henrique Cavallieri Franceschi)
 * iBlogeek.com - 2006-2009 (C)
 * 
 * All rights reserved
 *
*/

#ifndef __GENESIS_H
#define __GENESIS_H
#include "libgenesis.c"

void lcd_start();
void lcd_print(const char *message, int line);
void clear_lcd();
void sleep(int seconds);
void set_pin_on(uint8_t pin);
void set_pin_off(uint8_t pin);
void set_led_intensity(int percentage);
void led_pwm_start();
void led_pwm_stop();
void servo_pwm_start();
void servo_pwm_set(int position);
void servo_pwm_stop();
int pin_status(uint8_t pin);
void adc_start();
int adc_read();
void serial_start();
void serial_write(char buf);
char serial_read();
void buzzer_play(uint8_t pin, int delay_i, int duration);

#endif
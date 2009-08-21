#include <stdio.h>
#include <math.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <inttypes.h>
#include <avr/pgmspace.h>
#include "../libnerdkits/delay.h"
#include "../libnerdkits/lcd.h"
#include "../libnerdkits/uart.h"

void lcd_print(char message[], int line)
{
	switch(line)
	{
		case '1':
		lcd_line_one();
		case '2':
		lcd_line_two();
		case '3':
		lcd_line_three();
		case '4':
		lcd_line_four();
	}
	fprintf_P(PSTR("%c"), message);
}

void set_pin_on(int pin)
{
	DDRB |= (1<<pin);
	PORTB |= (1<<pin);
}

void set_pin_off(int pin)
{
	PORTB &= ~(1<<pin);
}

void sleep(int seconds)
{
	delay_ms((seconds * 1000));
}
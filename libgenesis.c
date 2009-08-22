#include <stdio.h>
#include <math.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <inttypes.h>
#include "../libnerdkits/delay.h"
#include "../libnerdkits/lcd.h"
#include "../libnerdkits/uart.h"

void lcd_print(const char *message, int line)
{
	lcd_init();
	if (line == 1)
	{
		lcd_line_one();
	}
	if (line == 2)
	{
		lcd_line_two();
	}
	if (line == 3)
	{
		lcd_line_three();
	}
	if (line == 4)
	{
		lcd_line_four();
	}
	while(pgm_read_byte(message) != 0x00)
	    lcd_write_data(pgm_read_byte(message++));
}

void clear_lcd()
{
	lcd_print(PSTR("                    "), 1);
	lcd_print(PSTR("                    "), 2);
	lcd_print(PSTR("                    "), 3);
	lcd_print(PSTR("                    "), 4);
}

void sleep(int seconds)
{
	delay_ms((seconds * 1000));
}

void set_pin_on(uint8_t pin)
{
	DDRC  |=  (1<<pin);
	PORTC |=  (1<<pin);
}

void set_pin_off(uint8_t pin)
{
	PORTC &= ~(1<<pin);
}

void set_led_intensity(uint8_t pin, int percentage)
{
	int setted_percentage = (percentage * 2.5);
	if (percentage > 100)
	{
		setted_percentage = 100;
	}	
	OCR1AL = setted_percentage;
}

void led_pwm_start(uint8_t pin)
{
	OCR1AH = 0;
	DDRB |= (1<<pin);
	TCCR1A = (1<<COM1A1)|(1<<1);
	TCCR1B = 1;
}

void led_pwm_stop()
{
	TCCR1B = 0;
	TCCR1A = 0;
}

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

void lcd_print(const char *message, int line)
{
	lcd_init();
	lcd_home();
	if (line == 1)
	{
		lcd_line_one();
	}
	if (line == 2)
	{
		lcd_line_one();
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

void sleep(int seconds)
{
	delay_ms((seconds * 1000));
}
#include "../../libgenesis.h" // include the main lib
int main()
{
	lcd_start(); // start the LCD
	while (1) // loop
	{
	sleep(1); // wait a second
	lcd_print(PSTR("LibGenesis - Simple "), 1); // print the message in line 1
	lcd_print(PSTR("MCU programming lib."), 2); // print the message in line 2
	lcd_print(PSTR("by pH - iBlogeek.com"), 4); // print the message in line 4
	sleep(1); // wait a second
	clear_lcd(); // remove everything from LCD 
}
}
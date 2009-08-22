#include "../../libgenesis.h" // include the main lib
int main()
{
	// PIN MAP:
	// PC5 - Button pulled to ground (-) when pressed
	// PC4 - LED
	
	lcd_start(); // start the LCD
	lcd_print(PSTR("  Button Detection  "), 1); // print the message in line 1
	lcd_print(PSTR("  using libgenesis  "), 2); // print the message in line 2
	lcd_print(PSTR("by pH - iBlogeek.com"), 4); // print the message in line 4
	while (1) // loop
	{
	 if (pin_status(PC5) == 1) // if PC5 is pulled to ground (button is pressed)...
	 {
		lcd_print(PSTR("status: PRESSED    "), 3); // print the message in line 3 telling the user the button is pressed.
		set_pin_on(PC4); // set the LED on PC4 on.
	 }
	 else // if PC5 is not pulled to ground (isn't pressed)...
	{
		lcd_print(PSTR("status: NOT PRESSED"), 3); // print the message in line 3 telling the user the button is pressed.
		set_pin_off(PC4); // set the LED on PC4 off.
	}
}
}
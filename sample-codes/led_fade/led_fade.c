#include "../../libgenesis.h" // include the main lib
// 
// // Some notes in Hz (from http://is.gd/2tvDr)
#define C 955
#define D 851
#define E 758
#define F 715
#define G 637
#define A 568
#define B 506
#define SmallC 477
#define DELAY 20

int main()
{
	// PIN MAP:
	// PC5 - Button pulled to ground (-) when pressed
	// PB1 - LED
	
	led_pwm_start(); //start LED pwm
	lcd_start();
	lcd_print(PSTR("LED Fade with       "), 1); // print the message in line 1
	lcd_print(PSTR("libgenesis          "), 2); // print the message in line 2
	lcd_print(PSTR("by pH - iBlogeek.com"), 4); // print the message in line 4
	while (1) // loop
	{
		if (pin_status(PC5) == 1) // if PC5 is pulled to ground (button is pressed)...
		{
			int i;
			for(i = 0; i < 100; ++i) // slowly turn the led on
			{
				set_led_intensity(i); // set led intensity
				delay_ms(15); // wait 15 milisec.
			}
			for (i = 100; i > 0; i--) // slowly turn the led off
			{
				set_led_intensity(i);
				delay_ms(15);
			}
			set_led_intensity(0);
		}
	}
}
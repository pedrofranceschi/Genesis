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
	// PB1 - piezo element
	// PC4 - LED
	
	lcd_start(); // start the LCD
	serial_start(); // start serial port comunication
	lcd_print(PSTR("Piano with Piezo    "), 1); // print the message in line 1
	lcd_print(PSTR("using libgenesis    "), 2); // print the message in line 2
	lcd_print(PSTR("by pH - iBlogeek.com"), 4); // print the message in line 4
	while (1)
	{
		char serialRead; // declare a char that will store the serial port input
		serialRead = serial_read(); // read the character over serial port
		
		set_pin_off(PC4); 
		if (serialRead == 'z'||serialRead == 'Z') // if the character sent over serial port is Z, we play the C...
		{
			buzzer_play(PB1, C, DELAY); // play the C with duration of DELAY in pin PB1...
			set_pin_on(PC4); // set LED on PC4 on
		}
		if (serialRead == 'x'||serialRead == 'X')
		{
			buzzer_play(PB1, D, DELAY); 
			set_pin_on(PC4); 
		}
		if (serialRead == 'c'||serialRead == 'C')
		{
			buzzer_play(PB1, E, DELAY); 
			set_pin_on(PC4); 
		}
		if (serialRead == 'v'||serialRead == 'V')
		{
			buzzer_play(PB1, F, DELAY); 
			set_pin_on(PC4); 
		}
		if (serialRead == 'b'||serialRead == 'B')
		{
			buzzer_play(PB1, G, DELAY); 
			set_pin_on(PC4); 
		}
		if (serialRead == 'n'||serialRead == 'N')
		{
			buzzer_play(PB1, A, DELAY); 
			set_pin_on(PC4); 
		}
		if (serialRead == 'm'||serialRead == 'M')
		{
			buzzer_play(PB1, B, DELAY); 
			set_pin_on(PC4); 
		}
		if (serialRead == ',')
		{
			buzzer_play(PB1, SmallC, DELAY); 
			set_pin_on(PC4); 
		}
	}
}
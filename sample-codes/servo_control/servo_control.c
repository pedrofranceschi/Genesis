#include "../../libgenesis.h" // include the main lib
int main()
{
	// PIN MAP:
	// PB2 - servo signal
	// PC5 - button pulled to ground (-) when pressed (turn servo to right)
	// PC4 - button pulled to ground (-) when pressed (turn servo to left)
	
	int position; // declare an integer to hold the servo position
	lcd_start(); // start the LCD
	servo_pwm_start(); // start the servo PWM
	position = 1300; // that's the starting position that is setted automatically when
	// servo_pwm_start(); is called.
	lcd_print(PSTR("Servo PWM Control   "), 1); // print the message in line 1
	lcd_print(PSTR("using libgenesis    "), 2); // print the message in line 2
	lcd_print(PSTR("by pH - iBlogeek.com"), 4); // print the message in line 4
	
	while (1) // loop
	{
	if (pin_status(PC5) == 1) // if PC5 is pulled to ground (button is pressed)...
	{
		position = position + 20; // increase in 20 the position of the servo
		servo_pwm_set(position); // set the new position to servo
	}
	if (pin_status(PC4) == 1) // if PC4 is pulled to ground (button is pressed)...
	{
		position = position - 20; // decrease in 20 the position of the servo
		servo_pwm_set(position); // set the new position to servo
	}
}
}
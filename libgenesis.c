#include <stdio.h>
#include <math.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <inttypes.h>
#include "../libnerdkits/delay.h"
#include "../libnerdkits/lcd.h"
#include "../libnerdkits/uart.h"

void lcd_start()
{
	lcd_init();
}

void lcd_print(const char *message, int line)
{
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

void set_led_intensity(int percentage)
{
	// WARNING: intensity will be setted on
	// pin OC1A (PC1)
	
	int setted_percentage = (percentage * 2.5);
	if (percentage > 100)
	{
		setted_percentage = 100;
	}	
	OCR1AL = setted_percentage;
}

void led_pwm_start()
{
	// WARNING: this function just works on 
	// pin OC1A (PC1)
	
	OCR1AH = 0;
	DDRB |= (1<<PC1);
	TCCR1A = (1<<COM1A1)|(1<<1);
	TCCR1B = 1;
}

void led_pwm_stop()
{
	TCCR1B = 0;
	TCCR1A = 0;
}

void servo_pwm_set(int position) 
{	
	if (position == 4450) position = 4450; // max. position
	if (position == 1300) position = 1300; // min. position
	OCR1B = position;
}

void servo_pwm_start()
{
	// WARNING: this function just works on 
	// pin OC1B (PC2)
	
	DDRB |= (1<<PB2);
	OCR1A = 36864;
	servo_pwm_set(1300);
    TCCR1A = (1<<COM1B1) | (1<<WGM11) | (1<<WGM10);
    TCCR1B = (1<<WGM13) | (1<<WGM12) | (1<<CS11);
}

void servo_pwm_stop()
{
	TCCR1B = 0;
	TCCR1A = 0;
}

int pin_status(uint8_t pin)
{
	// Returned values:
	// 1 - Is pulled to ground (pressed)
	// 2 - Is not pulled to ground (not pressed)
	
	PORTC |= (1<<pin);
	if (PINC & (1<<pin))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void adc_start()
{
	// WARNING: this function just works on
	// pin PC0 (ADC0)
	
	ADMUX = 0;
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
	ADCSRA |= (1<<ADSC);
}

int adc_read() {
	while(ADCSRA & (1<<ADSC)) {
	}
	uint16_t result = ADCL;
	uint16_t temp = ADCH;
	result = result + (temp<<8);
	
	ADCSRA |= (1<<ADSC);
	return result;
}

void serial_start()
{
	uart_init();
	FILE uart_stream = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);
	stdin = stdout = &uart_stream;
}

void serial_write(char buf)
{
	uart_write(buf);
}

char serial_read()
{
	return uart_read();
}

void buzzer_play(uint8_t pin, int delay_i, int duration)
{	
	// WARNING: delay should be the value of the note
	// in Hz (you can find notes in Hz in http://is.gd/2tvDr)
	
	// duration should be passed in millisec.
	int delay = (500000/delay_i);
	OSCCAL = 176;
	DDRB |= (1<<pin);
	
	uint16_t tmp = 100 * duration;
	uint16_t delaysm = delay / 50;
	uint16_t cycles = tmp / delaysm;
    
	while(cycles > 0) {
	  PORTB |= (1<<pin);
	  delay_us(delay);
	  PORTB &= ~(1<<pin);
	  delay_us(delay);
	  cycles--;
	}
}
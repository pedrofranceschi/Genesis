#include "../libgenesis/libgenesis.h"
int main()
{
	serial_start();
	lcd_start();
	lcd_print(PSTR("********************"), 1);
	lcd_print(PSTR("  GMAIL NOTIFIER    "), 2);
	lcd_print(PSTR("  using libgenesis  "), 3);
	lcd_print(PSTR("by pH - iBlogeek.com"), 4);
	
	while (1) {
	char tc;
	tc = serial_read();
	
	if (tc == '0')
	{
		set_pin_off(PC4);
	}
	if (tc == '1')
	{
		set_pin_on(PC4);
	}
}
}
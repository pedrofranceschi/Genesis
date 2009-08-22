GCCFLAGS=-g -Os -Wall -mmcu=atmega168 
LINKFLAGS=-Wl,-u,vfprintf -lprintf_flt -Wl,-u,vfscanf -lscanf_flt -lm
AVRDUDEFLAGS=-c avr109 -p m168 -b 115200 -P /dev/cu.PL2303-0000101D
LINKOBJECTS=../../includes/delay.o ../../includes/lcd.o ../../includes/uart.o

all:	lcd_message-upload

lcd_message.hex:	lcd_message.c
	make -C ../../includes/
	avr-gcc ${GCCFLAGS} ${LINKFLAGS} -o lcd_message.o lcd_message.c ${LINKOBJECTS}
	avr-objcopy -j .text -O ihex lcd_message.o lcd_message.hex
	
lcd_message.ass:	lcd_message.hex
	avr-objdump -S -d lcd_message.o > lcd_message.ass
	
lcd_message-upload:	lcd_message.hex
	avrdude ${AVRDUDEFLAGS} -U flash:w:lcd_message.hex:a

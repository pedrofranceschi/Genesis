GCCFLAGS=-g -Os -Wall -mmcu=atmega168 
LINKFLAGS=-Wl,-u,vfprintf -lprintf_flt -Wl,-u,vfscanf -lscanf_flt -lm
AVRDUDEFLAGS=-c avr109 -p m168 -b 115200 -P /dev/cu.PL2303-0000101D
LINKOBJECTS=../../includes/delay.o ../../includes/lcd.o ../../includes/uart.o

all:	led_fade-upload

led_fade.hex:	led_fade.c
	make -C ../../includes/
	avr-gcc ${GCCFLAGS} ${LINKFLAGS} -o led_fade.o led_fade.c ${LINKOBJECTS}
	avr-objcopy -j .text -O ihex led_fade.o led_fade.hex
	
led_fade.ass:	led_fade.hex
	avr-objdump -S -d led_fade.o > led_fade.ass
	
led_fade-upload:	led_fade.hex
	avrdude ${AVRDUDEFLAGS} -U flash:w:led_fade.hex:a

GCCFLAGS=-g -Os -Wall -mmcu=atmega168 
LINKFLAGS=-Wl,-u,vfprintf -lprintf_flt -Wl,-u,vfscanf -lscanf_flt -lm
AVRDUDEFLAGS=-c avr109 -p m168 -b 115200 -P /dev/cu.PL2303-0000101D
LINKOBJECTS=../../includes/delay.o ../../includes/lcd.o ../../includes/uart.o

all:	servo_control-upload

servo_control.hex:	servo_control.c
	make -C ../../includes/
	avr-gcc ${GCCFLAGS} ${LINKFLAGS} -o servo_control.o servo_control.c ${LINKOBJECTS}
	avr-objcopy -j .text -O ihex servo_control.o servo_control.hex
	
servo_control.ass:	servo_control.hex
	avr-objdump -S -d servo_control.o > servo_control.ass
	
servo_control-upload:	servo_control.hex
	avrdude ${AVRDUDEFLAGS} -U flash:w:servo_control.hex:a

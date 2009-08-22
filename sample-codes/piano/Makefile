GCCFLAGS=-g -Os -Wall -mmcu=atmega168 
LINKFLAGS=-Wl,-u,vfprintf -lprintf_flt -Wl,-u,vfscanf -lscanf_flt -lm
AVRDUDEFLAGS=-c avr109 -p m168 -b 115200 -P /dev/cu.PL2303-0000101D
LINKOBJECTS=../../includes/delay.o ../../includes/lcd.o ../../includes/uart.o

all:	piano-upload

piano.hex:	piano.c
	make -C ../../includes/
	avr-gcc ${GCCFLAGS} ${LINKFLAGS} -o piano.o piano.c ${LINKOBJECTS}
	avr-objcopy -j .text -O ihex piano.o piano.hex
	
piano.ass:	piano.hex
	avr-objdump -S -d piano.o > piano.ass
	
piano-upload:	piano.hex
	avrdude ${AVRDUDEFLAGS} -U flash:w:piano.hex:a

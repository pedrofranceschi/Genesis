GCCFLAGS=-g -Os -Wall -mmcu=atmega168 
LINKFLAGS=-Wl,-u,vfprintf -lprintf_flt -Wl,-u,vfscanf -lscanf_flt -lm
AVRDUDEFLAGS=-c avr109 -p m168 -b 115200 -P /dev/cu.PL2303-0000101D
LINKOBJECTS=../../includes/delay.o ../../includes/lcd.o ../../includes/uart.o

all:	button_detection-upload

button_detection.hex:	button_detection.c
	make -C ../../includes/
	avr-gcc ${GCCFLAGS} ${LINKFLAGS} -o button_detection.o button_detection.c ${LINKOBJECTS}
	avr-objcopy -j .text -O ihex button_detection.o button_detection.hex
	
button_detection.ass:	button_detection.hex
	avr-objdump -S -d button_detection.o > button_detection.ass
	
button_detection-upload:	button_detection.hex
	avrdude ${AVRDUDEFLAGS} -U flash:w:button_detection.hex:a

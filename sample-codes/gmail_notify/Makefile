GCCFLAGS=-g -Os -Wall -mmcu=atmega168 
LINKFLAGS=-Wl,-u,vfprintf -lprintf_flt -Wl,-u,vfscanf -lscanf_flt -lm
AVRDUDEFLAGS=-c avr109 -p m168 -b 115200 -P /dev/cu.PL2303-0000101D
LINKOBJECTS=../libnerdkits/delay.o ../libnerdkits/lcd.o ../libnerdkits/uart.o

all:	gmail_notify-upload

gmail_notify.hex:	gmail_notify.c
	make -C ../libnerdkits
	avr-gcc ${GCCFLAGS} ${LINKFLAGS} -o gmail_notify.o gmail_notify.c ${LINKOBJECTS}
	avr-objcopy -j .text -O ihex gmail_notify.o gmail_notify.hex
	
gmail_notify.ass:	gmail_notify.hex
	avr-objdump -S -d gmail_notify.o > gmail_notify.ass
	
gmail_notify-upload:	gmail_notify.hex
	avrdude ${AVRDUDEFLAGS} -U flash:w:gmail_notify.hex:a

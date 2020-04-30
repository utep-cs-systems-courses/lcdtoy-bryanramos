# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include
LDFLAGS 	= -L/opt/ti/msp430_gcc/include -L../lib 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as	-mcpu=msp430 --traditional-format -mP

all: project2.elf libLcd.a
libLcd.a: font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o
	$(AR) crs $@ $^
	
lcddraw.o: lcddraw.c lcddraw.h lcdutils.h
lcdutils.o: lcdutils.c lcdutils.h

install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

#additional rules for files
project2.elf: ${COMMON_OBJECTS} stateMachines.o buzzer.o interrupts.o led.o switches.o projectMain.o libLcd.a ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^
	

load: project2.elf
	msp430loader.sh project2.elf

clean:
	rm -f libLcd.a *.o *.elf
	
buzzer.o: buzzer.c buzzer.h

led.o: led.c led.h switches.h

switches.o: switches.c led.h switches.h buzzer.h

stateMachines.o: stateMachines.s stateMachines.h led.h switches.h

projectMain.o: projectMain.c buzzer.h led.h switches.h

interrupts.o: interrupts.c 

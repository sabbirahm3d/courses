# MAIN:="main"
# DEP:="music"

# .PHONY: run
# run:
# 	@./${MAIN}.o


# .PHONY: compile
# compile:
# 	@gcc -o ${MAIN}.o ${MAIN}.c ${DEP}.c -Wall


# .PHONY: clean
# clean:
# 	# clean out cache and temporary files
# 	@find . -name "*.o" -type f -delete

DEVICE     = atmega169
CLOCK      = 2000000
PROGRAMMER = stk500v1
PORT	   = /dev/tty56
BAUD       = 19200
FILENAME   = main
MUSIC 	   = music
COMPILE    = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) -std=c99

all: usb clean build upload

usb:
	ls /dev/cu.*
	
build:
	$(COMPILE) -c $(FILENAME).c -o $(FILENAME).o
	$(COMPILE) -c $(MUSIC).c -o $(MUSIC).o
	$(COMPILE) -o $(FILENAME).elf $(FILENAME).o $(MUSIC).o
	avr-objcopy -j .text -j .data -O ihex $(FILENAME).elf $(FILENAME).hex
	avr-size --format=avr --mcu=$(DEVICE) $(FILENAME).elf

upload:
	avrdude -v -p $(DEVICE) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i 

clean:
	@find . -name "*.o" -o "*.hex" -o "*.elf" -type f -delete
	rm main.o
	rm main.elf
	rm main.hex
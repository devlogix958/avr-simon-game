MCU = atmega328p
F_CPU = 16000000UL
PORT = /dev/ttyUSB0
BAUD = 115200

CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os

all: main.hex

main.elf: main.c
	$(CC) $(CFLAGS) -o main.elf main.c

main.hex: main.elf
	avr-objcopy -O ihex -R .eeprom main.elf main.hex

flash: main.hex
	avrdude -c arduino -p $(MCU) -P $(PORT) -b $(BAUD) -U flash:w:main.hex

clean:
	rm -f *.elf *.hex
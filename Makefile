MCU = atmega328p
F_CPU = 16000000UL
PORT = /dev/ttyUSB0
BAUD = 115200

CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os

SRC = main.c timer.c loading.c randomizer.c error.c leds.c buttons.c game.c init.c win.c

all: main.hex

main.elf: $(SRC)
	$(CC) $(CFLAGS) -o main.elf $(SRC)

main.hex: main.elf
	avr-objcopy -O ihex -R .eeprom main.elf main.hex

flash: main.hex
	avrdude -c arduino -p $(MCU) -P $(PORT) -b $(BAUD) -U flash:w:main.hex

clean:
	rm -f *.elf *.hex
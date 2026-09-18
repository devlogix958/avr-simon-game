###AVR Simon Game
A simple Simon-style memory game built around the ATmega328P microcontroller.
The game generates a sequence of LED signals that the player has to reproduce using buttons. The sequence becomes progressively longer as the player successfully completes each round.

#Components
- Arduino UNO
- 3x push buttons
- 3x LEDs
- 3x 10 kΩ resistors for button pull-downs
- 3x 220 Ω resistors for LED current limiting

#Hardware Schematic
The complete hardware schematic was designed in KiCad.
<img width="1006" height="673" alt="image" src="https://github.com/user-attachments/assets/4bddafbd-e0a3-487e-9731-4f8cc31924a2" />

#Build
Clone the repository:
git clone https://github.com/devlogix958/avr-simon-game.git
cd avr-simon-game

Build the firmware:
make

Connect the Arduino UNO to the programmer and run:
make flash

To remove generated build files:
make clean

#How to Play
Press BTN_RED and BTN_GREEN simultaneously to start the game.
Watch the LED sequence.
Reproduce the sequence using the three buttons.
If the sequence is correct, the next round begins with an increased difficulty.
If the sequence is incorrect, the game ends or resets.



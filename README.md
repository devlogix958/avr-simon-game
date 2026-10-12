<div align="center">
  
# 🎮 AVR Simon Game

**A Simon-style memory game built on the ATmega328P microcontroller**

![Platform](https://img.shields.io/badge/platform-Arduino%20UNO-00979D?logo=arduino&logoColor=white)
![MCU](https://img.shields.io/badge/MCU-ATmega328P-red)
![Language](https://img.shields.io/badge/language-C-blue)
![Schematic](https://img.shields.io/badge/schematic-KiCad-314cb0)

</div>

---

## About

A simple Simon-style memory game. The device generates a sequence of LED flashes, and the player has to reproduce it using buttons. The sequence gets longer with every successfully completed round.

## Components

| Component | Qty | Purpose |
|-----------|:---:|---------|
| Arduino UNO (ATmega328P) | 1 | Microcontroller |
| Push buttons | 3 | Player input |
| LEDs | 3 | Sequence output |
| 10 kΩ resistor | 3 | Button pull-downs |
| 220 Ω resistor | 3 | LED current limiting |

## Hardware

### Schematic (KiCad)

The complete hardware schematic was designed in KiCad.

<img src="https://github.com/user-attachments/assets/4bddafbd-e0a3-487e-9731-4f8cc31924a2" alt="KiCad schematic" width="800">

### Assembled Circuit

<img width="800" height="600" alt="photo_2026-10-12_13-04-42" src="https://github.com/user-attachments/assets/35a43ab8-9e40-484d-80c2-db959e3b1e19" />

### Pinout

| Element | AVR Pin | Arduino Pin |
|---------|-----|-----|
| BTN_RED | `PC0` | `A0` |
| BTN_GREEN | `PC1` | `A1` |
| BTN_BLUE | `PC2` | `A2` |
| LED_RED | `PD2` | `D2` |
| LED_GREEN | `PD3` | `D3` |
| LED_BLUE | `PD4` | `D4` |

## Build

Clone the repository:

```bash
git clone https://github.com/devlogix958/avr-simon-game.git
cd avr-simon-game
```

Build the firmware:

```bash
make
```

Connect the Arduino UNO to the programmer and flash it:

```bash
make flash
```

Remove generated build files:

```bash
make clean
```

## How to Play

1. Press **BTN_RED** and **BTN_GREEN** simultaneously to start the game.
2. Watch the LED sequence.
3. Reproduce the sequence using the three buttons.
4. If the sequence is correct, the next round begins with increased difficulty.
5. If the sequence is incorrect, the game ends or resets.

## Project Structure

```
avr-simon-game/
├── main.c          
├── *.c / *.h       # other source files
├── Makefile
└── README.md
```



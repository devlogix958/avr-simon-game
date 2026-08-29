#include <avr/io.h>
#include "leds.h"
#include "timer.h"

void leds(const int light){
    switch(light){
                case 0:
                PORTD |= (1 << PD2);
                timer(300);
                PORTD &= ~(1 << PD2);
                timer(300);
                break;

                case 1:
                PORTD |= (1 << PD3);
                timer(300);
                PORTD &= ~(1 << PD3);
                timer(300);
                break;

                case 2:
                PORTD |= (1 << PD4);
                timer(300);
                PORTD &= ~(1 << PD4);
                timer(300);
                break;
            }
}
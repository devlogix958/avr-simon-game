#include <avr/io.h>
#include "timer.h"
#include "loading.h"

void loading (){
for(int i = 0; i <= 2; i ++){ 
    PORTD |= (1 << PD2);
    timer(200);

    PORTD &= ~(1 << PD2);

    PORTD |= (1 << PD3); 
    timer(200);

    PORTD &= ~(1 << PD3);

    PORTD |= (1 << PD4); 
    timer(200);

    PORTD &= ~(1 << PD4);

}
}
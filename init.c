#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "init.h"
void init(){

TCCR0A = 0;                        
TCCR0B = (1 << CS01)|(1 << CS00);

_delay_ms(10);
srand(TCNT0);

DDRD |= (1 << PD2)|(1 << PD3)|(1 << PD4);  
DDRC &= ~((1 << PC0)|(1 << PC1)|(1 << PC2));    
}
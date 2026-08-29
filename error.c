#include <avr/io.h>
#include "timer.h"
#include "error.h"

void error(){
DDRD |= (1 << PD2)|(1 << PD3)|(1 << PD4);  
DDRC &= ~((1 << PC0)|(1 << PC1)|(1 << PC2)); 
  

for(int i = 0 ; i  < 2; i++){
    PORTD |= (1 << PD2)|(1 << PD3)|(1 << PD4);
    timer(200);
    PORTD &=~((1 << PD2)|(1 << PD3)|(1 << PD4)); 
    timer(200);
    
}
    
}
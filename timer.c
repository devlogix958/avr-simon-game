#include <avr/io.h>

#include <stdint.h>
#include "timer.h"

void timer(uint16_t ms){

TCCR0A = 0;                         
TCCR0B = (1 << CS01)|(1 << CS00);  

while ( ms -- ){
TCNT0 = 0;                     

while(TCNT0 < 250);             

}
}
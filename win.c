#include <avr/io.h>
#include "win.h"
#include "timer.h"

void win(){
int a = 0;

while(a < 3){
PORTD |= (1 << PD3); 
timer(200);
PORTD &= ~(1 << PD3);
timer(200);
a++;
}

}
#include <avr/io.h>
#include <stdlib.h>

#include "randomizer.h"


int randomizer(const int num){

return rand() % num;
}

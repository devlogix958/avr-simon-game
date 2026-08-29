#include <avr/io.h>
#include "timer.h"
#include <stdbool.h>
#include "buttons.h"

bool buttons(const int err[], int round){  
int f = 0;

  while(PINC &((1 << PC0) | (1 << PC1) | (1 << PC2)));
  
  while(f < round){
        
    if(PINC &(1 << PC0)){

      timer(20);
      if(PINC &(1 << PC0)){

      if(err[f] != 0 ) return false;

        f++;
        while(PINC &(1 << PC0));
        timer(20);

      }}else if(PINC &(1 << PC1)){

      timer(20);
      if(PINC &(1 << PC1)){

      if(err[f] != 1 ) return false;

        f++;
        while(PINC &(1 << PC1));
        timer(20);

      }}else if(PINC &(1 << PC2)){

      timer(20);
      if(PINC &(1 << PC2)){

      if(err[f] != 2 ) return false;

        f++;
        while(PINC &(1 << PC2));
        timer(20);
        
      }}
      }
     
      return true;  
      }

     
   

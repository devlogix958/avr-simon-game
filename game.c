#include <avr/io.h>
#include "loading.h"
#include "randomizer.h"
#include "timer.h"
#include "leds.h"
#include "error.h"
#include "game.h"
#include <stdbool.h>
#include "buttons.h"
#include "win.h"

#define ROUND 4

void game(){
if((PINC &(1 << PC0)) && (PINC &(1 << PC1))){
       
        loading();
        int round = 1;
        bool flag = 1;  
        int err[ROUND];

        for(int i = 0; i < ROUND; i ++){
        err[i] = randomizer(3);
        }

        while(flag){
                
        timer(200);
        for(int j = 0; j < round; j++){ 
        leds(err[j]);   
        }

        if(buttons(err,round)){
        round++;
        if(round > ROUND) flag = 0;

        }else{
        error(); 
        flag = 0;  

        }
        }
       
       if(ROUND < round){
        win();
        
        }
        }
}
 
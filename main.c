#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>


void Timer(uint16_t ms){
// Settings timer   
TCCR0A = 0; // Setting mod
TCCR0B = (1 << CS01)|(1 << CS00); // Setting speed 

while ( ms -- ){
    TCNT0 = 0;//Counter update

    while(TCNT0 < 250); // 250 is the number of ticks in one millisecond

}
}


void Louding (){
    DDRD |= (1 << PD2)|(1 << PD3)|(1 << PD4);  
    DDRC &= ~(1 << PC0)|~(1 << PC1)|~(1 << PC2); 

    for(int i = 0; i <= 2; i ++){ 
    PORTD |= (1 << PD2);
    Timer(200);

    PORTD &= ~(1 << PD2);

    PORTD |= (1 << PD3); 
    Timer(200);

    PORTD &= ~(1 << PD3);

    PORTD |= (1 << PD4); 
    Timer(200);

    PORTD &= ~(1 << PD4);

    }
   

}

int Randomizer(const int num){
    Timer(100);
    int result = rand() % num;
    return result;
}

void Error(){
    DDRD |= (1 << PD2)|(1 << PD3)|(1 << PD4);  
    DDRC &= ~(1 << PC0)|~(1 << PC1)|~(1 << PC2); 
    int a = 0;

    while(a < 3){
    PORTD |= (1 << PD2)|(1 << PD3)|(1 << PD4);
    Timer(200);
    PORTD &=~(1 << PC0)|~(1 << PC1)|~(1 << PC2); 
    Timer(200);
    }
    
}

int main(void) {
    srand(TCNT0);

    DDRD |= (1 << PD2)|(1 << PD3)|(1 << PD4);  
    DDRC &= ~(1 << PC0)|~(1 << PC1)|~(1 << PC2); 
   
  
    while (1) {
        
        if((PINC &(1 << PC0)) && (PINC &(1 << PC1))){
            Louding();
        
        
         int err[4];
         for(int i = 0; i < 3; i ++){
            err[i] = Randomizer(3);
         }

        for(int j = 0; j < 3; j++){
          
            switch(err[j]){
                case 0:
                PORTD |= (1 << PD2);
                Timer(300);
                PORTD &= ~(1 << PD2);
                Timer(300);
                break;

                case 1:
                PORTD |= (1 << PD3);
                Timer(300);
                PORTD &= ~(1 << PD3);
                Timer(300);
                break;

                case 2:
                PORTD |= (1 << PD4);
                Timer(300);
                PORTD &= ~(1 << PD4);
                Timer(300);
                break;
            }

        }
        int f = 0;
        while(f < 3){
        
            if(PINC &(1 << PC0)){
            if(err[f] != 0 ) {
            Error();
            }else{
                f++;
            }}
           
            if(PINC &(1 << PC1)){
            if(err[f] != 0 ) {
            Error();
            }else{
                f++;
            }}

            if(PINC &(1 << PC2)){
            if(err[f] != 0 ) {
            Error();
            }else{
                f++;
            }}

          
            

        }

          if(f == 2){
            PORTD |= (1 << PD3); 
            Timer(500);
            PORTD &= ~(1 << PD3);
            }
            
            if(PINC &(1 << PC0)){
            PORTD |= (1 << PD2); 
            }else{
            PORTD &= ~(1 << PD2);
            }
      
            if(PINC &(1 << PC1)){
            PORTD |= (1 << PD3); 
            }else{
            PORTD &= ~(1 << PD3);
            }

            if(PINC &(1 << PC2)){
            PORTD |= (1 << PD4); 
            }else{
            PORTD &= ~(1 << PD4);}
        }
            
     
    }
   
        
}

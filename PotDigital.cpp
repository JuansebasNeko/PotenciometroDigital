#include "PotDigital.h"
#include "mbed.h"
 
PotDigital::PotDigital(PinName pin, PinName pin2, PinName pin3) : CS(pin), UD(pin2),INC(pin3) {

}
 
void PotDigital::cero() {     // Dejar en 0 el potenciometro
   CS = 1;
   INC = 1;

   CS = 0;
   wait_us(1);
   UD = 0;
   for (int n=0; n<100; n++){
            INC = 0;
            wait_us (1);
            INC=1;
            wait_us (1);
            
                       }

        INC = 1; 
        wait_us (1);
        CS = 1;
}

void PotDigital::mover(int n, int c) { //Valor del PA, Valor actual del PD  y comparar
        
        int d;
        if (n>c){ 
        d = n-c;           
        UD = 1;
        CS = 0;
        wait_us (1);
        for (int o=0; o<d; o++){
            INC = 0;
            wait_us (1);
            INC=1;
            wait_us (1);
                            }
        INC = 1; 
        wait_us (1);
        CS = 1;
                }
        
        if (n<c){ 
        d = c-n;
        UD = 0;
        CS = 0;
        wait_us (1);
        for (int o=0; o<d; o++){
            INC = 0;
            wait_us (1);
            INC=1;
            wait_us (1);
                            }
        INC = 1; 
        wait_us (1);
        CS = 1;
               }
}

int PotDigital::porcentaje(float n){
    int p; float v;
    v = n*3.3;
    p = (v*100)/3.3;
    return p;
                              }
#ifndef MBED_POTDIGITAL_H
#define MBED_POTDIGITAL_H
 
#include "mbed.h"
 
class PotDigital {
public:
    PotDigital(PinName pin, PinName pin2, PinName pin3); //Pines: CS - UD - INC
    void cero();
    void mover(int n, int c); 
    // Pasos, PD (Compara el valor actual del p. digital con la nueva entrada)

    int porcentaje(float n); 
    //Leer el analogo y volverlo porcentaje (normalizado a 3.3)
private:  
    DigitalOut CS;
    DigitalOut UD;
    DigitalOut INC;
};
 
#endif
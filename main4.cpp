/*
 * main4.cpp
 *
 *  Created on: Nov 12, 2019
 *      Author: lucas
 */

/*
 * Los numeros deben ingresarse como floats utilizando como coma el punto (.). Al
 * terminar de ingresarlo se debe finalizar con la letra "j" para que establezca como
 * nuevo intervalo.
 */

#include <stdlib.h>
#include <ctype.h>
#include "mbed.h"

Serial pc(USBTX, USBRX); // tx, rx

DigitalOut turningLed(LED1);

int main() {
    DigitalOut leds[] = {LED1,LED2,LED3,LED4};

    double interval = 0.1f;
    double aux = 0.0;
    char buffer[20];
    int index = 0;

    pc.printf("Programa iniciado!\n\r");
    while(1) {
        for (int i=0; i <= 15; i++) {
            if(pc.readable()){
               char readedChar = pc.getc();
               if(isdigit(readedChar) || readedChar == '.'){
                   buffer[index++] = readedChar;
               } else if(readedChar == 'j'){
                   buffer[index++] = '\0';
                   aux = atof(buffer);
                   if(aux != 0){
                       index = 0;
                       interval = aux;
                       pc.printf("Nuevo intervalo recibido: %g!\n\r", aux);
                   }
                   else{
                       pc.printf("No funciono!\n\r");
                   }
               }
               pc.putc(readedChar);
            }
            wait(interval);
            leds[0] = ((i & 0x1) != 0) ? 1 : 0;
            leds[1] = ((i & 0x2) != 0) ? 1 : 0;
            leds[2] = ((i & 0x4) != 0) ? 1 : 0;
            leds[3] = ((i & 0x8) != 0) ? 1 : 0;
        }
    }
}

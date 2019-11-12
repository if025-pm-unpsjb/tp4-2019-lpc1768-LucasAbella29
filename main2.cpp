/*
 * main2.cpp
 *
 *  Created on: Nov 12, 2019
 *      Author: lucas
 */

#include "mbed.h"

Serial pc(USBTX, USBRX); // tx, rx

DigitalOut turningLed(LED1);

int main() {
    DigitalOut leds[] = {LED1,LED2,LED3,LED4};
    int selectedLed = 0;

    pc.printf("Programa iniciado!\n");
    while(1) {
        if(pc.readable()){
            char readedChar = pc.getc();
            if(readedChar >= '1' && readedChar <= '4'){
                selectedLed = readedChar - '1';
            }
            else{
                pc.putc(readedChar);
            }
        }
        wait(0.25);
        for(int i = 0;i < 4; i++){
            if(i == selectedLed){
                leds[i] = (leds[i] == 1) ? 0 : 1;
                continue;
            }

            leds[i] = 0;
        }
    }
}



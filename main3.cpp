/*
 * main3.cpp
 *
 *  Created on: Nov 12, 2019
 *      Author: lucas
 */

#include "mbed.h"

PwmOut led(LED1);
DigitalOut led4(LED4);

int main() {
    float dutyCycle = 0.0f;
    float aux = 0.05f;

    while(1){
        led.write(dutyCycle);      // 50% duty cycle, relative to period
        wait(0.1);

        dutyCycle += aux;

        if(dutyCycle >= 1.0f){
            led4 = 1;
            aux = -0.05f;
        }

        if(dutyCycle <= 0.0f){
            led4 = 0;
            aux = 0.05f;
        }
    }
}

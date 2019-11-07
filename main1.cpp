/*
 * main1.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: lucas
 */

#include "mbed.h"

Serial pc(USBTX, USBRX); // tx, rx

int main() {
    pc.printf("Programa iniciado!\n");
    while(1) {
        if(pc.readable()){
            char readedChar = pc.getc();
            if(readedChar == 'h'){
                pc.printf("¡hola!");
            }
            else{
                pc.putc(readedChar);
            }
        }
    }
}

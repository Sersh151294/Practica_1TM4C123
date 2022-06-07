/*
 * GPIO.c
 *
 *  Created on: 19 may 2022
 *      Author: Lenovo
 */

#include "lib/include.h"
extern void Configurar_GPIO_D(void)
{
    SYSCTL->RCGCGPIO |=  (1<<1);
       while((SYSCTL->PRGPIO&0X00000008)==0){;}
       //SALIDAS
                       // F1        F0
       GPIOD->DIR |= (0<<7) | (1<<1) | (1<<0);
       GPIOD->PUR |= (1<<7); //ESTADO EN ALTO


       //FUNCIONES ALTERNATIVAS
       GPIOD->AFSEL |= 0X00;
       //TABLA CON GPIOCTL
       GPIOD->PCTL |= 0X00;
}


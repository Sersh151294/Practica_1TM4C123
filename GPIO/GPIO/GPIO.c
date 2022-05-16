/*
 * GPIO.c
 *
 *  Created on: 7 abr 2022
 *      Author: Cruz Bautista Sergio Emmanuel
 */
#include "lib/include.h"
extern void Configurar_GPIO_C(void)
{
    //OPERACIONES CON BITWISE
                    //     N      J      F      B
    SYSCTL->RCGCGPIO |=  (1<<1);
    while((SYSCTL->PRGPIO&0X00000004)==0){;}
    //SALIDAS
                    // F1        F0
    GPIOC->DIR |= (0<<7) | (1<<1) | (1<<0);
    GPIOC->PUR |= (1<<7); //ESTADO EN ALTO


    //FUNCIONES ALTERNATIVAS
    GPIOD->AFSEL |= 0X00;
    //TABLA CON GPIOCTL
    GPIOC->PCTL |= 0X00;
    //HABILITACION COMO SEÑAL DIGITAL
    GPIOC_AHB->DEN  |= (1<<7) | (1<<1) | (1<<0);


    //HABILITAR INTERRUPCIONES
    GPIOC->IM|= (0<<7)|(0<<0);
    GPIOC->IS |= (0<<7)|(0<<0);
    GPIOC->IBE |= (0<<7)|(0<<0);
    GPIOC->IEV |= (1<<7)|(1<<0);
    GPIOC->IM |=(1<<7)|(1<<0);

    //PORTC -----
    NVIC->IP[0] = (NVIC->IP[12]&0X00FFFFFF) | (0X8000000);
    NVIC->ISER[0] = 0X8;

}

extern void Configurar_BOTONES (void)
{
    //OPERACIONES CON BITWISE
    SYSCTL->RCGCGPIO |= (1<<8);
    while((SYSCTL->PRGPIO&0X00000100)==0){;}
    //ENTRADAS
    GPIOC_AHB->DIR |= (0<<1) | (0<<0);
    GPIOC_AHB->PUR |= (1<<1) | (1<<0); //ESTADO EN ALTO
    //FUNCIONES ALTERNATIVAS
    GPIOC_AHB->AFSEL |= 0X00;

    //TABLA CON GPIOCTL
    GPIOC_AHB->PCTL |= 0X00;
    //HABILITACION COMO SEÑAL DIGITAL

    GPIOC_AHB->DEN  |= (1<<1) | (1<<0);


}

extern void Configurar_LEDS(void)
{
    //OPERACIONES CON BITWISE
                    //     N       F
    SYSCTL->RCGCGPIO |= (1<<4)|(1<<5);
    while((SYSCTL->PRGPIO&0X00000010)==0){;}
    //SALIDAS
    GPIOF_AHB->DIR |= (1<<4) | (1<<0);
    GPIOA->DIR |= (1<<1) | (1<<0);

    //FUNCIONES ALTERNATIVAS
    GPIOA->AFSEL |= 0X00;
    GPIOF_AHB->AFSEL |= 0X00;

    //TABLA CON GPIOCTL
    GPIOA->PCTL |= 0X00;
    GPIOF_AHB->PCTL |= 0X00;
    //HABILITACION COMO SEÑAL DIGITAL
    GPIOA->DEN  |= (1<<1) | (1<<0);
    GPIOF_AHB->DEN  |= (1<<4) | (1<<0);

}

extern void  GPIOC_ISR(void)
{
    uint32_t i;
    GPIOC->DATA = (1<<0);  // LED EXTERNO C0
    for(i=0;i<<10;i++){}
    GPIOC->DATA = (0<<0);  // LED EXTERNO C0
    for(i=0;i<<10;i++){}


}



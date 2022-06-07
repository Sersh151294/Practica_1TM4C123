/*
 * PWM.c
 *
 *  Created on: 19 may 2022
 *      Author: Lenovo
 */

#include "../lib/include.h"
extern void Configurar_PWM_0(void)

{
    SYSCTL->RCGCPWM |= 1<<0;
    while ((SYSCTL->PRPWM&0X01)==0){};//MÓDULO HABILITADO

    SYSCTL->RCGC0(0x0);
    SYSCTL->RCGC2(0x0);

    GPIOE->AFSEL |=0x59;
    GPIOE->PCTL (0x60);

/**
    PWM0->CTL = (0x0000.0000);
    PWM0->_0_GENA = (0x0000.008C);
    PWM0->_0_GENB = (0x0000.080C);

    PWM0->_0_LOAD = (0x0000.018F);
    PWM0->_0_CMPA = (0x0000.012B);
    PWM0->_0_CMPB = (0x0000.0063);
    PWM0->CTL = (0x0000.0001);
    PWM0->ENABLE = (0x0000.0003);*/



}



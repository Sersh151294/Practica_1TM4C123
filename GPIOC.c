/*
 * GPIOC.c
 *
 *  Created on: 28 abr 2022
 *      Author: Lenovo
 */


extern void Configurar_GPIO_C(void);
{
    //OPERACIONES CON BITWISE

        SYSCTL->RCGCGPIO |=  (1<<3);
        while((SYSCTL->PRGPIO&0X00000004)==0){;}
        //SALIDAS
                        // F1        F0
        GPIOC->DIR   |= (0<<7) | (1<<1) | (1<<0);
        GPIOC->PUR   |= (1<<7) //ESTADO EN ALTO


        //FUNCIONES ALTERNATIVAS
        GPIOC->AFSEL |= 0X00;
        //TABLA CON GPIOCTL
        GPIOC->PCTL  |= 0X00;
        //HABILITACION COMO SEÑAL DIGITAL
        GPIOC->DEN   |= (1<<7) | (1<<1) | (1<<0);


        //HABILITAR INTERRUPCIONES
        GPIOC->IM  |= (0<<1)|(0<<0);
        GPIOC->IS  |= (0<<1)|(0<<0);
        GPIOC->IBE |= (0<<1)|(0<<0);
        GPIOC->IEV |= (0<<1)|(0<<0);
        GPIOC->IM  |= (1<<1)|(1<<0);

        //PORTC -----> 51             51504948
        NVIC->IP[0] = (NVIC->IP[12]&0X0OFFFFFF) | (0X80000000);
        NVIC->ISER[0] = 0X8;

}

extern void  GPIOC_ISR(void);
{
    uint32_t i;
    GPIOC->DATA = (1<<0);  // LED EXTERNO C0
    for(i=0;i<<1000000;i++){}
    GPIOC->DATA = (0<<0);  // LED EXTERNO C0
    for(i=0;i<<1000000;i++){}


}


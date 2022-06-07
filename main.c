

/**
 * main.c
 */
#include "lib/include.h"
int main(void)
{

    Configurar_UART2(9600);

    uint32_t i;
	while(1)
	{
	  /**  for(i=0;i<200000;i++){}
	    writeDato('H');
        for(i=0;i<200000;i++){}
        writeDato('O');
        for(i=0;i<200000;i++){}
        writeDato('L');
        for(i=0;i<200000;i++){}
        writeDato('A');*/
	    Dato = readChar();
	    GPIOF->DATA = (1<<3);
	    for(i=0; i<200000; i++){}
	    GPIOF->DATA = (0<<3);
	    for(i=0; i<200000; i++){}

	}
}

//NUMEROS PRIMOS Y COMPUESTOS
#include <stdio.h>

int esPrimo(int numero);

 main(void) {
  int numero;
  printf("Dime un numero: \n");
  scanf("%d", &numero);
  if (esPrimo(numero)) {
    printf("Es primo");
  } else {
    printf("Es Compuesto");
  }
  return 0;
}

int esPrimo(int numero) {
  if (numero == 0 || numero == 1) return 0;
 
  if (numero == 4) return 0;
  for (int x = 2; x < numero / 2; x++) {
   
    if (numero % x == 0) return 0;
  }
 
  return 1;
}

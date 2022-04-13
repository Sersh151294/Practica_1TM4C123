//SUMA DE NUMEROS DE 16 BITS
#include <stdio.h>

void operacion (float *n1, float *n2);

int main(){
    
    float num1, num2;
    printf("Dame el primer numero:\n");
    scanf("%f",&num1);
    printf("Dame el segundo numero:\n");
    scanf("%f",&num2);
    operacion (&num1, &num2);
}

void operacion(float *n1, float *n2){
    float suma;
    
    suma=*n1+*n2;
    
    printf("El Resultado de la Suma es: %f",suma);
}
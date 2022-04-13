#include <stdio.h>
int main() {
   int  b=2, a;
   printf("Ingrese un numeros: \n");
   scanf("%d", &a);
   if((a % b == 0) && (b!=0))
   {
      printf("%d es Divisible entre %d",a,b);
   }else{
      printf("%d NO es Divisible entre %d",a,b);
   }

   return 0;
   }
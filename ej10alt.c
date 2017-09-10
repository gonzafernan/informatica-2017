//
//
//Escribir un programa que calcule la siguiente ecuación:
//
//

#include <stdio.h>

//int main(){
   int i, j, k=0;
   float sum=0;
   for (i=0; i<=100; i++){
      for (j=0; j<=100; j++){
         k=k+1;
         if (i%2!=0 || j%2!=0 || i==0 || j==0){
            continue;
         } else {
            sum=sum+(i*j)/(i+j);
         }
      }
   } printf("El resultado de la sumatoria es igual a %f\nContador= %d\n", sum, k);
return 0;
}

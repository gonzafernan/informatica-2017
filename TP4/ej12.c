//
// Escriba una función que reciba como parámetro una matriz de M x N elementos, y calcule
// la transpuesta de la matriz. El resultado debe ser almacenado en la misma matriz (es decir
// que no se debe reservar memoria para el resultado ni devolver ningún apuntador)
//
//

#include <stdio.h>
#include <stdlib.h>

void ej12(double*u, int M, int N){
   double paso;
   int i, j;
   for (i=1; i<=M; i++){
      for (j=i; j<=N; j++){
         paso=u[i-1,j-1];
         u[i-1,j-1]=u[j-1,i-1];
         u[j-1,i-1]=paso;
      }
   }
}

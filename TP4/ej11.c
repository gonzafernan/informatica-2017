//
//  ej11.c
//  Informatica-2017
//  Repita el ejercicio (5) para el caso de una matriz de M x N elementos
//

#include <stdio.h>
#include <stdlib.h>

void ej11(double **matriz,double M,double N){
  int i,j;
  for (i=0;i<M;i++){
    for (j=0;j<N;j++){
      printf("%lf ",matriz[i][j]);
    }
    printf("\n");
  }
}

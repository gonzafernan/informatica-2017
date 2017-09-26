//
//  ej10.c
//  Informatica-2017
//  Repita el ejercicio (4) para el caso de una matriz de M x N elementos
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ej10(double **matriz,int M,int N){
  int i,j;
  for (i=0;i<M;i++){
    for (j=0;j<N;j++){
      matriz[i][j]=(double)rand()/(double)rand();
    }
  }
  return matriz;
}

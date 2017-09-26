//
//  ej9.c
//  Informatica-2017
//  Repita el ejercicio (3) para el caso de una matriz de M x N elementos
//

#include <stdio.h>
#include <stdlib.h>

double **ej9(double **matriz,double M,double N,double s){
  int i,j;
  for (i=0;i<M;i++){
    for (j=0;j<N;j++){
      matriz[i][j]=s*matriz[i][j];
    }
  }
  return matriz;
}

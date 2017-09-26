//
//  ej8.c
//  Informatica-2017
//  Escriba una función que reciba como parámetros 2 matrices A y B de MxN y NxP elementos tipo double,
//  respectivamente, cree una nueva matriz C de MxP elementos dinámicamente,
//  y calcule (almacenando el resultado en C) el producto matricial.
//  La función debe devover el apuntador a C (que fue creada en la misma función).
//  Valide los tamaños de las matrices
//

#include <stdio.h>
#include <stdlib.h>
#include "ejercicios.h"

double **ej8(double **matrizA,double **matrizB,double M,double N, double P){
  double **matrizC,sum=0;
  matrizC=ej7(M,P);
  int i,j,k;
  for (k=0;k<M;k++){
    for (i=0;i<P;i++) {
      for (j=0;j<N;j++){
        sum=sum+matrizA[k][j]*matrizB[j][i];
      }
      matrizC[k][i]=sum;
      sum=0;
    }
  }
  ej11(matrizC,M,P);
  return matrizC;
}

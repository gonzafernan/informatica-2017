
#include <stdio.h>
#include <stdlib.h>

/*Escriba una función que reciba como argumento un par de entero M y N,
cree una matriz de MxN de tipo double dinámicamente (calloc) y
devuelva un apuntador con la direccón de memoria del arreglo creado*/

double **ej7(double M, double N){
  int i;
  double **mat;
  mat=calloc(M,sizeof(double*));
  for (i=0;i<N;i++){
    mat[i]=calloc(N,sizeof(double));
  }
  return mat;
}

//
//  ej4.c
//  Informatica-2017
//  Escriba una función que reciba como argumento un vector de N elementos double
//  (donde N puede ser variable) y que genere valores aleatorios para el mismo.
//  Asegurese de generar valores con cifras decimales
//  (es decir que no sean simplemente enteros).
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ejercicios.h"

void ej4(double *u,int n){
  int i;
  printf("Vector con valores random:\n");
  for (i=0;i<n;i++) {
    u[i]=(double)rand()/(double)rand();
  }
  ej5(u,n);
}

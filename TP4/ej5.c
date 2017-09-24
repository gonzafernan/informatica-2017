//
//  ej5.c
//  Informatica-2017
//  Escriba una función que reciba un vector de N elementos (N variable)
//  e imprima por pantalla el vector en un formato legible para el ser humano
//  (ej: utilizando notación algebraica: “ (v1, v2, ..., vn) ”)
//

#include <stdio.h>
#include <stdlib.h>

void ej5(double *u,num){
  int i;
  printf("Vector en notación algebraica:\n(");
  for (i=0;i<num;i++){
    if (i<num-1){
      printf("%lf, ",u[i]);
    } else {
      printf("%lf)\n",u[i]);
    }
  }
}

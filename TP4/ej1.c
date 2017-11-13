//
//  ej1.c
//  Informatica-2017
//  Escriba una función que reciba como argumento un entero N,
//  cree un vector de N elementos de tipo double dinámicamente (utilizando la función malloc),
//  y devuelva un apuntador con la dirección de memoria del arreglo creado.
//

#include <stdio.h>
#include <stdlib.h>

double *ej1(int num){
  int i;
  double *v;
  v=calloc(num,sizeof(double));
  //  Verificación de malloc()
  if (v==NULL){
    printf("ERROR al reservar la memoria.\n");
  }
  //printf("%p\n",v);
  return v;
}


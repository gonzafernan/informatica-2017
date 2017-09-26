//
//  ej2.c
//  Informatica-2017
//  Escriba una función que reciba como parámetros 2 vectores u y v de N elementos tipo double (donde N puede ser variable),
//  cree un nuevo vector w de N elementos dinámicamente,
//  y calcule (almacenando el resultado en w) el producto vectorial u x v.
//  La función debe devolver el apuntador a w (que fue creado en la misma función).
//

#include <stdio.h>
#include <stdlib.h>
#include "ejercicios.h"

double *ej2(double *u,double *v,int num){
  if (num==3) {
    int i;
    double *w=ej1(num);
    w[0]=u[1]*v[2]-u[2]*v[1];
    w[1]=u[2]*v[0]-u[0]*v[2];
    w[2]=u[0]*v[1]-u[1]*v[0];
    return w;
  } else {
    printf("ERROR: Producto vectorial definido solo para 3 dimensiones.\n");
    return 0;
  }
}

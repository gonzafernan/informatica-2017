//
//  ej3.c
//  Informatica-2017
//  Escriba una función que reciba un vector de N elementos double
//  (donde N pued ser variable) y un escalar double s,
//  y escale el mismo arreglo utilizando el factor s
//  (es decir, no debe devolver un puntero ni crear otro arreglo)
//

#include <stdio.h>
#include <stdlib.h>

void ej3(double *vec,double s,int num){
  int i;
  for(i=0;i<num;i++){
    vec[i]=vec[i]*s;
  }
  printf("El vector escalado por %lf es:\n",s);
  ej5(vec,num);
}

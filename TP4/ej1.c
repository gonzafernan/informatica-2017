//
//  ej1.c
//  Informatica-2017
//  Escriba una función que reciba como argumento un entero N,
//  cree un vector de N elementos de tipo double dinámicamente (utilizando la función malloc),
//  y devuelva un apuntador con la dirección de memoria del arreglo creado.
//

#include <stdio.h>
#include <stdlib.h>

int *ej1(int num){
  int i,*v;
  v=(int *)calloc(num,sizeof(int));
  //  Verificación de malloc()
  if (v==NULL){
    printf("ERROR al reservar la memoria.\n");
  }
  //  Vector de ceror (No es necesario)
  for (i=0;i<num;i++){
    *(v+i)=0;
  }
  printf("%p\n",v);
  return v;
}


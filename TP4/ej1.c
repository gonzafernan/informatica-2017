//
//  main.c
//  Informatica-2017
//  Escriba una función que reciba como argumento un entero N,
//  cree un vector de N elementos de tipo double dinámicamente (utilizando la función malloc),
//  y devuelva un apuntador con la dirección de memoria del arreglo creado.
//

#include <stdio.h>
#include <stdlib.h>

int ej1(){
  float num;
  int vector[0],*v;
  printf("Ingrese el valor de un entero:\n");
  scanf("%f",&num);
  v=malloc(sizeof(vector));
  printf("%p",v);
  return 0;
}

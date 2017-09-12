//
//  ej17.c
//  Informatica-2017
//  Escriba un programa que calcule el producto vectorial de 2 vectores en R3 utilizando structs
//  pare representar los vectores
//

#include <stdio.h>

int ej17(){
//creacion de la estructura de vector en R3
  struct vectorR3{
    float x;
    float y;
    float z;
  };
struct vectorR3 v1,v2,v3;
//asignacion de las componentes de los vectores
printf("Ingrese las 3 componentes del vector 1 en orden \n");
scanf("%f %f %f",&v1.x,&v1.y,&v1.z);
printf("Ingrese las 3 componentes del vector 2 en orden \n");
scanf("%f %f %f",&v2.x,&v2.y,&v2.z);
//calculo del producto vectorial con un vector v3 como resultado
v3.x= (v1.y*v2.z)-(v1.z*v2.y);
v3.y= (v1.z*v2.x)-(v1.x*v2.z);
v3.z= (v1.x*v2.y)-(v1.y*v2.x);
printf("El vector resultado del producto vectorial es: (%f,%f,%f)\n",v3.x,v3.y,v3.z);
  
return 0;
}

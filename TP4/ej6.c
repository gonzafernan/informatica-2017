//
//  ej6.c
//  Informatica-2017
//  Escriba un programa que:
//  a. lea por teclado un entero N,
//  b. cree 4 vectores de N elementos double dinámicamente con valores aleatorios,
//  c. lea por teclado un factor de escala double
//  d. escale 2 de los vectores generados en (b) por el factor s
//  e. calcule el producto vectorial de los vectores de a pares, el primero por el segundo y
//  el tercero por el cuarto, generando como resultado 2 vectores u y v
//  f. calcule el producto vevtorial de u x v
//  g. muestre todos los resultados intermedios por pantalla
//  h. Libere la memoria dinámica utilizada
//

#include <stdio.h>
#include <stdlib.h>
#include "ejercicios.h"

void ej6(){
  //  Inciso a:
  int N;
  printf("Introduzca un entero N:\n");
  scanf("%d",&N);
  printf("a) Entero introducido: %d\n",N);
  //  Inciso b:
  printf("b) ", );
  double *vec1,*vec2,*vec3,*vec4;
  vec1=ej1(N);  //Vector 1
  ej4(vec1,N);
  vec2=ej1(N);  //Vector 2
  ej4(vec2,N);
  vec3=ej1(N);  //Vector 3
  ej4(vec3,N);
  vec4=ej1(N);  //Vector 4
  ej4(vec4,N);

  //  Inciso c:
  double s;
  printf("Factor de escalamiento:\n");
  scanf("%lf",&s);

  //  Inciso d:
  ej3(vec1,s,N);
  ej3(vec2,s,N);

  //  Inciso e:
  double *u,*v;
  u=ej2(vec1,vec2,N);
  v=ej2(vec3,vec4,N);

  //  Inciso f:
  double *ans;
  ans=ej2(u,v,N);

  //  Inciso g:
  printf("c) Factor de escalamiento: %lf\n",s);
  printf("d) Primer vector escalado:\n");
  ej5(vec1,N);
  printf("   Segundo vector escalado:\n");
  ej5(vec2,N);
  printf("e) Vector u:\n");
  ej5(u,N);
  printf("   Vector v:\n");
  ej5(v,N);
  printf("f) Producto vectorial u x v:\n");
  ej5(ans,N);

  //  Inciso h:
  free(vec1);
  free(vec2);
  free(vec3);
  free(vec4);

}

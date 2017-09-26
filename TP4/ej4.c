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

void ej4(double *u,int n){
  int i;
  //srand:generador de semilla. Esto nos permite establecer el método de generación de los números random.
  //time: esta semilla utiliza el tiempo para establecer los random. Por esto 2 vectores generados consecutivamente no se repiten.
  //NULL: inicializa la función time en 0.
  //drand48: permite asignar valores random.
  //48: Para valores aleatorios con decimales.
  srand48(time(NULL)); //Para que en cada ejecucion del programa los valores aleatorios sean distintos
  printf("Vector con valores random:\n");
  for (i=0;i<n;i++) {
    u[i]=drand48()*(20.0-10.0)+10.0;
    printf("%lf\n",u[i]);
  }
  /*
  int i; 
  srand (time(NULL));
  for(i=0;i<n;i++){
    u[i]=(double)rand()/(double)rand();
    // printf("%lf ",u[i]); //después decidimos si imprime por pantalla los valores del vector o no 
  } //printf("\n");
  
  }

  */
  
}

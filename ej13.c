/*
Escriba un programa que
a. Genere un vector con valore aleatorios enteros
b. Recorra el vector y guarde el promedio de los valores en una variable
c. Encuentre el menor de los elementos
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ej13(){
   //srand:generador de semilla. Esto nos permite establecer el método de generación de los números random.
   //time: esta semilla utiliza el tiempo para establecer los random. Por esto 2 vectores generados consecutivamente no se repiten.
   //NULL: inicializa la función time en 0.
   //rand: permite asignar valores random.
   srand(time(NULL));
   int tam, i, j, sum=0, min;
   float prom;
   printf("Ingrese el tamaño del vector\n");
   scanf("%d",&tam);
   int V[tam];
   //Asignación del vector random
   printf("Vector Random\n");
   for (i=1; i<=tam; i++){
      V[(i-1)]=rand();
      printf("Elemento %d = %d\n",i,V[(i-1)]);
   } //Promedio y menor elemento
   for (j=1; j<=tam; j++){
      sum=sum+V[(j-1)];
      if (j==1){
         min=V[(j-1)];
      } else if (V[j-1] < min){
         min=V[(j-1)];
      }
   } prom=sum/tam;
   printf("El promedio es igual a %f\nEl menor de los elementos es %d",prom,min);
return 0;
}

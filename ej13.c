//
//  ej13.c
//  Informatica-2017
//  Escriba un programa que
//  a. Genere un vector con valore aleatorios enteros
//  b. Recorra el vector y guarde el promedio de los valores en una variable
//  c. Encuentre el menor de los elementos
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ej13(){
    //Declaración de variables enteras
    int largo,i;
    printf("Ingrese cantidad de componentes del vector:\n");
    scanf("%d",&largo);
    
    //Declaración de variables long
    long vector[largo],menor;
   //srand:generador de semilla. Esto nos permite establecer el método de generación de los números random.
   //time: esta semilla utiliza el tiempo para establecer los random. Por esto 2 vectores generados consecutivamente no se repiten.
   //NULL: inicializa la función time en 0.
   //rand: permite asignar valores random.
    srand(time(NULL)); //Para que en cada ejecucion del programa los valores aleatorios sean distintos
    
    //Bucle para cargar el vector con el largo asignado con numeros aleatorios
    for (i=1;i<=largo;i++){
        vector[i-1]=rand();
    }
    
    //Bucle para calcular el promedio
    float sum=0;
    for (i=1;i<=largo;i++){
        sum= vector[i-1]+sum;
    }
    float prom=sum/largo;
    
    //Bucle para buscar menor componente
    menor=vector[0];
    for (i=1;i<=largo;i++){
        if(vector[i]<=menor){
            menor=vector[i];
        }
    }
    
    //Resultados
    printf("El vector de números aleatorios es: \n");
    printf("[");
    for (i=1;i<=largo;i++){
        if (i==largo){
            printf("%ld]\n",vector[i-1]);
        } else {
            printf("%ld, ",vector[i-1]);
        }
    }
    printf("El promedio de las componentes del vector es: %f\n",prom);
    printf("La menor de las componentes del vector es: %ld\n",menor);
    return 0;
}

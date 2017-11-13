#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ejercicios.h"

typedef int boolean;
#define TRUE 1
#define FALSE 0
boolean bandera=TRUE;
int main() {
   int seccion,num;
   double s;
   char resp;
   //srand:generador de semilla. Esto nos permite establecer el método de generación de los números random.
   //time: esta semilla utiliza el tiempo para establecer los random. Por esto 2 vectores generados consecutivamente no se repiten.
   //NULL: inicializa la función time en 0.
   srand(time(NULL)); //Para que en cada ejecucion del programa los valores aleatorios sean distintos
   do{
      printf("Ingrese sección del trabajo práctico a ejecutar, siendo:\n  1- Ejercicio 6: Donde se reúnen los ejercicios del 1 al 5 en un solo procedimiento.\n  2- Ejercicio 13: Donde se reúnen los ejercicios del 7 al 12 en un solo procedimiento.\n  3- Sección sucesión de Fibonacci (RECURSIÓN).\n");
       scanf(" %d",&seccion);
       switch (seccion) {
               case(1):
               //////////////////////////////////////////////////////////////////////////////
               //              Sección para ejercicios del 1 al 6 (ARREGLOS 1D)
               // Ejercicio 6
               ej6();

               break;
               case(2):
               //////////////////////////////////////////////////////////////////////////////
               //Sección del trabajo práctico donde se trabaja con los ejercicios 7 al 13 (ARREGLOS 2D)
               //(Se creo un ejercicio similar al ejercicio 6, pero con matrices)
               ej13();

               break;
               case(3):
               //////////////////////////////////////////////////////////////////////////////
               //                Sección sucesión de Fibonacci (RECURSIÓN)
                 ej14();
               break;
           default:
               printf("ERROR: No existe tal sección.\n");
       } char resp;
         printf("\nDesea continuar? Y/N\n");
         scanf(" %c",&resp);
      switch (resp){
         case('y'):
         case('Y'):
            break;
         default:
            bandera=FALSE;
         }
}   while(bandera);

return 0;
}

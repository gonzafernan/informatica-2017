/*
Ejercicio 15 - Informática 2017

Un sistema en un parque eólico predice la producción de energía del día siguiente Dt+1. La
predicción se realiza promediando la producción de energía en el día Dt, y luego
promediando esta producción promedio en Dt con la producción promedio de los 20 días
anteriores. El precio de venta del MW es de U$D 100. Utilice una matriz (arreglo 2D) como
estructura de datos
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int boolean;
#define TRUE 1
#define FALSE 0

int ej15(){
   /*Suponiendo que se toman las mediciones diarias cada 6 horas (después lo podemos cambiar) y que
   el usuario del programa sólo tiene que ingresar los valores de la nueva medición.
   Los valores anteriores ya van a estar guardados en la matriz A(5x23) en las primeras 20 columnas,
   en la columna 21 se irán colocando los valores del día actual Dt y en la 23 la predicción para
   el día siguiente Dt+1.
   Para la próxima iteración:
   En la columna 22 se va a guardar la predicción que se había hecho para el día Dt+1 y los valores
   de las primeras 21 se corren uno a la izquierda eliminando la primera. Los nuevos valores se
   colocan en la columna 21 y así sucesivamente.
   Al final de cada día coloca una pregunta para seguir utilizando el programa o cortarlo.
   */
printf("Por favor maximize el tamaño de la consola para poder visalizar correctamente la matriz\n");
/*Inicialización:
  Generación de una matriz inicial de 4x20 con random limitado entre 10 y 60 ( rand() %51 +10) y una
  fila 5 con el promedio de las filas superiores. Asignación de ceros a la columna 21 de valor esperado*/
   int A[5][23];
   int sum[20], sum2[5];
   int i, j, ceros, ceros2, ceros3, hs;
   for (ceros=1; ceros<=20; ceros++){
      sum[ceros-1]=0;
   }
   srand(time(NULL));
   for (i=1; i<=20; i++){
      for (j=1; j<=4; j++){
         A[j-1][i-1]=10+rand()%51;
         sum[i-1]=sum[i-1]+A[j-1][i-1];
         A[j-1][21]=0;
      } A[4][i-1]=sum[i-1]/4;
   }
   boolean band=TRUE;

//Ciclo iterativo do while
    while (band) {
//Asignación de los valores del día actual (columna 21) y promedio de estos en A(5x21)
      A[4][20]=0;
      for (i=1; i<=4; i++){
         hs=(i-1)*6;
         printf("Ingrese el valor de producción correspondiente a las %d:00 hs ==>  ",hs);
         scanf("%d",&A[i-1][20]);
         A[4][20]=A[4][20]+A[i-1][20];
      } A[4][20]=A[4][20]/4;
//Asignación de la predicción (columna 23)
      for (ceros2=1; ceros2<=5; ceros2++){
         sum2[ceros2-1]=0;
      }
      for (i=1; i<=5; i++){
         for (j=1; j<=21; j++){
            sum2[i-1]=sum2[i-1]+A[i-1][j-1];
         } A[i-1][22]=sum2[i-1]/21;
      }
      
/*Matriz en pantalla*/
      for (i=1; i<=6; i++){
         for (j=1; j<=23; j++){
            if (i==1){
               if (j==21){
                  printf("Actual ");
               } else if (j==22){
                  printf("Espera ");
               } else if (j==23){
                  printf("Predic ");
               } else if (j<10){
                  printf("Dia%d  ",j);
               } else if (j>=10 && j<21){
                  printf("Dia%d ",j);
               }
            } else if (j==23){
               printf("    %d",A[i-2][j-1]);
            } else {
               printf("  %d  ",A[i-2][j-1]);
            }
         } printf("\n");
      }
//Continuar?? y Reemplazo de variables
      char resp;
      printf("Desea salir del sistema?? Y / any other key\n");
      scanf(" %c",&resp);
      //Bloque condicional switch
      switch (resp) {
         case 'Y':
         case 'y':
            band=FALSE;
            break;
         default:
         /*if (resp=='y' || resp=='Y'){
            band=0;
         } else{*/
            for (i=1; i<=5; i++){
               for (j=2; j<=23; j++){
                  if (j==22){
                     A[i-1][20]=0; //La nueva columna de día actual se hace 0
                  } else if (j==23){
                     A[i-1][j-2]=A[i-1][j-1]; //Traslado de la columna 23 (predicción) a la 22 (esperada)
                     A[i-1][22]=0; //La nueva columna de predicción se hace 0
                  } else {
                     A[i-1][j-2]=A[i-1][j-1]; //Traslado de las variables viejas a la izquierda.
                  }
               }
            } break;
         }
   }
return 0;   
}

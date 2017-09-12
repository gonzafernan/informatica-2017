/*
Ejercicio 15 - Informática 2017

Un sistema en un parque eólico predice la producción de energía del día siguiente Dt+1. La
predicción se realiza promediando la producción de energía en el día Dt, y luego
promediando esta producción promedio en Dt con la producción promedio de los 20 días
anteriores. El precio de venta del MW es de U$D 100. Utilice struct como estructura de datos
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int boolean;
#define TRUE 1
#define FALSE 0

int ej16(){
printf("Por favor maximize el tamaño de la consola para poder visalizar correctamente la matriz"\n);
/*Inicialización:
  Generación de una matriz base de 5x23 utilizando 4 vectores struct vec y 1 vector struct vecprom*/
   int i, j, q, c, c1, c2, c3, c4, c5, s, hs;
   struct vec {
      int x[21];
      float y[2];
   };
   struct vec v1, v2, v3, v4;
   struct vecprom {
      float x[23];
   };
   struct vecprom vp1;

   srand(time(NULL));
   for (i=1; i<=20; i++){
      v1.x[i-1]=10+rand()%51;
      v2.x[i-1]=10+rand()%51;
      v3.x[i-1]=10+rand()%51;
      v4.x[i-1]=10+rand()%51;
      vp1.x[i-1]=(v1.x[i-1]+v2.x[i-1]+v3.x[i-1]+v4.x[i-1])/4;
   }

   boolean band=TRUE;

/*Ciclo iterativo do while*/
    while (band) {
/*Asignación de los valores del día actual (columna 21) y promedio de estos en A(5x21)*/
      for (q=1; q<=4; q++){
         hs=(q-1)*6;
         printf("Ingrese el valor de producción correspondiente a las %d:00 hs ==>  ",hs);
         if (q==1){
            scanf("%d",&v1.x[20]);
         } else if (q==2){
            scanf("%d",&v2.x[20]);
         } else if (q==3){
            scanf("%d",&v3.x[20]);
         } else if (q==4){
            scanf("%d",&v4.x[20]);
         }
      } vp1.x[20]=(v1.x[20]+v2.x[20]+v3.x[20]+v4.x[20])/4;

/*Asignación de la predicción (columna 23)*/
      v1.y[1]=0;
      v2.y[1]=0;
      v3.y[1]=0;
      v4.y[1]=0;
      vp1.x[22]=0;
      for (j=1; j<=21; j++){
         v1.y[1]=v1.y[1]+v1.x[j-1];
         v2.y[1]=v2.y[1]+v2.x[j-1];
         v3.y[1]=v3.y[1]+v3.x[j-1];
         v4.y[1]=v4.y[1]+v4.x[j-1];
         vp1.x[22]=vp1.x[22]+vp1.x[j-1];
      }  v1.y[1]=v1.y[1]/21;
         v2.y[1]=v2.y[1]/21;
         v3.y[1]=v3.y[1]/21;
         v4.y[1]=v4.y[1]/21;
         vp1.x[22]=vp1.x[22]/21;

/*Matriz en pantalla*/
      for (c=1; c<=23; c++){
         if (c==21){
               printf("Actual ");
            } else if (c==22){
               printf("Espera ");
            } else if (c==23){
               printf("Predic ");
            } else if (c<10){
               printf("Dia%d   ",c);
            } else if (c>=10 && c<21){
               printf("Dia%d  ",c);
            }
      } printf("\n");
      for (c1=1; c1<=23; c1++){
         if (c1==23 || c1==22){
            printf(" %.2f ",v1.y[c1-22]);
         } else {
            printf(" %d    ",v1.x[c1-1]);
         }
      } printf("\n");
      for (c2=1; c2<=23; c2++){
         if (c2==23 || c2==22){
            printf(" %.2f ",v2.y[c2-22]);
         } else {
            printf(" %d    ",v2.x[c2-1]);
         }
      } printf("\n");
      for (c3=1; c3<=23; c3++){
         if (c3==23 || c3==22){
            printf(" %.2f ",v3.y[c3-22]);
         } else {
            printf(" %d    ",v3.x[c3-1]);
         }
      } printf("\n");
      for (c4=1; c4<=23; c4++){
         if (c4==23 || c4==22){
            printf(" %.2f ",v4.y[c4-22]);
         } else {
            printf(" %d    ",v4.x[c4-1]);
         }
      } printf("\n");
      for (c5=1; c5<=23; c5++){
         printf(" %.2f ",vp1.x[c5-1]);
      } printf("\n");

/*Continuar?? y Reemplazo de variables*/
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
            for (s=2; s<=23; s++){
               if (s==22){
                  v1.x[20]=0; //La nueva columna de día actual se hace 0
                  v2.x[20]=0;
                  v3.x[20]=0;
                  v4.x[20]=0;
                  vp1.x[20]=0;
               } else if (s==23){
                  v1.y[0]=v1.y[1]; //Traslado de la columna 23 (predicción) a la 22 (esperada)
                  v2.y[0]=v2.y[1];
                  v3.y[0]=v3.y[1];
                  v4.y[0]=v4.y[1];
                  vp1.x[21]=vp1.x[22];
                  v1.y[1]=0; //La nueva columna de predicción se hace 0
                  v2.y[1]=0;
                  v3.y[1]=0;
                  v4.y[1]=0;
                  vp1.x[22]=0;
               } else {
                  v1.x[s-2]=v1.x[s-1]; //Traslado de las variables viejas a la izquierda.
                  v2.x[s-2]=v2.x[s-1];
                  v3.x[s-2]=v3.x[s-1];
                  v4.x[s-2]=v4.x[s-1];
                  vp1.x[s-2]=vp1.x[s-1];
               }
            } break;
         }
   }
return 0;
}


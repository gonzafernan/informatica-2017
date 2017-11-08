#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int recorre(struct posicion *A, struct posicion *B){

  struct posicion *C;
  int i, j, k;
  int salida;

  for (i = 0; i<10; i++){
    for (j = 0; j<10; j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  if (A -> x == B -> x && A -> y == B -> y) {
    printf("Punto encontrado\n");
    return 1;
  }

  k = 0;
  for (i = -1; i < 2; i++) {
    for (j = -1; j < 2; j++) {
      if (!(i==0 && j==0)){
        if ((A -> x + i)<10 && (A -> x + i)>=0 && (A -> y + j)<10 && (A -> y + j)>=0) {
          A -> hijos[k] = malloc(sizeof(struct posicion));
          A -> hijos[k] -> x = A -> x + i;
          A -> hijos[k] -> y = A -> y + j;
          printf("Hijo %d:(%d,%d)\n", k, A -> hijos[k] -> x, A -> hijos[k] -> y);
          k += 1;
          // printf("Hola\n");
        }
      }

    }
  }

//WARNING!!!!

  for (i = 0; i < k; i++) {
    int estado;
    estado = matriz[A -> hijos[i] -> x][A -> hijos[i] -> y];
    if (estado == 0) {
      printf("(%d,%d)\n", A -> hijos[i] -> x, A -> hijos[i] -> y);
      matriz[A -> hijos[i] -> x][A -> hijos[i] -> y] = 2;
      C = A -> hijos[i];

      salida = recorre(C,B);
      if (salida == 1){
        return 1;
      }
    } else if (estado == 1 || estado == 2) {
      return 0;
    }
  }

  //Impresion final de la matriz

  return 0;
}

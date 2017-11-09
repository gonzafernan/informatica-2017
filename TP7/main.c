#include <stdio.h>
#include "headers.h"

int matriz[10][10] = {
                      {1,0,0,0,0,1,1,1,1,1},
                      {1,1,0,0,0,1,0,0,0,0},
                      {0,1,0,0,0,1,0,0,0,0},
                      {0,1,0,0,0,1,0,0,0,0},
                      {0,1,0,0,0,1,0,0,0,0},
                      {0,1,0,0,0,1,1,0,0,0},
                      {0,1,0,0,0,0,1,1,1,1},
                      {0,1,0,0,0,0,0,0,0,1},
                      {0,1,0,0,0,0,0,0,0,1},
                      {0,1,1,1,1,1,1,1,1,0}
                                            };

int main(){
  int i, j;

  //Creación de la matriz
  for (i = 0; i<10; i++){
    for (j = 0; j<10; j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  struct posicion A, B;

  printf("Ingrese la posicion x,y del punto inicial de la forma (x,y):\n");
  scanf("%d,%d", &(A.x), &(A.y));
  if (!((A.x)<10 && (A.x)>=0 && (A.y)<10 && (A.y)>=0)){
    printf("Posicion no valida\n");
    return 0;
  }

  printf("Ingrese la posicion x,y del punto final de la forma (x,y):\n");
  scanf("\n%d,%d", &(B.x), &(B.y));
  if (B.x > 9 || B.x < 0 || B.y > 9 || B.y < 0){
    printf("Posicion no valida\n");
    return 0;
  }

  printf("Posición:\n\tInicial:(%d,%d)\n\tFinal: (%d,%d)\n", A.x, A.y, B.x, B.y);

  int salida;
  salida = recorre(&A, &B);
  if (salida == 1){
    for (i = 0; i<10; i++){
      for (j = 0; j<10; j++){
        printf("%d ", matriz[i][j]);
      }
      printf("\n");
    }
    printf("Somos krrrraks\n");
  }else{
    printf("No existe solucion.\n");
  }




  return 0;
}

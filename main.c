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
struct posicion{
  int x;
  int y;
};

struct NODO{
  int valor;
  struct NODO *hijos[8];
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

  printf("Ingrese la posicion x,y del punto inicial\n");
  scanf("%d", &(A.x));
  scanf("%d", &(A.y));
  if (A.x > 9 || A.x < 0 || A.y > 9 || A.y < 0){
    printf("Posicion no valida\n");
    return 0;
  }

  printf("Ingrese la posicion x,y del punto final\n");
  scanf("%d", &(B.x));
  scanf("%d", &(B.y));
  if (B.x > 9 || B.x < 0 || B.y > 9 || B.y < 0){
    printf("Posicion no valida\n");
    return 0;
  }

  printf("%d %d %d %d ", A.x, A.y, B.x, B.y);





  return 0;
}

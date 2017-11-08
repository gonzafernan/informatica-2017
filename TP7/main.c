#include <stdio.h>

int main(){
//la matriz laberinto se ubica en un archivo de texto desde donde la leeremos
  FILE *matriz;
  matriz = fopen("matriz.txt", "r");
  if (matriz == NULL){
      printf("\nError de apertura del archivo.\n\n");
  }
  int laberinto[10][10];
  int buffer_int, i, j;
  char get_buffer;
  printf("El laberinto a resolver es:\n\n");

  //lectura del archivo de texto y escritura sobre una matriz con enteros
  for (i=0;i<10;i++){
    for (j=0;j<11;j++){
      get_buffer = fgetc(matriz);
      buffer_int = (int)(get_buffer - '0');  //casteo de char ascii a int
      if (get_buffer == '\n'){
        continue;
      }
      laberinto[i][j] = buffer_int;
    }
  }
  fclose(matriz);

  for (i = 0; i<10; i++){
    for (j = 0; j<10; j++){
      printf("%d ", laberinto[i][j]);
    }
    printf("\n");
  }



  // int Ax,Ay,Bx,By;
  // printf("\n ingrese en modo de coordernada (x,y) el punto inicial A (tomar en cuenta que el (0,0) es el extremo izquierdo de abajo):\n");
  // scanf(" (%d,%d)",&Ax,&Ay);
  // printf("ingrese en modo de coordernada (x,y) el punto final B :\n");
  // scanf(" (%d,%d)",&Bx,&By);
  // laberinto[10-Ay][Ax]=2;
  // laberinto[10-By][Bx]=3;
  /*for (i=0;i<10;i++){ //algoritmo para mostrar la matriz
    for (j=0;j<10;j++){
        printf(" %d ",laberinto[i][j]);}
        printf("\n");}
  */
  return 0;
}

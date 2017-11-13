#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers.h"

int main(){
  srand(time(NULL));

  // Generación de arreglo de números aleatorios.
  int i, num;
  int dim = 1000;
  int *arreglo;
  arreglo = malloc(dim*sizeof(int));
  for (i = 0; i < dim; i++) {
    arreglo[i] = rand() % dim;
  }

  int num_search = 500;

  num = rand() % dim;
  arreglo[num] = num_search;

  printf("\nArreglo desordenado:\n\n");
  for (i = 0; i < dim; i++) {
    printf("%d, ", arreglo[i]);
  }
  printf("\n");

      //Ordenamiento del arreglo

  printf("Ingrese 0 para bubblesort.\nIngrese 1 para quicksort\n");
  int opcion;
  scanf(" %d", &opcion);
  if (opcion == 0) {
    arreglo = bubblesort(arreglo, dim);
  } else if (opcion == 1) {
    quicksort(arreglo, 0, dim - 1);
  }

  printf("\nArreglo ordenado:\n\n");
  for (i = 0; i < dim; i++) {
    printf("%d, ", arreglo[i]);
  }
  printf("\n");

      //Busqueda binaria

  printf("\nBúsqueda binaria:\n");

  int pos = busqueda_binaria(arreglo, 0, dim - 1, num_search);
  if (pos < 0){
    printf("Número no encontrado\n");
  }
  else{
    printf("El índice del número es %d\n", pos);
    printf("Verificación:\tarreglo[%d]=%d\n", pos, arreglo[pos]);
  }



  free(arreglo);

  return 0;
}

#include <stdio.h>
#include "sort_and_search.h"

int *bubblesort(int *arreglo, int dim){
  int i, aux, cond = 1;
  while(cond != 0){
    cond = 0;
    for (i = 0; i < dim - 1; i++){
      if (arreglo[i] > arreglo[i + 1]) {
        aux = arreglo[i];
        arreglo[i] = arreglo[i + 1];
        arreglo[i + 1] = aux;
        cond += 1;
      }
    }
  }

  return arreglo;
}

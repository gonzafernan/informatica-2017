#include <stdio.h>
#include "sort_and_search.h"

void *quicksort(int *arreglo, int izq, int der){

  // printf("\n\n");
  // printf("arreglo inicial=\n");
  // for (int k = 0; k < 10; k++) {
  //   printf("%d, ", arreglo[k]);
  // }
  // printf("\n");
  //
  // printf("pivote=%d\n", izq);

  if (izq < der){
    int i = izq + 1;
    int j = der;
    int p_val = arreglo[izq];

    while (i < j){
      if (arreglo[i] <= p_val){
        i++;
      }
      else if(arreglo[j] >= p_val){
        j--;
      }
      else{  // solo entra cuando arreglo[i] > p_val && arreglo[j] < p_val
        //swap arreglo_i y arreglo_j
        int aux = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = aux;
      }
    }

    // for (int k = 0; k < 10; k++) {
    //   printf("%d, ", arreglo[k]);
    // }
    // printf("\n");
    //
    // printf("i=%d\n",i);

    if(arreglo[i] < p_val){
      //swap arreglo_i y arreglo_izq
      int aux = arreglo[i];
      arreglo[i] = arreglo[izq];
      arreglo[izq] = aux;

      i--;
    }
    else{
      i--;
      //swap arreglo_i y arreglo_izq
      int aux = arreglo[i];
      arreglo[i] = arreglo [izq];
      arreglo[izq] = aux;
    }

    // for (int k = 0; k < 10; k++) {
    //   printf("%d, ", arreglo[k]);
    // }
    // printf("\n");

    quicksort(arreglo, izq, i);
    quicksort(arreglo, j, der);
  }
}

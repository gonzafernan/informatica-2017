#include <stdio.h>
#include "sort_and_search.h"

int busqueda_binaria(int *arreglo, int izq, int der, int elem){

  int pos_piv = (der + izq) / 2;
  if (der - izq == 0){
    pos_piv = der;
    if (arreglo[pos_piv] == elem){
      return pos_piv;
    }
    else{
      return -1;
    }
  }

  if (arreglo[pos_piv] == elem){
    return pos_piv;
  }
  else if (arreglo[pos_piv] < elem){
    return busqueda_binaria(arreglo, pos_piv + 1, der, elem);
  }
  else if (arreglo[pos_piv] > elem){
    return busqueda_binaria(arreglo, izq, pos_piv - 1, elem);
  }

  else{
    return -1;  //codigo de error
  }
}

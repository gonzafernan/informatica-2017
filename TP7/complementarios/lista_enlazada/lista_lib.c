#include <stdio.h>
#include <stdlib.h>
#include "lista_lib.h"

struct NODO * agregar_nodo(struct NODO * actual){

  // Búsqueda del último nodo en la lista.
  while (actual -> siguiente != NULL) {
    actual = actual -> siguiente;
  }
  actual -> siguiente = malloc(sizeof(struct NODO));
  actual -> siguiente -> anterior = actual;
  actual -> siguiente -> siguiente = NULL;
  actual -> siguiente -> valor = 0;

  return actual -> siguiente;
}

void eliminar_nodo(struct NODO * nodo){
  if (nodo -> anterior != NULL) {
    nodo -> anterior -> siguiente = nodo -> siguiente;
  }
  if (nodo -> siguiente != NULL) {
    nodo -> siguiente -> anterior = nodo -> anterior;
  }
  free(nodo);
}

void modificar_nodo(struct NODO * nodo, int cambio){
  nodo -> valor = cambio;
}

void print_lista(struct NODO * nodo) {
  while (nodo -> anterior != NULL) {
    nodo = nodo -> anterior;
  }
  int i = 0;
  while (nodo != NULL) {
    printf("Nodo %d: %d\n", i, nodo -> valor);
    nodo = nodo -> siguiente;
    i += 1;
  }
}

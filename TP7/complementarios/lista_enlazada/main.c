#include <stdio.h>

#include "lista_lib.h"

int main(){
  // Creación del primer nodo.
  struct NODO *primero;
  primero -> valor = 1;
  primero -> siguiente = NULL;
  primero -> anterior = NULL;

  // Se agregan elementos a la lista:
  struct NODO *segundo;
  struct NODO *tercero;
  segundo = agregar_nodo(primero); // La función agrega el nodo al final de la lista.
  tercero = agregar_nodo(primero);

  // Se modifican sus valores:
  modificar_nodo(segundo, 2);
  modificar_nodo(tercero, 3);

  // Se imprimen todos los nodos de la lista en que se haya el nodo que se pasa como parámetro.
  // Los nodos de la lista se muestran del primero al último.
  print_lista(segundo);

  // Se elimina uno de los nodos de la lista, en este caso el segundo.
  eliminar_nodo(segundo);
  // Se verifica con la misma función anterior que el nodo haya sido eliminado.
  print_lista(tercero);

  return 0;
}

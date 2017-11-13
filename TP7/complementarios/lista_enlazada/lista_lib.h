#ifndef lista_lib_h
#define lista_lib_h

struct NODO {
  struct NODO *anterior;
  int valor;
  struct NODO *siguiente;
};

int main();
struct NODO * agregar_nodo(struct NODO * actual);
void eliminar_nodo(struct NODO * nodo);
void modificar_nodo(struct NODO * nodo, int cambio);
void print_lista(struct NODO * nodo);

#endif

#ifndef headers_h
#define headers_h

int main(void);
void manejador_signals(int signal_type);
void proceso_A();
void proceso_B();

void *thread_H1(int *en_ejecucion, int sd, void *direccionSocketCliente, void *longitudDireccionCliente);
void *thread_H2(void * attr);
void *thread_H3(void *en_ejecucion);

#define MAP_BOOLEAN(X) X==TRUE?"TRUE":"FALSE"

#endif

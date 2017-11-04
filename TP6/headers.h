#ifndef headers_h
#define headers_h

int main(void);
void manejador_signals(int signal_type);
void proceso_A();
void proceso_B();

void *thread_H1(int sd, void *direccionSocketCliente, void *longitudDireccionCliente);
void *thread_H2(void * sd);
void *thread_H3();
void *thread_H4();

// Definición de tipo booleano.
typedef int boolean;
#define TRUE 1
#define FALSE 0
boolean en_ejecucion;
#define MAP_BOOLEAN(X) X==TRUE?"TRUE":"FALSE"

// Variables globales utilizadas para la comunicación entre procesos.
#define SERVER 0
#define CLIENTE 1
int rolProceso;

#define PUERTO_SERVER 3333
#define MAX_LARGO_COLA 100

#endif

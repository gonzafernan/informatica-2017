#include <stdio.h>
#include <stdlib.h>

#include "headers.h"

#include <unistd.h> // Biblioteca para multi processing
#include <signal.h> // Bibilioteca para enviar señales a los procesos
#include <sys/wait.h>

// Variables globales utilizadas para la comunicación entre procesos.
#define SERVER 0
#define CLIENTE 1
int rolProceso;

#define PUERTO_SERVER 3333
#define MAX_LARGO_COLA 100

typedef int boolean;
#define TRUE 1
#define FALSE 0
boolean en_ejecucion;

int main(void){

  //Inicializacion
	en_ejecucion = TRUE;

  pid_t pid_B, pid_C;

  //Registramos con el kernel la funcion que maneja las signals
	signal(SIGINT, manejador_signals);
	signal(SIGTERM, manejador_signals);
	signal(SIGHUP, manejador_signals);

  // El proceso principal (Proceso A), crea 2 procesos hijos (Procesos B y C)

  // Creación del primer proceso hijo (Proceso B)
  pid_B = fork();
  if (pid_B == -1) {
    perror("ERROR al crear proceso B.\n");
    return 1;;
  } else if (pid_B == 0) {
    // Código a ejecutar por el proceso hijo (Proceso B)
    //printf("Proceso B creado con éxito. En ejecución...\n");
    proceso_B();

  } else {
    // Código a ejecutar por el proceso padre (Proceso A)
    // Creación del segundo proceso hijo (Proceso C)
    pid_C = fork();
    if (pid_C == -1) {
      perror("ERROR al crear proceso C.\n");
      return 1;
    } else if (pid_C == 0){
      // Código a ejecutar por el proceso hijo (Proceso C)
			//printf("Proceso C esperando órdenes\n");
      getchar();
      kill(pid_B, SIGHUP);
			//printf("Ejecución del proceso C finalizada con éxito.Estado: %d\n", en_ejecucion);

			exit(0);

    } else {
      // Código a ejecutar por el proceso padre (Proceso A)
      //printf("Proceso A en ejecución...\n");
      proceso_A();

      // kill(pid_B, SIGTERM);
      // kill(pid_C, SIGTERM);
      // printf("Señal SIGTERM enviada a los procesos con éxito.\n");

      int status;
      waitpid(pid_B, &status, 0);
      waitpid(pid_C, &status, 0);

      //printf("\nEjecución del multiprocessing finalizada con éxito.\n");
    }
  }

  return 0;
}


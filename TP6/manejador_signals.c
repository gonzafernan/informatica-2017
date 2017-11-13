#include <stdio.h>
#include <stdlib.h>
#include <string.h>			// Memset

#include "headers.h"

#include <signal.h> // Bibilioteca para enviar señales a los procesos

extern boolean en_ejecucion;

//Esta funcion maneja las señales que recibe del kernel ("interrupciones de software")
void manejador_signals(int signal_type){
  char rolprocesochar[10];
  if(rolProceso == SERVER){
	  strcpy(rolprocesochar, "Servidor");
  } else{
	  strcpy(rolprocesochar, "Cliente");
  }
  if (signal_type == SIGTERM){
	  en_ejecucion = FALSE;
	  printf("%s: Señal SIGTERM recibida. Terminando proceso.\n", rolprocesochar);
  }
  else if (signal_type == SIGKILL){
	  en_ejecucion = FALSE;
	  printf("%s: Señal SIGKILL recibida. Terminando proceso.\n", rolprocesochar);
  }
  else if (signal_type == SIGHUP){
    en_ejecucion = FALSE;
    printf("Señal SIGHUP recibida. Finalizando el programa.\n");
  }
  else
	printf("Señal desconocida. Ignorando...\n\n");
}

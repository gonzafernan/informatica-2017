#include <stdio.h>
#include <stdlib.h>
#include <string.h>			// Memset

#include "headers.h"

extern boolean en_ejecucion;

//Esta funcion maneja las señales que recibe del kernel ("interrupciones de software")
void manejador_signals(int signal_type){
  char rolProceso_[10];
  if(rolProceso == SERVER){
	  strcpy(rolProceso_, "Servidor");
  } else{
	  strcpy(rolProceso_, "Cliente");
  }
  if (signal_type == SIGTERM){
	  en_ejecucion = FALSE;
	  printf("%s: Señal SIGTERM recibida. Terminando proceso.\n", rolProceso_);
  }
  else if (signal_type == SIGKILL){
	  en_ejecucion = FALSE;
	  printf("%s: Señal SIGKILL recibida. Terminando proceso.\n", rolProceso_);
  }
  else if (signal_type == SIGHUP){
    en_ejecucion = FALSE;
    printf("Señal SIGHUP recibida. Finalizando el programa.\n");
  }
  else
	printf("Señal desconocida. Ignorando...\n\n");
}

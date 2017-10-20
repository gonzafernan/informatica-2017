#include <stdio.h>
#include <stdlib.h>
#include <string.h>			// Memset
#include <signal.h>
#include <bits/signum.h>
#include "headers.h"

// Definición de tipo booleano.
typedef int boolean;
#define TRUE 1
#define FALSE 0
boolean en_ejecucion;

// Variables globales utilizadas para la comunicación entre procesos.
#define SERVER 0
#define CLIENTE 1
int rolProceso;

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
  else
	printf("Señal desconocida. Ignorando...\n\n");
}

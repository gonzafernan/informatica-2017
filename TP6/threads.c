#include <stdio.h>
#include <stdlib.h>

#include "headers.h"

#include <sys/socket.h>		// Sockets
#include <arpa/inet.h>		// Sockets

#include <pthread.h>

#include <unistd.h>
#include <sys/wait.h>
#include <string.h>			// Memset

typedef int boolean;
#define TRUE 1
#define FALSE 0
boolean en_ejecucion;

// Mutex para la sincronización de los hilos:
pthread_mutex_t mutext = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condicion = PTHREAD_COND_INITIALIZER;


// Espacio de memoria compartido:
char *file;

void *thread_H1(int *en_ejecucion, int sd, void *direccionSocketCliente, void *longitudDireccionCliente) {
  // El hilo 1 se bloquea esperando conexiones:
  while (*en_ejecucion == TRUE) {
    int sd_cliente2;
    sd_cliente2 = accept(sd, direccionSocketCliente, longitudDireccionCliente);
  }

  return NULL;
}

void *thread_H2(int *en_ejecucion, int sd_aceptado){
  // El hilo 2 recibe los datos que el proceso A envía en bloques de 10 bytes.
  // Coloca esos datos en una estructura de datos compartida.
  //pthread_mutex_init(&mutext, NULL);
  while (*en_ejecucion == TRUE) {
    char buffer_lectura[10];
    long int sz_file;
    //Ahora intentamos leer los bytes transferidos. El proceso se bloquea si no hay nada que leer
    recv(sd_aceptado, &sz_file, sizeof(long int), 0);

    // Asignación dinámica de memoria:
    file = malloc((sz_file)*sizeof(char));

    // Recepción del archivo desde el cliente:
    int i = 0, j = 0;
    boolean band = TRUE;
    while (band) {
      //pthread_cond_wait(&condicion, &mutext);
      recv(sd_aceptado, buffer_lectura, sizeof(buffer_lectura), 0);
      //pthread_mutex_lock(&mutext);
      for (i = 0; i < sizeof(buffer_lectura); i++) {
        file[j + i] = buffer_lectura[i];
        if (buffer_lectura[i] == EOF) {
          band = FALSE;
          *en_ejecucion = FALSE;
          break;
        }
        //printf("%c", buffer_lectura[i]);
        printf("%c", file[i + j]);
      }
      //pthread_mutex_unlock(&mutext);
      j = j + 1;
    }
    for (i = 0; i < sz_file; i++) {
      printf("%c", file[i]);
    }
  }

  free(file);
  //pthread_mutex_destroy(&mutext);

  return NULL;
}

// void *thread_H3(void){
//   // El hilo 3 muestra por pantalla lo que el hilo 2 va recibiendo.
//   boolean band = TRUE;
//   int i = 0;
//   while (band) {
//     pthread_cond_wait(&condicion, &mutext);
//     pthread_mutex_lock(&mutext);
//     printf("%c", file[i]);
//     if (file[i] == EOF) {
//       band = FALSE;
//     }
//     pthread_mutex_unlock(&mutext);
//     i += 1;
//   }
//   return NULL;
// }

// void *thread_H4(char *file) {
//   // El hilo 4 va guardando en un archivo lo que el hilo 2 va recibido.
//   FILE *fp;
//   fp = fopen("Archivo recibido.txt","w");
//
//   boolean band = TRUE;
//   int i = 0;
//   while (band) {
//
//   }
// }

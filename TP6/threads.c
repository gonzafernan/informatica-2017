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
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condicion = PTHREAD_COND_INITIALIZER;

// Struct para argumentos de los hilos:
struct attr{
  boolean arg1;
  int arg2;
};

// Espacio de memoria compartido:
char *file;

void *thread_H1(int *en_ejecucion, int sd, void *direccionSocketCliente, void *longitudDireccionCliente) {
  // El hilo 1 se bloquea esperando conexiones:
  while (*en_ejecucion == TRUE) {
    printf("Thread 1...\n");
    int sd_cliente2;
    sd_cliente2 = accept(sd, direccionSocketCliente, longitudDireccionCliente);
    //printf("%d\n", sd_cliente2);
  }

  return NULL;
}

void *thread_H2(void * attr_H2){
  // El hilo 2 recibe los datos que el proceso A envía en bloques de 10 bytes.
  // Coloca esos datos en una estructura de datos compartida.
  //pthread_mutex_init(&mutext, NULL);
  struct attr *args_H2 = (struct attr *)attr_H2;
  boolean en_ejecucion = args_H2 -> arg1;
  int sd_aceptado = args_H2 -> arg2;
  while (en_ejecucion == TRUE) {
    printf("Thread 2...\n");
    char buffer_lectura[10];
    long int sz_file;
    //Ahora intentamos leer los bytes transferidos. El proceso se bloquea si no hay nada que leer
    recv(sd_aceptado, &sz_file, sizeof(long int), 0);
    printf("%lu\n", sz_file);
    // Asignación dinámica de memoria:
    file = malloc((sz_file)*sizeof(char));

    // Recepción del archivo desde el cliente:
    int i = 0, j = 0;
    boolean band = TRUE;
    while (band) {
      //pthread_cond_wait(&condicion, &mutext);
      recv(sd_aceptado, buffer_lectura, sizeof(buffer_lectura), 0);
      //printf("%s\n", buffer_lectura);
      //pthread_mutex_lock(&mutex);
      for (i = 0; i < sizeof(buffer_lectura); i++) {
        file[j * 10 + i] = buffer_lectura[i];
        //printf("%c", buffer_lectura[i]);
        if (buffer_lectura[i] == '\0') {
          band = FALSE;
          en_ejecucion = FALSE;
          break;
        }
        printf("%c", buffer_lectura[i]);
      }
      //pthread_mutex_unlock(&mutex);
      j = j + 1;
    }
  }

  free(file);
  //pthread_mutex_destroy(&mutext);

  return NULL;
}

void *thread_H3(void *en_ejecucion){
  // El hilo 3 muestra por pantalla lo que el hilo 2 va recibiendo.
  while (*(int *)en_ejecucion == TRUE) {
    int i = 0;
    printf("Thread 3...\n");
    while (file[i] != '\0') {
      //pthread_cond_wait(&condicion, &mutext);
      //pthread_mutex_lock(&mutext);
      printf("%c", file[i]);
      //pthread_mutex_unlock(&mutext);
      i += 1;
    }
  }

  return NULL;
}

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

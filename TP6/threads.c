#include <stdio.h>
#include <stdlib.h>

#include "headers.h"

#include <sys/socket.h>		// Sockets
#include <arpa/inet.h>		// Sockets

#include <pthread.h>

#include <unistd.h>
#include <sys/wait.h>
#include <string.h>			// Memset

// Espacio de memoria compartido:
char *file;
long int sz_file;

extern boolean en_ejecucion;

void *thread_H1(int sd, void *direccionSocketCliente, void *longitudDireccionCliente) {
  // El hilo 1 se bloquea esperando conexiones:
   while (en_ejecucion == TRUE) {
     //int sd_cliente2;
     //sd_cliente2 = accept(sd, direccionSocketCliente, longitudDireccionCliente);
   }
  // printf("Ejecución del primer hilo finalizada con éxito.\n");
  return NULL;
}

void *thread_H2(void * sd){
  // El hilo 2 recibe los datos que el proceso A envía en bloques de 10 bytes.
  // Coloca esos datos en una estructura de datos compartida.
  int sd_aceptado = *(int *)sd;
  char buffer_lectura[10];
  //Ahora intentamos leer los bytes transferidos. El proceso se bloquea si no hay nada que leer
  recv(sd_aceptado, &sz_file, sizeof(long int), 0);
  //printf("Servidor:\n\tTamaño del archivo: %lu\n", sz_file);
  // Asignación dinámica de memoria:
  file = malloc((sz_file)*sizeof(char));
  int i = 0, j = 0;
  for (i = 0; i < sz_file; i++) {
    file[i] = '\0';
  }

  // Recepción del archivo desde el cliente:
  int pack=(sz_file/(int)sizeof(buffer_lectura))+1;
  for (j = 0; j < pack; j++) {
    recv(sd_aceptado, buffer_lectura, sizeof(buffer_lectura), 0);
    for (i = 0; i < sizeof(buffer_lectura); i++) {
      file[j * 10 + i] = buffer_lectura[i];
      buffer_lectura[i] = '\0';
      if (file[j * 10 + i] == sz_file) {
        break;
      }
    }
  }
  do{sleep(1);}while(en_ejecucion == TRUE);
  // printf("Ejecución del segundo hilo finalizada con éxito.\n");
  return NULL;
}

void *thread_H3(){
  // El hilo 3 muestra por pantalla lo que el hilo 2 va recibiendo.
  sleep(1);
  int i = 0;
  for (i = 0; i < sz_file; i++) {
    if (file[i]!='\0' && (file + i) != NULL) {
      printf("%c", file[i]);
    } else {
      i -= 1;
    }
  }
  free(file);
  do{sleep(1);}while(en_ejecucion == TRUE);
  // printf("Ejecución del tercer hilo finalizada con éxito.\n");
  return NULL;
}

 void *thread_H4() {

   // El hilo 4 va guardando en un archivo lo que el hilo 2 va recibido.
   sleep(1);
   FILE *fp;
   fp = fopen("Archivo recibido.txt","w");
   int i;
   for (i = 0; i < sz_file; i++) {
     if (file[i]!='\0') {
       fwrite((file + i),1,sizeof(char),fp);
     } else {
       i -= 1;
     }
   }
   fclose(fp);
   
   do{sleep(1);}while(en_ejecucion == TRUE);
  //  printf("Ejecución del cuarto hilo finalizada con éxito.\n");
   return NULL;
 }

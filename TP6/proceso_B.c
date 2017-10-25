#include <stdio.h>
#include <stdlib.h>

#include "headers.h"

#include <sys/socket.h>		// Sockets
#include <arpa/inet.h>		// Sockets

#include <pthread.h>

#include <unistd.h>
#include <sys/wait.h>
#include <string.h>			// Memset

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

// Struct para argumentos de los hilos:
struct attr{
  boolean arg1;
  int arg2;
};

void proceso_B(){
  //Inicializacion
	en_ejecucion = TRUE;

  rolProceso = SERVER;

  // Creación del socket.
  int sd; // Descriptor del socket
  // AF_INET: Familia de protocolos TCP/IP
  // SOCK_STREAM: Servicio orientado a la conexión (normalmente protocolo TCP)
  sd = socket(AF_INET, SOCK_STREAM, 0);
  if (sd < 0){
    perror("ERROR al crear socket (servidor)");
    abort();
  }

  //Creamos la configuracion de direccion para el socket
  struct sockaddr_in direccionSocket;  //Estructura para configurar el socket
  memset(&direccionSocket, 0, sizeof(direccionSocket)); 		//Utilizamos memset para inicializar a 0 todos los bytes de la estructura de configuracion del socket
  direccionSocket.sin_family = AF_INET; 						//Familia de direcciones de TCP/IP
  inet_aton("127.0.0.1", &(direccionSocket.sin_addr));		//Especificamos la direccion IP al que se conectara el socket, y la convertimos al formato de la red
  direccionSocket.sin_port = htons(PUERTO_SERVER);       		//Especificamos el puerto TCP al que se conectara el socket, y lo convertimos al byte order de la red

  //Enlazamos el socket con la direccion local
  if(bind(sd, (struct sockaddr *)&direccionSocket,sizeof(direccionSocket)) < 0){
    perror("ERROR al enlazar socket al puerto (servidor)");
    abort();
  }

  //Configuramos el socket para que escuche conexiones, y configuramos una cantidad maxima MAX_LARGO_COLA de conexiones que podemos poner en la cola
  listen(sd, MAX_LARGO_COLA);

  //Creamos las variables requeridas para esperar una conexion
  struct sockaddr_in direccionSocketCliente;
  socklen_t longitudDireccionCliente;
  int sd_aceptado;  //socket creado automaticamente cuando se acepta una conexion

  //El proceso se bloquea esperando una conexion
  sd_aceptado = accept(sd, (struct sockaddr *)&direccionSocketCliente, &longitudDireccionCliente);

  //Handlers de los threads a ser creados:
  pthread_t H2, H3; //H4;
  //int H2_id = 2, H3_id = 3, H4_id = 4;

  //Inicializacion de los threads:
  struct attr attr_H2;
  attr_H2.arg1 = en_ejecucion;
  attr_H2.arg2 = sd_aceptado;

	if(pthread_create(&H2, NULL, thread_H2, (void *)&attr_H2)){
		printf("Error al crear el hilo 2.\n");
		abort(); //Sale del programa y realiza un volcado del nucleo (muestra el estado completo del proceso con sus variables, instrucciones, etc.
	}
  if(pthread_create(&H3, NULL, thread_H3, (void *)&en_ejecucion)){
		printf("Error al crear el hilo 3.\n");
		abort();
  }
  // if(pthread_create(&H4, NULL, thread_H4, &H4_id)){
	// 	printf("Error al crear el hilo 4.\n");
	// 	abort();
	// }

  // El hilo 1 se bloquea esperando conexiones:
  thread_H1(&en_ejecucion, sd, (struct sockaddr *)&direccionSocketCliente, &longitudDireccionCliente);

  //El thread principal queda en espera de que el usuario presione una tecla, y cuando esto ocurre cierra todos los threads y los unifica
  getchar();
  en_ejecucion = FALSE;

  //Reunión de los 4 threads.
	//Esta llamada bloquea la ejecución del thread principal hasta que los otros 3 terminan.
  if(pthread_join(H2, NULL) /*|| pthread_join(H3, NULL)*/ /*|| pthread_join(H4, NULL)*/) {
		printf("Error reuniendo los threads.");
		abort();
	}
	else{
	  printf("\nEjecucion finalizada con exito.\n");
  }
  close(sd_aceptado);
  close(sd);
}

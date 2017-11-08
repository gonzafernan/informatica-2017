#include <stdio.h>
#include <stdlib.h>

#include "headers.h"

#include <sys/socket.h>		// Sockets
#include <arpa/inet.h>		// Sockets

#include <pthread.h>

#include <unistd.h>
#include <sys/wait.h>
#include <string.h>			// Memset

extern boolean en_ejecucion;

void proceso_B(){

  rolProceso = SERVER;

  // Creación del socket.
  int sd; // Descriptor del socket
  // AF_INET: Familia de protocolos TCP/IP
  // SOCK_STREAM: Servicio orientado a la conexión (normalmente protocolo TCP)
  sd = socket(AF_INET, SOCK_STREAM, 0);
  if (sd < 0){
    perror("ERROR al crear socket (servidor)");
    en_ejecucion = FALSE;
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
    en_ejecucion = FALSE;
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
  pthread_t H1, H2, H3, H4;

  // Atributos para el thread 1:
  struct attr1 descriptor1;
  descriptor1.socket = sd;
  descriptor1.direccionS = &direccionSocketCliente;
  descriptor1.longitudS = &longitudDireccionCliente;

  //Inicializacion de los threads:
  if(pthread_create(&H1, NULL, thread_H1, (void *)&descriptor1)){
		printf("Error al crear el hilo 1.\n");
		en_ejecucion = FALSE; //Sale del programa y realiza un volcado del nucleo (muestra el estado completo del proceso con sus variables, instrucciones, etc.
	}

	if(pthread_create(&H2, NULL, thread_H2, &sd_aceptado)){
		printf("Error al crear el hilo 2.\n");
		en_ejecucion = FALSE; //Sale del programa y realiza un volcado del nucleo (muestra el estado completo del proceso con sus variables, instrucciones, etc.
	}
  if(pthread_create(&H3, NULL, thread_H3, NULL)){
		printf("Error al crear el hilo 3.\n");
		en_ejecucion = FALSE;
  }
  if(pthread_create(&H4, NULL, thread_H4, NULL)){
		printf("Error al crear el hilo 4.\n");
		en_ejecucion = FALSE;
	}
  // El hilo 1 se bloquea esperando conexiones:
  //thread_H1(sd, (struct sockaddr *)&direccionSocketCliente, &longitudDireccionCliente);
  while (1) {
    if (en_ejecucion == FALSE) {
      close(sd_aceptado);
      close(sd);
      break;
    }
  }
  //Reunión de los 4 threads.
	//Esta llamada bloquea la ejecución del thread principal hasta que los otros 3 terminan.
  if(pthread_join(H1, NULL) || pthread_join(H2, NULL) || pthread_join(H3, NULL) || pthread_join(H4, NULL)) {
		printf("Error reuniendo los threads.");
	}
  //printf("Ejecución del proceso B finalizada con éxito. Estado: %d\n", en_ejecucion);
  exit(0);
}

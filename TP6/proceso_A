#include <stdio.h>
#include <stdlib.h>

#include "headers.h"

#include <sys/socket.h>		// Sockets
#include <arpa/inet.h>		// Sockets

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

void proceso_A(){
  //Inicializacion
	en_ejecucion = TRUE;

  // Establecer conexión TCP con proceso B (servidor)
  int sd; // Descriptor del socket

  rolProceso = CLIENTE;

  // Creación del socket.
  // AF_INET: Familia de protocolos TCP/IP
  // SOCK_STREAM: Servicio orientado a la conexión (normalmente protocolo TCP)
  sd = socket(AF_INET, SOCK_STREAM, 0);
  if (sd < 0){
    perror("ERROR al crear socket (cliente)");
    abort();
  }

  //Creamos la configuracion de direccion para el socket
  struct sockaddr_in direccionSocket; 						//Estructura para configurar el socket
  memset(&direccionSocket, 0, sizeof(direccionSocket)); 		//Utilizamos memset para inicializar a 0 todos los bytes de la estructura de configuracion del socket
  direccionSocket.sin_family = AF_INET; 						//Familia de direcciones de TCP/IP
  inet_aton("127.0.0.1", &(direccionSocket.sin_addr));		//Especificamos la direccion IP al que se conectara el socket, y la convertimos al formato de la red
  direccionSocket.sin_port = htons(PUERTO_SERVER);       		//Especificamos el puerto TCP al que se conectara el socket, y lo convertimos al byte order de la red

  //Establecemos conexion con el server
  int conectado;
  do{
    sleep(1);
    conectado = connect(sd, (struct sockaddr *)&direccionSocket,sizeof(direccionSocket));
  }while(conectado < 0);

  char buffer_envio[10];

  while (en_ejecucion){
    // Partición de texto.
    // Leer un archivo de disco.
    FILE *fp;
    fp = fopen("No se culpe a nadie.txt","r");
    /* The C library function int fseek(FILE *stream, long int offset, int whence) (whence: posición)
    sets the file position of the stream to the given offset. */
    long int sz;
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp); // Tamaño del texto. ftell() devuelve la posición del fp en el stream.
    fseek(fp, 0L, SEEK_SET); // Reset del fp en el stream.

    // Enviamos el tamaño del archivo al servidor:
    send(sd, &sz, sizeof(long int), 0);

    // Enviamos el archivo al servidor:
    int i=0, j=0;
    boolean band = TRUE;
    while (band) {
      for (i = 0; i < sizeof(buffer_envio); i++) {
          buffer_envio[i] = getc(fp);
          if (buffer_envio[i] == EOF) {
            band = FALSE;
            break;
          }
      }
      // Enviamos el paquete de 10 bytes del archivo al servidor:
      send(sd, buffer_envio, sizeof(buffer_envio), 0);
    }

    en_ejecucion = FALSE;
    usleep(100000);
  }
  close(sd);
}

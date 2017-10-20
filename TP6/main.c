#include <stdio.h>
#include <stdlib.h>

#include "headers.h"

#include <unistd.h> // Biblioteca para multi processing
#include <signal.h> // Bibilioteca para enviar señales a los procesos

#include <sys/socket.h>		// Sockets
#include <arpa/inet.h>		// Sockets
//#include <bits/signum.h> 	// Biblioteca conconstantes para los tipos de señales
#include <sys/wait.h>
#include <string.h>			// Memset

//#include <pthread.h> // Biblioteca para multi threading

// Variables globales utilizadas para la comunicación entre procesos.
#define SERVER 0
#define CLIENTE 1
int rolProceso;

#define PUERTO_SERVER 3333
#define MAX_LARGO_COLA 100

// Definición de tipo booleano.
typedef int boolean;
#define TRUE 1
#define FALSE 0
boolean en_ejecucion;

int main(void){
  int pid_B, pid_C;

  pid_t pid_servidor;
	pid_t pid_cliente;

  //Inicializacion
	en_ejecucion = TRUE;

  //Registramos con el kernel la funcion que maneja las signals
	signal(SIGINT, manejador_signals);
	signal(SIGTERM, manejador_signals);

  // El proceso principal (Proceso A), crea 2 procesos hijos (Procesos B y C)

  // Creación del primer proceso hijo (Proceso B)
  pid_B = fork();
  if (pid_B == -1) {
    perror("ERROR al crear proceso B.\n");
    return 1;
  } else if (pid_B == 0) {
    // Código a ejecutar por el proceso hijo (Proceso B)

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

    char buffer_lectura[10];
  	char buffer_envio[100];
    boolean band=FALSE;
    while (en_ejecucion){
  		//Ahora intentamos leer los bytes transferidos. El proceso se bloquea si no hay nada que leer
      long int sz_file;
      recv(sd_aceptado, &sz_file, sizeof(long int), 0);

      //Esta verificacion solo se necesita para minimizar mensajes y ejecucion si se modifica la bandera en la mitad del bucle.
      if(en_ejecucion){
  			//Mostramos lo recibido por pantalla
  			//printf("Servidor recibio: '%s'\n", buffer_lectura);
        printf("Servidor recibio: '%li'\n", sz_file);
  			//Enviamos una respuesta al cliente
  			sprintf(buffer_envio, "Recepción de tamaño del archivo confirmada:\n\tTamaño: %li", sz_file);
        send(sd_aceptado, buffer_envio, strlen(buffer_envio), 0);
  		}

      // Asignación dinámica de memoria:
      //char *file;
      //file = malloc(sz_file*sizeof(char));

      // Recepción del archivo desde el cliente:
      int i = 0;
      boolean band = TRUE;
      while (band) {
        recv(sd_aceptado, buffer_lectura, sizeof(buffer_lectura), 0);

        // Verificación de lo que se esta recibiendo:
        printf("Servidor: %s\n", buffer_lectura);
        //printf("%lu\n",strlen(buffer_lectura));
        for (i = 0; i < sizeof(buffer_lectura); i++) {
          if (buffer_lectura[i] == EOF) {
            band = FALSE;
            break;
          }
        }
      }

      //Esta verificacion solo se necesita para minimizar mensajes y ejecucion si se modifica la bandera en la mitad del bucle.
      if(en_ejecucion){
  			//Mostramos lo recibido por pantalla
  			//printf("Servidor recibio: '%s'\n", buffer_lectura);
        printf("Servidor recibio: '%s'\n", buffer_lectura);
  			//Enviamos una respuesta al cliente
  			sprintf(buffer_envio, "Recepción del archivo confirmada.\n");
        send(sd_aceptado, buffer_envio, strlen(buffer_envio), 0);
        en_ejecucion = FALSE;
  		}
      //free(file);
      en_ejecucion = FALSE;

    }
  	//Cerramos el nuevo socket creado con accept
  	close(sd_aceptado);

  	//Cerramos el socket original
  	close(sd);

  } else {
    // Código a ejecutar por el proceso padre (Proceso A)
    // Creación del segundo proceso hijo (Proceso C)
    pid_C = fork();
    if (pid_C == -1) {
      perror("ERROR al crear proceso C.\n");
      return 1;
    } else if (pid_C == 0){
      // Código a ejecutar por el proceso hijo (Proceso C)

    } else {
      // Código a ejecutar por el proceso padre (Proceso A)

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

    	char buffer_lectura[100];
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

    		//Ahora intentamos leer los bytes transferidos. El proceso se bloquea si no hay nada que leer
    		recv(sd, buffer_lectura, sizeof(buffer_lectura), 0);

    		//Esta verificacion solo se necesita para minimizar mensajes y ejecucion si se modifica la bandera en la mitad del bucle
    		if(en_ejecucion){
    			//Mostramos lo recibido por pantalla
    			printf("\t|--> Cliente recibio: '%s'\n", buffer_lectura);
    		}

        // Enviamos el archivo al servidor:
        int i=0, j=0;
        boolean band = TRUE;
        while (band) {
          for (i = 0; i < sizeof(buffer_envio); i++) {
              buffer_envio[i] = getc(fp);
              if (buffer_envio[i] == EOF) {
                band = FALSE;
              }
          }
            // Verificación de lo que se esta enviando:
            // printf("Cliente: %s\n",buffer_envio);
            // printf("%lu\n",strlen(buffer_envio));
            // printf("%lu\n", sizeof(buffer_envio));

          // Enviamos el paquete de 10 bytes del archivo al servidor:
          send(sd, buffer_envio, sizeof(buffer_envio), 0);
        }

    		//Ahora intentamos leer los bytes transferidos. El proceso se bloquea si no hay nada que leer
    		//recv(sd, buffer_lectura, sizeof(buffer_lectura), 0);

    		//Esta verificacion solo se necesita para minimizar mensajes y ejecucion si se modifica la bandera en la mitad del bucle
    		if(en_ejecucion){
    			//Mostramos lo recibido por pantalla
    			printf("\t|--> Cliente recibio: '%s'\n", buffer_lectura);
          en_ejecucion = FALSE;
    		}
        en_ejecucion = FALSE;
    		usleep(100000);
      }
    	close(sd);

      getchar();

      kill(pid_servidor, SIGTERM);
      kill(pid_cliente, SIGTERM);

      int status;
      waitpid(pid_servidor, &status, 0);
      waitpid(pid_cliente, &status, 0);

      printf("\nEjecución terminada.\n");
    }
  }

  return 0;
}

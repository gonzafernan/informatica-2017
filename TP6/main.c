#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Biblioteca para multi processing
#include <signal.h> // Bibilioteca para enviar señales a los procesos
#include <sys/socket.h>		// Sockets
#include <arpa/inet.h>		// Sockets
#include <bits/signum.h> 	// Biblioteca conconstantes para los tipos de señales
#include <sys/wait.h>
#include <string.h>			// Memset

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

//Esta funcion maneja las señales que recibe del kernel ("interrupciones de software")
void manejador_signals(int signal_type)
{
  char rolProceso[10];
  if(rolProceso == SERVER){
	  strcpy(rolProceso, "Servidor");
  } else{
	  strcpy(rolProceso, "Cliente");
  }
  if (signal_type == SIGTERM){
	  en_ejecucion = FALSE;
	  printf("%s: Señal SIGTERM recibida. Terminando proceso.\n", rolProceso);
  }
  else if (signal_type == SIGKILL){
	  en_ejecucion = FALSE;
	  printf("%s: Señal SIGKILL recibida. Terminando proceso.\n", rolProceso);
  }
  else
	printf("Señal desconocida. Ignorando...\n\n");
}


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

    char buffer_lectura[100];
  	char buffer_envio[100];

  	while(en_ejecucion){
  		//Ahora intentamos leer los bytes transferidos. El proceso se bloquea si no hay nada que leer
  		recv(sd_aceptado, buffer_lectura, sizeof(buffer_lectura), 0);

  		//Esta verificacion solo se necesita para minimizar mensajes y ejecucion si se modifica la bandera en la mitad del bucle
  		if(en_ejecucion){
  			//Mostramos lo recibido por pantalla
  			printf("Servidor recibio: '%s'\n", buffer_lectura);

  			//Enviamos una respuesta al cliente
  			sprintf(buffer_envio, "Respuesta = %d", rand());
  			send(sd_aceptado, buffer_envio, strlen(buffer_envio), 0);
  		}
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
      // Leer un archivo de disco.
      FILE *fp;
      fp = fopen("Hello world.txt","r");

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
    	char buffer_envio[100];

      // Partición de texto.
      char * texto = malloc(15*sizeof(char));
      if( fp==NULL ){
       printf("Error al abrir el fichero\n");
     }else {
       int i=0;
       while( !feof(fp) ){
       buffer_envio[i] = getc(fp);
        i = i+1;
      }
      }

    	while(en_ejecucion){
    		// Enviamos mensaje al servidor
    		//sprintf(buffer_envio, "Mensaje = %d", rand());
    		send(sd, buffer_envio, strlen(buffer_envio), 0);

    		//Ahora intentamos leer los bytes transferidos. El proceso se bloquea si no hay nada que leer
    		recv(sd, buffer_lectura, sizeof(buffer_lectura), 0);

    		//Esta verificacion solo se necesita para minimizar mensajes y ejecucion si se modifica la bandera en la mitad del bucle
    		if(en_ejecucion){
    			//Mostramos lo recibido por pantalla
    			printf("\t|--> Cliente recibio: '%s'\n", buffer_lectura);
    		}

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


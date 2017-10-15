#include <stdio.h>
#include <unistd.h> // Biblioteca para multi processing
#include <signal.h> // Bibilioteca para enviar señales a los procesos
#include <sys/socket.h>		// Sockets
#include <arpa/inet.h>		// Sockets

int main(void){
  // El proceso principal (Proceso A), crea 2 procesos hijos (Procesos B y C)

  // Creación del primer proceso hijo (Proceso B)
  pid_B = fork();
  if (pid_B == -1) {
    perror("ERROR al crear proceso B.\n");
    return 1;
  } else if (pid_B == 0) {
    // Código a ejecutar por el proceso hijo (Proceso B)

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
      fp = fopen("No-se-culpe-a-nadie.txt","r");
      // Establecer conexión TCP con proceso B (servidor)
    }
  }

  return 0;
}

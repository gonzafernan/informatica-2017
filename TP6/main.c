#include <unistd.h> // Biblioteca para multi processing
#include <signal.h> // Bibilioteca para enviar señales a los procesos
#include <sys/wait.h>

int main(void){
  pid_t pid_B, pid_C;

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
    proceso_B();

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
      proceso_A();

      getchar();

      kill(pid_B, SIGTERM);
      kill(pid_C, SIGTERM);

      int status;
      waitpid(pid_B, &status, 0);
      waitpid(pid_C, &status, 0);

      printf("\nEjecución terminada.\n");
    }
  }

  return 0;
}

#include <stdio.h>

//Función que hace el cálculo del factorial
//Qué les parecen los criterios de detención? Faltaría algo?
int factorial (int n){
int y;
if (n>=1){
  y=n*factorial(n-1);
}
  else if (n==0){   //factorial de cero  es uno
    y=1;
}
  else if (n<0){
    printf("El número ingresado no es válido, ingrese un entero positivo\n");
    return -1;
  }
  return y;
}


//Cambiar main por ej7 para que compile todo el proyecto (y agregar header)
int main(){
  int x,f;
  printf("Ingrese el valor entero cuyo factorial quiere saber\n");
  scanf("%d", &x);
  f=factorial(x);
  if (f==-1){//Cuando x es negativo la función factorial devuelve -1
    return 0;
  }
  printf("El factorial de %d es %d\n", x, f);

  return 0;
}

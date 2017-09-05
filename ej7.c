#include <stdio.h>

int factorial (int n){
int y;
if (n>1){
  y=n*factorial(n-1);
}
else if (n==1){
  return 1;
}
  return y;
}

int main(){
  int x,f;
  printf("Ingrese el valor cuyo factorial quiere saber\n");
  scanf("%d", &x);
  if (x==0){
    printf("El factorial de %d es %d\n",x,f=1);
    return 0;
  }
  if (x<0){
    printf("El número ingresado no es válido, ingrese un entero positivo\n");
    return 0;
  }
  f=factorial(x);
  printf("El factorial de %d es %d\n", x, f);

  return 0;
}

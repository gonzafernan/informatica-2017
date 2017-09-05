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


int ej7(){
  int x,f;
  printf("Ingrese el valor entero cuyo factorial quiere saber\n");
  scanf("%d", &x);
  f=factorial(x);
  if (f==-1){//Cuando x es negativo la función factorial devuelve -1
    return 0;
  }
  printf("El factorial de %d es %d\n", x, f);

  return 0;
=======
//
//  ej7.c
//  Informatica-2017
//  Escribir un programa que calcule el factorial de un número y muestre el valor por pantalla
//
//
/*
#include <stdio.h>

int ej7(){
    int num,i;
    unsigned long long r1=1;
    long double r2=1;
    
    printf("///////////////////////////ADVERTENCIA: Si el número es mayor a 20 se pierde precisión///////////////////////////////////\nIngresar número: \n");
    scanf("%d",&num);

    if (num<0){
        printf("Math ERROR\n");
    } else if (num==0){
        printf("0!=1\n");
    } else if (num<=20){
        //Ciclo iterativo for
        for (i=1;i<=num;i++) {
            r1=r1*i;
        }
        printf("%d!=%llu\n",num,r1);
    } else {
        //Ciclo iterativo for
        for (i=1;i<=num;i++) {
            r2=r2*i;
        }
        printf("%d!=%Lf\n",num,r2);
    }
    
    return 0;
    */
}


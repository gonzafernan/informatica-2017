//
//  ej13.c
//  Informatica-2017
// Escriba un programa que:
//a. Lea por teclado 3 valores M, N y P
//b. Cree 4 matrices dinámicamente con valores aleatorios:
//    i. 2 de M x N
//    ii. 2 de N x P
//c. Lea por teclado un factor de escala double
//d. Escale las 4 matrices generadas en (b) por el factor s
//e. Calcule el producto matricial de a pares, generando 2 matrices C1 y C2 de MxP
//elementos cada una
//f. Calcule la transpuesta de C2
//g. Calcule el producto de C1 x C2(transpuesta)(MxP y PxM respectivamente)
//h. Muestre los resultados intermedios por pantalla
//i. Libere la memoria dinámica utilizada

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"ejercicios.h"

void ej13(){
int M,N,P;
srand(time(NULL));
double s;
//(a)
  printf("escriba los valores enteros M,N y P: \n");
  scanf("%d %d %d",&M,&N,&P);
  //(b) matrices aleatrias
  double **A,**B,**C,**D; //generar los espacios de memoria
  A=ej7(M,N);
  B=ej7(M,N);
  C=ej7(N,P);
  D=ej7(N,P);

  ej10(A,M,N);//aca no estoy seguro como pasar el apuntador de la matriz al ej10(creo que es por referencia por que quiero que se modifiquen las matrices)
  printf("la matriz A es:\n");
  ej11(A,M,N);
  ej10(B,M,N);
  printf("la matriz B es:\n");
  ej11(B,M,N);
  ej10(C,N,P);
  printf("la matriz C es:\n");
  ej11(C,N,P);
  ej10(D,N,P);
  printf("la matriz D es:\n");
  ej11(D,N,P);

  //(d) escalar por s usando el ej9
  printf("Ingrese el factor:\n");
  scanf("%lf",&s);

  ej9(A,M,N,s);
  printf("la matriz A escalada por %lf es:\n",s);
    ej11(A,M,N);
  ej9(B,M,N,s);
  printf("la matriz B escalada por %lf es:\n",s);
    ej11(B,M,N);
  ej9(C,N,P,s);
  printf("la matriz C escalada por %lf es:\n",s);
    ej11(C,N,P);
  ej9(D,N,P,s);
  printf("la matriz D escalada por %lf es:\n",s);
    ej11(D,N,P);

  //(e) producto de matrices AxC y BxD
  double **C1,**C2;
  printf("la matriz C1=AxC es:\n");
  C1=ej8(A,C,M,N,P);
  printf("la matriz C2=BxD es:\n");
  C2=ej8(B,D,M,N,P);

  //(f)matriz transpuesta de C2 (lo pase por referencia para que cambie el valor de c2 pero este si que no se como anda por que no solo cambiarian los valores tambien las filas y columnas)
  ej12(C2,M,P);
  printf("la matriz C2 transpuesta es:\n");
    ej11(C2,M,P);
  //(g)producto de matrices
  double **C3;
printf("la matriz C3=C1xC2 es:\n");
  C3=ej8(C1,C2,M,P,M);
//(h) liberar los espacios de memoria
int i;
for (i=0;i<M;i++){
  free(A[i]);
  free(B[i]);
  free(C1[i]);
  free(C3[i]);
}
 for (i=0;i<N;i++){
   free(C[i]);
   free(D[i]);
}
 for (i=0;i<P;i++){
   free(C2[i]);
 }
 free(A);
 free(B);
 free(C);
 free(D);
 free(C1);
 free(C2);
 free(C3);

 }


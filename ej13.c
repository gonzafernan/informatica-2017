//
//  ej13.c
//  Informatica-2017
//Escriba un programa que
//a. Genere un vector con valore aleatorios enteros
//b. Recorra el vector y guarde el promedio de los valores en una variable
//c. Encuentre el menor de los elementos
//
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int ej13(){
  int largo,i,j,k,l;
  printf("ingrese el largo del vector (un numero entero)\n");
  scanf("%d",&largo);
long vector[largo],menor;
srand(time(NULL)); //para que en cada ejecucion del programa los valores aleatorios sean distintos
//bucle para cargar el vector con el largo asignado con numeros aleatorios
for (i=1;i<=largo;i++){
  vector[i-1]=rand();
}
//bucle para calcular el promedio
float sum=0;
for (j=1;j<=largo;j++){
  sum= vector[j-1]+sum;
}
float prom=sum/largo;
//primer comparacion
if (vector[0]<vector[1]){
  menor = vector[0];
}else{
  menor=vector[1];
}
// bucle para ver cual es el numero menor

for (k=2;k<largo;k++){
  if (menor<vector[k]){
    menor = menor;
  }else{
    menor=vector[k];
  }
}
printf("el vector de numero aleatorios fue: \n");
for (l=1;l<=largo;l++){
  printf(" %d, ",vector[l-1]);
}
printf("\n");
printf("el promedio de las componentes del vector fue: %f\n",prom);
printf("la menor de las componentes del vector fue: %d\n",menor);
return 0;
}

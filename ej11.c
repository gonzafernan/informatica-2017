//
//  ej11.c
//  Informatica-2017
//  Escribir un programa que lea un valor entero desde el teclado, y que muestre su configuración de bits por pantalla utilizando los operadores << y >>
//

#include<stdio.h>

int ej11(){
  int num, i,j, comp=1,and;
  int binario[16]; //Vector donde se guardara el numero binario de 16 bits (int)
  int cp[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
  printf("escriba el numero entero que desea conocer en binario: \n");
  scanf("%d",&num);
//Dentro del for se compara el numero con cada uno de los digitos binarios
// empezando desde el 00001 y corriendo el 1 a la izquierda y cuando encuentra
//igualdad guarda un 1 en la posicion correspondiente  del vector binario
  for (i=1;i<=16 ;i++){
    and=num&comp;
    if (and==cp[i-1]){
      binario[(i-1)]=1;
    }
    else{
    binario[(i-1)]=0;
    }
  comp=comp<<1;
  }
//Display del vector binario ordenado como el numero binario al que corresponde
  printf("el numero %d en binario es: \n",num);
  for (j=1;j<=16;j++){
    printf("%d",binario[15-(j-1)]);
  }
  return 0;
}

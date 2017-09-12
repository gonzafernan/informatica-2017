
//
//  ej14.c
//  Informatica-2017
//  Escriba un programa que calcule el producto de 2 matrices A x B = C, con Amn, Bnp.
//

#include <stdio.h>

int ej14(){
int m,n,p,i,j,k,cerosf,cerosc;
printf("ingrese numero de filas de la primer matriz y de columnas de la primer matriz   (con el formato mxn):\n");
scanf(" %dx%d",&m,&n);
printf("ingrese el numero de columnas de la segunda matriz: \n");
scanf(" %d",&p);
float A[m][n],B[n][p],C[m][p];
//cargar las matrices de arriba hacia abajo e izquierda a derecha
printf("la carga de los valores de las matrices se realizara de arriba hacia abajo y luego izquierda a derecha\n");
for (i=1;i<=n;i++){ //columnas
  for (j=1;j<=m;j++){ //filas
    printf("Primer matriz, ingrese el numero correspondiente a la columna %d y  fila %d: ",i,j);
    scanf(" %f",&A[j-1][i-1]);
  }
}
for (i=1;i<=p;i++){
  for (j=1;j<=n;j++){
    printf("Segunda matriz,ingrese el numero correspondiente a la columna %d y  fila %d: ",i,j);
    scanf(" %f",&B[j-1][i-1]);
  }
}
//llenar matriz producto con ceros
for (cerosc=1;cerosc<=p;cerosc++){
  for (cerosf=1;cerosf<=m;cerosf++){
    C[cerosf-1][cerosc-1]=0;
  }
}
//producto de matrices
for (i=1;i<=p;i++){ //columnas de C
  for (j=1;j<=m;j++){ //filas de C
    for (k=1;k<=n;k++){
        C[j-1][i-1]=A[j-1][k-1]*B[k-1][i-1]+C[j-1][i-1];
      }
  }
}
//display de las matrices
printf(" Matriz A: \n");
for (i=1;i<=m;i++){//filas de A
  for(j=1;j<=n;j++){//columnas de A
    printf(" %f ",A[i-1][j-1]);
  }
  printf("\n");
}
printf("\n Matriz B: \n");
for (i=1;i<=n;i++){//filas de B
  for(j=1;j<=p;j++){//columnas de B
    printf(" %f ",B[i-1][j-1]);
  }
  printf("\n");
}
printf("\n Matriz C (producto AxB): \n");
for (i=1;i<=m;i++){//filas de C
  for(j=1;j<=p;j++){//columnas de C
    printf(" %f ",C[i-1][j-1]);
  }
  printf("\n");
}
  return 0;
}

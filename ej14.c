//
//  ej14.c
//  Informatica-2017
// Escriba un programa que calcule el producto de 2 matrices A x B = C, con Amn, Bnp.
//
#include <stdio.h>

int ej14(){
int m,n,p,i,j,k,l,e,f,g,cerosf,cerosc,h,d,q,r,s,t;
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
for (k=1;k<=p;k++){
  for (l=1;l<=n;l++){
    printf("Segunda matriz,ingrese el numero correspondiente a la columna %d y  fila %d: ",k,l);
    scanf(" %f",&B[l-1][k-1]);
  }
}
//llenar matriz producto con ceros
for (cerosc=1;cerosc<=p;cerosc++){
  for (cerosf=1;cerosf<=m;cerosf++){
    C[cerosf-1][cerosc-1]=0;
  }
}
//producto de matrices
for (e=1;e<=p;e++){ //columnas de C
  for (f=1;f<=m;f++){ //filas de C
    for (g=1;g<=n;g++){
        C[f-1][e-1]=A[f-1][g-1]*B[g-1][e-1]+C[f-1][e-1];
      }
  }
}
//display de las matrices
printf(" Matriz A: \n");
for (h=1;h<=m;h++){//filas de A
  for(d=1;d<=n;d++){//columnas de A
    printf(" %f ",A[h-1][d-1]);
  }
  printf("\n");
}
printf("\n Matriz B: \n");
for (q=1;q<=n;q++){//filas de B
  for(r=1;r<=p;r++){//columnas de B
    printf(" %f ",B[q-1][r-1]);
  }
  printf("\n");
}
printf("\n Matriz C (producto AxB): \n");
for (s=1;s<=m;s++){//filas de C
  for(t=1;t<=p;t++){//columnas de C
    printf(" %f ",C[s-1][t-1]);
  }
  printf("\n");
}
  return 0;
}

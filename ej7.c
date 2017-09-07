//
//  ej7.c
//  Informatica-2017
//  Escribir un programa que calcule el factorial de un número y muestre el valor por pantalla
//
//

#include <stdio.h>

int ej7(){
    int num,i;
    long double r=1;
    
    printf("Ingresar número: \n");
    scanf("%d",&num);

    if (num<0){
        printf("Math ERROR\n");
    } else if (num==0){
        printf("0!=1\n");
    } else {
        //Ciclo iterativo for
        for (i=1;i<=num;i++) {
            r=r*i;
        }
        printf("%d!=%Lf\n",num,r);
        
    }
    
    return 0;
}

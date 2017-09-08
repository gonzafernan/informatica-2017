//
//  ej8.c
//  Informatica-2017
//  Escribir un programa que permita ingresar por teclado un valor inicial a, un valor final b, y un número c, y que cuente la cantidad de números divisibles por c que hay en el rango [a,b].
//
//

#include <stdio.h>

int ej8(){
    int a,b,c,i,r=0;
    printf("Ingrese valor inicial, final y número, en el respectivo orden: \n");
    scanf("%d%d%d",&a,&b,&c);
    for (i=a;i<=b;i++){
        if (i%c==0){
            r++;
        }
    }
    printf("Hay %d números divisibles por %d.\n",r,c);
    
    return 0;
}

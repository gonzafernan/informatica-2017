//
//  ej4.c
//  Informatica-2017
//  Escribir un programa que lea 2 números enteros por teclado y que calcule:
//  El número que contiene sólo los bits que son 1 en ambos números
//  El número que contiene los bits que son 1 en alguno de los números
//

#include <stdio.h>

int ej4(){
    int num1,num2,ina,inb;
    printf("Ingrese dos número enteros: \n");
    scanf("%d%d",&num1,&num2);
    ina = num1&num2;
    inb = num1|num2;
    printf("Inciso a: %d \nInciso b: %d\n",ina,inb);
    return 0;
}

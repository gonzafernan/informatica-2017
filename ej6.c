//
//  ej6.c
//  Informatica-2017
//  Escribir un programa que le pida al usuario una fecha del estilo DD/MM/AAAA y determine:
//  a. El día anterior y posterior.
//  b. El último día del mes y cuantos días faltan para el mismo.
//  Considere la existencia de los años bisiestos.
//

#include "ej6.h"
#include <stdio.h>

//Definición tipo de dato booleano
typedef int boolean;
#define TRUE 1
#define FALSE 0

int ej6(){
    int day,month,year;
    boolean bisiesto;
    printf("Ingrese fecha en formato DD/MM/AAAA: \n");
    scanf("%d/%d/%d",&day,&month,&year);
    //Determinación si el año es bisiesto
    bisiesto=(year%4==0)&&((year%100!=0)||(year%400==0));
    
    printf("%d \n",bisiesto);
    return 0;
}

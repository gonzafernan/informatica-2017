//
//  ej5.c
//  Informatica-2017
//  Escribir un programa que resuelva los valores resultantes de funciones multivariables.
//  Considere las variables como valores enteros que se le piden al usuario.
//

#include "ej5.h"
#include <stdio.h>
#include <math.h>

int ej5(){
    int a,b,c,d,e,f;
    float x,y;
    printf("Ingrese valores de a, b, c, d, e y f en ese orden: \n");
    scanf("%f%f%f%f%f%f",&a,&b,&c,&d,&e,&f);
    x=(3*a+b)/(c-((d+5*e)/(a-b)));
    y=3*pow(a,4)-5*pow(b,3)+12*c-7;
    printf("x=%f \n y=%f \n",x,y);
    return 0;
}

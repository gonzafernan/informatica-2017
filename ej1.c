//
//  ej1.c
//  Informatica-2017
//  Escribir un programa que pida 3 números por pantalla e identifique cual es el valor central, si es posible.
//  Ej. a es central si y solo si b > a > c.
//
//  Created by Gonzalo Gabriel Fernández on 8/30/17.
//  Copyright © 2017 Gonzalo Gabriel Fernández. All rights reserved.
//

#include "ej1.h"
#include <stdio.h>

int ej1(){
    int num1,num2,num3; //Declaración de variables
    printf("Ingresar tres números: \n");
    scanf("%d%d%d",&num1,&num2,&num3);  //Ingreso de variables
    //Bloque condicional
    if (((num1<num2)&&(num2<num3))||((num3<num2)&&(num2<num1))){
        printf("%d es el valor central\n",num2);
    } else if (((num2<num1)&&(num1<num3))||((num3<num1)&&(num1<num2))){
        printf("%d es el valor central\n",num1);
    } else if (((num1<num3)&&(num3<num2))||((num2<num3)&&(num3<num1))){
        printf("%d es el valor central\n",num3);
    } else {
        printf("Algunos de los valores son iguales\n");
    }
    return 0;
}

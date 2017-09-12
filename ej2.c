//
//  ej2.c
//  Informatica-2017
//  Elaborar un algoritmo en el cual se ingrese una letra y se detecte si se trata de una vocal o cualquier otro tipo de caracter.
//

#include <stdio.h>

int ej2(){
    char letra;
    printf("Ingrese caracter: \n");
    scanf(" %c",&letra);
    //Bloque condicional switch
    switch (letra) {
        case 'a':
            printf("%c es una vocal\n",letra);
            break;
        case 'e':
            printf("%c es una vocal\n",letra);
            break;
        case 'i':
            printf("%c es una vocal\n",letra);
            break;
        case 'o':
            printf("%c es una vocal\n",letra);
            break;
        case 'u':
            printf("%c es una vocal\n",letra);
            break;
        //Bloque opcional para agregar vocales mayúsculas
        case 'A':
            printf("%c es una vocal\n",letra);
            break;
        case 'E':
            printf("%c es una vocal\n",letra);
            break;
        case 'I':
            printf("%c es una vocal\n",letra);
            break;
        case 'O':
            printf("%c es una vocal\n",letra);
            break;
        case 'U':
            printf("%c es una vocal\n",letra);
            break;
        default:
            printf("El caracter no es una vocal\n");
            break;
    }
    return 0;
}

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
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        //Bloque opcional para agregar vocales mayúsculas
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            printf("%c es una vocal\n",letra);
            break;
        default:
            printf("El caracter no es una vocal\n");
    }
    return 0;
}

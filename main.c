//
//  main.c
//  Informatica-2017
//

#include <stdio.h>
#include "ej1.h"
#include "ej2.h"
#include "ej3.h"
#include "ej4.h"
#include "ej5.h"
#include "ej6.h"
#include "workspace.h"
int main() {
   int ejercicio;
   printf("Ingrese el número del ejercicio a ejecutar:\n");
    scanf("%d",&ejercicio);
    switch (ejercicio) {
            case(1):
              ej1();
            break;
            case(2):
              ej2();
            break;
            case(3):
              ej3();
            break;
            case(4):
               ej4();
            break;
            case(5):
              ej5();
            break;
            case(6):
               ej6();
            break;
            //incluir desde aca todos los ejercicios siguientes
        default:
            printf("No existe tal ejercicio o no esta hecho");
    }
   printf("Dónde está Santiago Maldonado?");
        
    return 0;
}

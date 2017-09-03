//
//  ej3.c
//  Informatica-2017
//La compañía de celulares “Chismefon” posee un mecanismo de cobro de llamadas por el cual mientras más se habla, menos se paga.
//De esta forma los primeros cinco minutos cuestan $ 1.00 c/u, los siguientes tres, $ 0.80 c/u, los siguientes dos minutos, $ 0.70 c/u, y a partir del décimo minuto, 0.50 c/u (los valores no incluyen IVA).
//Realice un programa para determinar el costo total de una llamada expresada en segundos.
//

#include "ej3.h"
// Por qué el include de arriba tiene comillas? No se supone que era o con <> o con **? 
#include <stdio.h>
#include <math.h>

int ej3(){
    int temp1=5,temp2=3,temp3=2;
    float tarif1=0.8,tarif2=0.7,tarif3=0.5,tiempo,costo=0;
    printf("Ingrese duración de la llamada en segundos: \n");
    scanf("%f",&tiempo);
    tiempo = ceil(tiempo/60);
    if (tiempo<=temp1){
        costo = tiempo;
    } else if (tiempo<=(temp1+temp2)){
        costo = temp1+(tiempo-temp1)*tarif1;
    } else if (tiempo<=(temp1+temp2+temp3)){
        costo = temp1+temp2*tarif1+(tiempo-(temp1+temp2))*tarif2;
    } else if (tiempo>=(temp1+temp2+temp3)){
        costo = temp1+temp2*tarif1+temp3*tarif2+(tiempo-(temp1+temp2+temp3))*tarif3;
    }
    printf("El costo de la llamada es: $%f \n",costo);
    return 0;
}

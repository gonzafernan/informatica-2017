#include <stdio.h>
#include <stdlib.h>

int cont = -1;
int i, j;
struct struct_nodo{
    int valor;
    int posicion[2];
    struct struct_nodo * izquierda;
    struct struct_nodo * derecha;
    struct struct_nodo * arriba;
    struct struct_nodo * abajo;
    // struct struct_nodo * izqarriba;
    // struct struct_nodo * izqabajo;
    // struct struct_nodo * derarriba;
    // struct struct_nodo * derabajo;
};
typedef struct struct_nodo NODO;

NODO* apuntador[10];
int buffer[2][500];


void recorre(NODO * actual, int B[2]){ // el primer actual es el NODO apuntador[i][j] con i y j siendo la posición de A
    cont++;
    buffer[0][cont] = actual -> posicion[0];
    buffer[1][cont] = actual -> posicion[1];
    if (actual -> posicion[0] == B[0] && actual -> posicion[1] == B[1]){
        actual -> valor = 777;
        printf("TERMINAR PROCESO, CAMINO ENCONTRADO");
        for (i=cont+1; i<100; i++){ // Limpia el resto del buffer que no corresponde al camino
            buffer[0][i] = 0;
            buffer[1][i] = 0;
        }
        for (i=0;i<cont+1;i++){
            printf("(%d,%d)", buffer[0][i], buffer[1][i]);
        }
        printf("\n");
        for (i=0;i<10;i++){ //algoritmo para mostrar la matriz
            for (j=0;j<10;j++){
                printf(" %d ",apuntador[i][j].valor);
                }
                printf("\n");
            }
        abort();
    }
    if (actual -> izquierda -> valor == 0){
        actual -> valor = 7;
        recorre(actual -> izquierda, B);
        actual -> valor = 0;
        cont--; // El contador disminuirá de manera que la siguiente instrucción de if utilice el mismo valor de contador
    }
    if (actual -> derecha -> valor == 0){
        actual -> valor = 7;
        recorre(actual -> derecha, B);
        actual -> valor = 0;
        cont--;
    }
    if (actual -> abajo -> valor == 0){
        actual -> valor = 7;
        recorre(actual -> abajo, B);
        actual -> valor = 0;
        cont--;
    }
    if (actual -> arriba -> valor == 0){
        actual -> valor = 7;
        recorre(actual -> arriba, B);
        actual -> valor = 0;
        cont--;
    }
}

int main(){
    for (i=0; i<10; i++){
        apuntador[i] = calloc(10, sizeof(NODO));
    }

    int matriz[10][10] = {
                            {1, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                            {1, 1, 0, 0, 0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 1, 0, 0, 0 ,0},
                            {0, 1, 0, 0, 0, 1, 1, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0, 1, 1, 1 ,1},
                            {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                            {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
                                                            };


    NODO muro;
    muro.valor = 1;
    muro.izquierda = NULL;
    muro.derecha = NULL;
    muro.arriba = NULL;
    muro.abajo = NULL;
    // muro -> izqarriba = NULL;
    // muro -> izqabajo = NULL;
    // muro -> derarriba = NULL;
    // muro -> derabajo = NULL;

    // ASIGNACIÓN DE NODOS ENLAZADOS

    for (i=0; i<10; i++){
        for (j=0; j<10; j++){
            apuntador[i][j].valor = matriz[i][j];
            apuntador[i][j].posicion[0] = i;
            apuntador[i][j].posicion[1] = j;
            if (i==0){
                apuntador[i][j].izquierda = &muro;
            } else {
                apuntador[i][j].izquierda = &apuntador[i-1][j];
            }
            if (i==9){
                apuntador[i][j].derecha = &muro;
            } else {
                apuntador[i][j].derecha = &apuntador[i+1][j];
            }
            if (j==0){
                apuntador[i][j].arriba = &muro;
            } else {
                apuntador[i][j].arriba = &apuntador[i][j-1];
            }
            if (j==9){
                apuntador[i][j].abajo = &muro;
            } else {
                apuntador[i][j].abajo = &apuntador[i][j+1];
            }
        }
    }
    for (i=0;i<10;i++){ //algoritmo para mostrar la matriz
          for (j=0;j<10;j++){
              printf(" %d ",apuntador[i][j].valor);
              }
              printf("\n");
          }

    int A[2];
    int B[2];
    // Recibe posición completando A y B
    printf("\n Ingrese en modo de coordernada (x,y) el punto inicial A (tomar en cuenta que el (0,0) es el extremo izquierdo superior):\n");
    scanf(" (%d,%d)",&A[0],&A[1]);
    printf("ingrese en modo de coordernada (x,y) el punto final B :\n");
    scanf(" (%d,%d)",&B[0],&B[1]);

    apuntador[A[0]][A[1]].valor = 666;

    // Reservo en memoria un buffer de ceros que irá guardando el camino recorrido

    recorre(&apuntador[A[0]][A[1]], B); // el primer actual es el NODO apuntador[i][j] con i y j siendo la posición de A
  /*for (i=0;i<10;i++){ //algoritmo para mostrar la matriz
        for (j=0;j<10;j++){
            printf(" %d ",apuntador[i][j].valor);
            }
            printf("\n");
        }*/
    for (i=0;i<50;i++){
        printf("(%d,%d)", buffer[0][i], buffer[1][i]);
    }

printf("\ncamino imposible\n");
    // for (i=0;i<2;i++){ //algoritmo para mostrar la matriz
    //     for (j=0;j<100;j++){
    //         printf("%d", buffer[i][j]);}
    //         printf("\n");}
return 0;
}


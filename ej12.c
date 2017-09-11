/*
Escriba un programa que lea por teclado 3 coeficientes a, b y c, un valor inicial x1, un valor
final x2 y un un incremento delta, y que calcule p(x) utilizando la función que se muestra a
continuación, en el intervalo [x1, x2], según el incremento delta. Muestre los valores
calculados por pantalla.
p ( x )=ax^2+bx+c
*/

#include <stdio.h>
#include <math.h>

int ej12(){
   float a, b, c, x1, x2, delta;
   int tam, i;
   printf("Ingrese en orden los coeficientes a, b y c\n");
   scanf("%f%f%f",&a,&b,&c);
   printf("Ingrese en orden Valor Inicial, Valor Final e Incremento\n");
   scanf("%f%f%f",&x1,&x2,&delta);
   //tam: tamaño del vector función y vector variable.
   //Redondea hacia arriba el cociente y luego agrega 1 para el valor x=x2.
   //La función fabs creo que hace esto mismo (truncaría al entero) pero lo puse así para que vean el razonamiento.
   //Ej: x1=2, x2=4, delta=0.5; tam=5 (2; 2.5; 3; 3.5; 4)
   //Ej: x1=2, x2=4.1, delta=0.5; tam=6 (2; 2.5; 3; 3.5; 4; 4.1)
   tam=ceil((x2-x1)/delta);
   tam=tam+1;
   float P[tam];
   float V[tam];
   for (i=1; i<=tam; i++){
      if (i==1){
         V[(i-1)]=x1;
      } else if (i==tam){
         V[(i-1)]=x2;
      } else { V[(i-1)]= x1+(i-1)*delta;
      } P[(i-1)]= a* pow(V[(i-1)],2) +b* V[(i-1)] +c;
      printf("Para x= %f ==>  P(x)= %f\n", V[(i-1)], P[(i-1)]);
   }
return 0;
}

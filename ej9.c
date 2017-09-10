#include <stdio.h>

int ej9(){

float i,j,s=0;
  int k=0;

  for (i=0; i<=100;i++){
    for (j=0; j<=100; j++){
      k++;
      if (i==j){
        continue;
      }
      s=s+((i+j)/(i-j));
    }
  }
  printf("El resultado es: %lf\nHubo %d itereichons\n", s,k);
  return 0;
}

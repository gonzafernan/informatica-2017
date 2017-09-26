/*
Ejercicio 14 - TP4 - Informática 2017

La Sucesión de Fibonacci viene dada por las siguientes ecuaciones
F(n)=F(n-1)+F(n-2)
F(0)=1
F(1)=1
Escriba un afuncinón recursiva que reciva como argumento un entero n,
y que calcule la sucesión hasta el valor F(n)
*/

#include <stdio.h>

int fib(int n){
    //int ans;
    if (n==0||n==1){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
    //return ans;
}

int ej14(){
    int m,i;
    printf("Ingrese el término hasta el cual quiere saber la sucesión de Fibonacci (el primer término es el término 0)\n");
    scanf("%d",&m);
    if (m<0){
        printf("Ingrese un valor mayor o igual a 0\n");
        return 0;
    }
    printf("La sucesión hasta el término %d es:\n",m);
    for (i=0;i<=m;i++){
        printf("%d ",fib(i));
        if (i==(m)){
            printf("\n");
        }
    }
    return 0;
}

/*
int ej14(){
    int n,i;
    printf("Ingrese el término hasta el cual quiere saber la sucesión de Fibonacci\n");
    scanf("%d",&n);
    unsigned long long fibo[n];
    printf("La sucesión de Fibonacci hasta el término %d es\n",n);
    
    fibo[0]=1;
    fibo[1]=1;
    
    for(i=2;i<=n-1;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    
    for(i=0;i<=n-1;i++){
        printf("%llu ",fibo[i]);
        if(i==n-1){
            printf("\n");
        }
    }
    return 0;
}
*/

//
//  ej6.c
//  Informatica-2017
//  Escribir un programa que le pida al usuario una fecha del estilo DD/MM/AAAA y determine:
//  a. El día anterior y posterior.
//  b. El último día del mes y cuantos días faltan para el mismo.
//  Considere la existencia de los años bisiestos.
//

include "ej6.h"
#include <stdio.h>

//Definición tipo de dato booleano
typedef int boolean;
#define TRUE 1
#define FALSE 0

int ej6(){
    
    //Declaración de variables.
    int day,month,year,daya=0, montha=0, yeara=0, dayb=0, monthb=0, yearb=0, dayl=0, numdays=0; //daya: day after dayb: day before dayl: last day.
    boolean bisiesto,m30;
    
    //Datos de entrada.
    printf("Ingrese fecha en formato DD/MM/AAAA: \n");
    scanf("%d/%d/%d",&day,&month,&year);
    
    //Determinación si el año es bisiesto
    bisiesto=(year%4==0)&&((year%100!=0)||(year%400==0));
    
    //Ubicación en el calendario.
    //Meses con 30 días
    m30=(month==4||month==6||month==9||month==11);
    
    //Fechas normales, se actualizarán en caso de ser fechas límites
    daya=day+1;
    dayb=day-1;
    montha=month;
    monthb=month;
    yeara=year;
    yearb=year;
    
    //Bloque condicional
    //Condicional meses con treinta días.
    if (m30){
        if (day==30){
            daya=1;
            montha=month+1;
            
        } else if (day==1){
            dayb=31;
            monthb=month-1;
        }
        dayl=30;
        numdays=dayl-day;
    } else if (month==2){   //Condicional para febrero
        if (day==1){
            dayb=31;
            monthb=1;
        } else if (day==29){
            daya=1;
            montha=3;
        } else if (day==28){
            if (bisiesto==FALSE){
                daya=1;
                dayb=27;
                montha=3;
            }
            if (bisiesto) {
                dayl=29;
            } else {
                dayl=28;
            }
        }
        numdays=dayl-day;
    } else {    //Condicional meses con trenta y un días
        if (day==31){
            daya=1;
            montha=month+1;
            if (month==12){
                yeara=year+1;
                month=1;
            }
        } else if (day==1){
            if (month==8||month==1){
                dayb=31;
            } else if (month==3){
                if (bisiesto) {
                    dayb=29;
                }else {
                    dayb=28;
                }
            } else {
                dayb=30;
            }
            if (month==1){
                yearb=year-1;
                monthb=12;
            }
        }
        dayl=31;
        numdays=dayl-day;
    }
    
    //Datos de salida.
    printf("Fecha del día anterior: %d/%d/%d \n",dayb,monthb,yearb);
    printf("Fecha del día posterior: %d/%d/%d \n",daya,montha,yeara);
    printf("Fecha del último día del mes: %d/%d/%d \n Faltan %d días para finalizar el mes.\n",dayl,month,year,numdays);
    return 0;
}

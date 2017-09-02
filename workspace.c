//
//  workspace.c
//  Informatica-2017
//
//  Created by Gonzalo Gabriel Fernández on 8/30/17.
//  Copyright © 2017 Gonzalo Gabriel Fernández. All rights reserved.
//

#include "workspace.h"
#include <stdio.h>

int workspace(){
    int num1,num2;
    scanf("%d%d",&num1,&num2);
    if (num1<num2){
        printf("OK");
    }
    return 0;
}

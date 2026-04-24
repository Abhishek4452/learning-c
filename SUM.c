/*
STATUS = DONE
description - program to add 2 number without using the + operator
*/ 
#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t a,b,sum,carry;
    printf("enter 2 numbers : ");
    scanf("%d %d",&a,&b);
    while(b != 0){
        sum = a^b;
        carry = (a&b)<<1;
        a = sum;
        b = carry;
    }
    printf("sum will be %d\n",a);
}
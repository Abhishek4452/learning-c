/*
*       this file is linked with the math.c fi
*  In order to run this file - save both file then 
* write command >> gcc main.c math.c -o myprogram
* ./myprogram
*/



#include <stdio.h>

int mainPrivateData = 0;
void printData(void);

int main(){
    printf(" mainPrivateData : %d \n", mainPrivateData);
    printData();
    printf(" mainPrivateData : %d \n", mainPrivateData);
    return 0;
}
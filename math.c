/*
*                   this file is made for the use of the main.c 
*               objective - to understand the working of static and global variable
*
*/

#include <stdio.h>
extern int mainPrivateData;

void printData(void){
    mainPrivateData = 10;
    printf(" mainPrivate data : %d \n",mainPrivateData);
}
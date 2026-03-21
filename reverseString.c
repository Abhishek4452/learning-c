/* STATUS - Done 
description - 5.  **Reverse String** [Easy] - *Why:* Classic two-pointer technique on a char array .
*/
#include <stdio.h>
#include <string.h>
void reverse(char *arr,int size);
void swap_char(char *a,char *b);

int main(){
    char str[] = "ABHISHEK";
    
    //print_string(str,strlen(str));
    reverse(str,strlen(str));
    //print_string(str,strlen(str));
    printf("%s \n",str);
    return 0;
}

void reverse(char *arr,int size){
    for(int i=0;i<(size/2);i++){
        swap_char(&arr[i],&arr[size-i-1]);
    }
}
void swap_char(char *a,char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

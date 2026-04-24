//status = not yet completer using operator
// program to differ 2 number without using the - operator
#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t a,b;
    printf("enter 2 numbers : ");
    scanf("%d %d",&a,&b);
    
    while(b != 0){
        a--;
        b++;
    }
    printf("addition will be : %d \n", a);
}
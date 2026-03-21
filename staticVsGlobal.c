#include <stdio.h>

void print(void){
    static int var =0;
    printf("%d \n",var);
    var = var+1;

}

int main(){
    printf(" welcome to the task control panel ! \n");
    
    print();
    print();
    print();
    return 0;
}
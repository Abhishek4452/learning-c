/*status - done
desc -19. **Power of Two** [Easy] - *Why:* Checks understanding of bit patterns (only one bit set) .
*/
#include<stdio.h>
void pwrOfTwo(int n);
int main(){
    int a = 8;
    pwrOfTwo(a);
    return 0;
}

void pwrOfTwo(int n){
    if(n%2 == 0){
        // return pwr
        int count= 0;
        while((n != 0) && (n%2 == 0)){ 
                count++;
                n = (n/2);  
        }
        if(n == 1){
            printf("number of count %d \n",count);
        }
        else{
            printf("number can't be represent in form of 2 the pwr something\n");
        }

        return;
    }
    else{
        printf(" number can't be represented in pwr of 2 \n");
        return;
    }
}
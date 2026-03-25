/* status - done
description- *Number of 1 Bits** [Easy] - *Why:* Population count is used in parity calculations and error detection . how to do this thing in C
*/

#include <stdio.h>
int oneNumber(int a){
    int count =0;

    while(a>0){
        count += (a&1);
        a = (a>>1);
    }
    return count;
}
int main(){
    int num = 29;
    printf("number of 1 is : %d \n",oneNumber(num));
    return 0;
}
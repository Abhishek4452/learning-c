/* status -
desc -18. **Reverse Bits** [Easy] - *Why:* Tests your understanding of endianness and bit order, vital for SPI protocols .
*/
#include <stdio.h>
#include <stdint.h>
uint32_t RBit(int num){
    uint32_t num2 = 0;
    for(int i=0;i<32;i++){
        num2 = (num2<<1)|(num&1);
        num = num>>1;
    }
    return num2;
}
int main(){
    int num = 29;
    printf(" num is : %d \n",RBit(num));
    return 0;
}
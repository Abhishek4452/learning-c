/* status - not yet done
desc- 16. **Single Number** [Easy] - *Why:* XOR tricks are essential for parity, checksums, and toggling bits without a temp variable .
*/
/* learning -
                x >> n  ≈  x / (2^n)
                int y = 0x5;   // hexadecimal representation
*/

#include <stdio.h>
#include <stdint.h>
void printBinary(int n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int main(){
    int8_t temp = 2;
    temp |= (1<<0); // insert 1 at the end (binary << idx_from right)
    printf("%d \n",temp); //3
    temp &= (1<<0);
    printf("%d \n",temp);
    temp = ~temp;
    printf("%d \n",temp);

    printf("check parity \n");
    int8_t rand = 0b11111111; // rprintf("%d parity \n",rand);
    printBinary(rand);
    rand ^= 0b01;
    printBinary(rand);
    printf("xor operation 11111110; \n");
    rand ^= 0b101101;
    printBinary(rand);
    printf("toggling a bit\n");  // all bits are toggling by the not operator 
    rand = ~rand;
    printBinary(rand);
    printf("shifting of the bits: \n");
    int8_t rand2 = 0b11111111;
    rand2 = (rand2>>5)&11;
    printBinary(rand2);

    return 0;
}
/* status -  done
42. **Squares of a Sorted Array** [Easy] - *Why:* Two-pointer technique on sorted data .*/

#include <stdio.h>
#include <stdint.h>
int a[] = {1,2,3,4,5,6};
int square(int num);
void twiceArray(int* arr,int size);
void printArray(int* arr,int size);

int main(){
    
    printArray(a,6);
    twiceArray(a,6);
    printArray(a,6);
    return 0;
}
int square(int num){
    return num*num;
}
void twiceArray(int* arr,int size){
    for(int i =0; i<= ((size-1)/2);i++){
        arr[i] = square(arr[i]);
        arr[size-1-i] = square(arr[size-1-i]);
    }
}
void printArray(int* arr,int size){
    for(int i=0; i< size;i++){
        printf("%d ",arr[i]);
    }
printf("\n");
}


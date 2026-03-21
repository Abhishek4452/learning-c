/*STATUS- DONE 
description: 6.  **Move Zeroes** [Easy] - *Why:* Maintaining order while manipulating an array in-place .*/

#include <stdio.h>
// function declaration
void moveZero(int *arr,int size);
void printArray(int *arr,int size);
int main(){
    int arr[] = {1,2 ,3,4,5,0,2,3,4,5,6,70,0,9,8,7,0,9,8,9,0,8};
    int length = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,length);
    moveZero(arr,length);
    printArray(arr,length);
    return 0;
}
// function defination

void moveZero(int *arr,int size){
    int count_zero = 0;
    int k=0; // set the indexing of the array which contain non zero element
    for(int i;i<size;i++){ // moving the non zero element toward zero index
        if(arr[i] != 0){
            arr[k] = arr[i];
            k++;
        }
        else{
            count_zero++;
        }
    }
    int k0 = k;
    // moving the zeros in end position 
    for (k0;k <= (k0+count_zero-1);k++){
        arr[k] = 0;
    }
}
void printArray(int *arr,int size){
    for (int i =0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

/* STATUS - not yet done
description **Find All Numbers Disappeared in an Array** [Easy] - *Why:* Using the array itself as a hash table to save space .
*/

#include <stdio.h>
void insertion_sort(int *arr,int size);
void disappered_is(int* arr,int size);
int main(){
    return 0;
}
void insertion_sort(int *arr,int size){
    for(int i=1;i<size;i++){
        int key= arr[i];
        int j= i-1;
        while(j>=0 && arr[j]>key ){
            arr[j+1]= arr[j];// swap with the previous
            j--;
        }
        arr[j+1] =key;
    }
}
void disappered_is(int* arr,size){
    
    insertion_sort(&arr,size);
    int key_begin = arr[0];
    int key_end = arr[size];
    int temp = 0;
    while(temp >= arr[size]){
        

    }
}
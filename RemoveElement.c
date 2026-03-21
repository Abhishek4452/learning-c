/*  status -  DONE
description -  **Remove Element** [Easy] - *Why:* More in-place logic; useful for filtering sensor data .
*/

#include <stdio.h>
#include <stdlib.h>
// function declaration
int Remove_element(int *arr,int size,int val);
void print_array(int *arr,int size);
int main(){
    int arr[] = {1 ,2 ,3 ,6 ,3,22,67,86,23,976,2,9,2,5};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    print_array(arr,arr_size);
    arr_size = Remove_element(arr,arr_size,2);
    print_array(arr,arr_size);
    return 0;
}
// function defination
int Remove_element(int *arr,int size,int val){
    int k =0;
    for (int i=0; i<size ;i++){
        if (arr[i] != val){
            arr[k] = arr[i];
            k++;
        }
    }
    return k;
}
void print_array(int *arr,int size){
    for (int i=0 ; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
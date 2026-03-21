/* STATUS -  not yet done
descritipon -**Merge UnSorted Array** [Easy] - *Why:* Understanding memory overlap and merging data streams .
*/

#include <stdio.h>
// function declaration
void Insertion_sort(int *arr,int length);
void printArray(int *arr,int size);
void merge(int *a,int size_a);
int main(void){
    int a[25] = {2,3,4,7,3,2,223,554,67,764,564,342,75,453,56,86,0,0,0,0,0,0,0};
    int b[7] = {2,1,3,5,6,78,9};
    int size_a = 25
    int size_b = (sizeof(b)/sizeof(b[0]));
    merge(a,size_a);

    return 0;
}
// function defination
void merge(int *a,int size_a){
    printArray(a,size_a);

}
void Insertion_sort(int *arr,int length){
    for (int i=1; i<length;i++){
        int key = arr[i];
        int j= i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j] = key;
    }
}
void printArray(int *arr,int size){
    for (int i =0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

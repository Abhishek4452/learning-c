/*🔸STATUS - DONE

Insertion Sort (VERY common in embedded)
Time: O(n²), but:
Extremely fast for small datasets
Why it's preferred:
Simple (tiny code size)
No recursion
Deterministic timing
Works great when data is nearly sorted
👉 Best choice when:
Data size is small (common in embedded systems)
Memory is very limited*/
#include <stdio.h>
// function declaration
void Insertion_sort(int *arr,int length);
void print_array(int *arr,int size);

// body of the function
int main(){
    int array[] = {22,3,4,5,66,3,2,4,4,6,89,44};
    print_array(array,sizeof(array)/sizeof(array[0]));
    Insertion_sort(array,sizeof(array)/sizeof(array[0]));
    print_array(array,sizeof(array)/sizeof(array[0]));
    return 0;

}
// function defination
void Insertion_sort(int *arr,int length){
    for(int i= 1;i<length;i++){
        int key = arr[i]; // before this number we will sort 
        int j = i-1;
        while( j>=0 && arr[j] > key){
            arr[j+1] = arr[j]; // swap with the adjucent one
            
            j--;
        }
        arr[j+1] = key; 
    }
}
void print_array(int *arr,int size){
    for (int i=0 ; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
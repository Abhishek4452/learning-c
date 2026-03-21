/*2.    STATUS - DONE 
        **Remove Duplicates from Sorted Array** [Easy] - *Why:* In-place array manipulation to save memory .

*/      
/*  Processor to deal with this thing
    arrange data in sequence then compare and delete the element
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// function declartion
void printArray(int *arr,int size);
void merge_sort(int *arr, int left, int right);
void merge(int *arr, int left,int mid, int right);
int Remove_duplicate(int *arr,int size);
void Array_push_left(int *arr,int size,int idx);


// ==================== BODY OF THE PROGRAM =========================
int main(){
    clock_t start , end;
    start = clock();

    // start 
    int a[] = {9,3,7,1,7,4,8,2,75,32,64,653,7,2,24,3,3};
    int Array_size = sizeof(a)/sizeof(a[0]);
    printf("size of the array is : %d \n",Array_size);
    printArray(a,Array_size);
    merge_sort(a,0,Array_size-1);  // do not forget to include the left half
    printf("printing array after sorting \n");
    printArray(a,Array_size);
    Array_size = Remove_duplicate(a,Array_size);
    printf(" removing duplicate from array \n");
    printArray(a,Array_size);


    // end 
    end = clock();  // end time

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}

//==================== function defination  =========================
void merge_sort(int *arr, int left, int right){
    if(left<right){
        int mid = left + (right-left)/2;
        merge_sort(arr,left,mid);  //sort left half
        merge_sort(arr,mid+1,right);  // sort right half

        merge(arr,left,mid,right); // merge both halves
    }
}

void merge(int *arr, int left,int mid, int right){
    int n1,n2;
    n1 = mid -left+1;
    n2 = right-mid;
    int i,j,k;

    int temp_arr1[n1],temp_arr2[n2]; // temporary array
    // copy data into temporary array
    for(i =0;i<n1;i++){
        temp_arr1[i] = arr[left+i];
    }
    for(j=0;j<n2;j++){
        temp_arr2[j]= arr[mid+1+j];
    }
    i = 0; // index for L[]
    j =0; // index for r[]
    k = left; // index for merged array

    // merge the two array
    while(i<n1 && j<n2){
        if(temp_arr1[i] <= temp_arr2[j]){
            arr[k] = temp_arr1[i];
            i++;
        }
        else{
            arr[k] = temp_arr2[j];
            j++; 
        }
        k++;
    }
    //copy remaining elements
    while(i<n1){
        arr[k] = temp_arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = temp_arr2[j];
        j++;
        k++;
    }
}
 //======================== PRINTING ARRAY =====================
void printArray(int *arr,int size){
    for(int i = 0;i<size;i++){
        printf("%d \n",arr[i]);
    }
}

// ===================== Remove duplicate ======================
int Remove_duplicate(int *arr,int size){
    for(int i =0 ;i < (size-1);i++){
        if(arr[i] == arr[i+1]){
            Array_push_left(arr,size,i);
            size--;
            i--;
        }
    }
    return size;
}
// =================== left shift =============================
void Array_push_left(int *arr,int size,int idx){
    for(idx;idx <= (size-1);idx++){
        arr[idx] = arr[idx+1];
    }
}
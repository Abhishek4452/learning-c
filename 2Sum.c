/*Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]*/
#include<stdio.h>
int arr[4] = {2,7,11,15};

int TwoSum(int *arr,int len,int target,int* returnSize){
    for(int i=0;i<len;i++){
        printf("i %d \n",i);
        for(int j=i+1;j<len;j++){
            printf("j = %d ",j);
            
            if((arr[i]+arr[j])==target){
                returnSize[0] = i+1;
                returnSize[1] = j+1;
                
                return 1;
            }
        }
        printf("\n");
    }
return 0;
}
int main(void){
    
    int size[2] ;// segmentation fault occur if it was not define
    
    int target = TwoSum(arr,4,21,size);
    printf("\n");
    if (target == 1){
        for(int i =0 ; i<2;i++){
            printf("index %d\n ",size[i]);
        }
    }   
    else{
        printf("target not found \n");
    }
    return 0;
}

/*  nlogn   - time complexity
#include<stdio.h>

int binarySearch(int *arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int TwoSum_BinarySearch(int *arr, int len, int target, int* returnSize) {
    for (int i = 0; i < len - 1; i++) {
        int complement = target - arr[i];
        
        // Binary search for complement in the remaining array
        int foundIndex = binarySearch(arr, i + 1, len - 1, complement);
        
        if (foundIndex != -1) {
            returnSize[0] = i + 1;
            returnSize[1] = foundIndex + 1;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int arr[4] = {2, 7, 11, 15};
    int size[2];
    int target = 9;
    
    int found = TwoSum_BinarySearch(arr, 4, target, size);
    
    if (found == 1) {
        printf("Indices: %d, %d\n", size[0], size[1]);
    } else {
        printf("Target not found\n");
    }
    
    return 0;
}*/
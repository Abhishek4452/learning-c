/* desc- **Binary Search** [Easy] - *Why:* Off-by-one discipline is mandatory for reliable firmware .
*/

#include <stdio.h>
#include <stdint.h>


int BinarySearch(int *a,int length,int target);
int main(){

int a[] = {1 ,2 ,3 ,4 ,5,6,8,9,11,34,64,234,864};
    printf("binary search %d \n",BinarySearch(a,13,2));
    return 0;
}
// function defination
int BinarySearch(int *a,int length,int target){
    int mid,l,r;
    l=0;
    r = length-1;
    
    while(l<=r){
        mid = (l+r)/2;
        if(a[mid] == target ){
            return 1;
        }
        if(target > mid){
            l = mid +1;
        }
        else{
            r = mid-1;
        }
    }
    return 0;
}


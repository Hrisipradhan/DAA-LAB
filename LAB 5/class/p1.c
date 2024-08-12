#include<stdio.h>

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        // printf(" %d ",arr[i]);
        if(arr[i]<0){
            printf(" %d ",arr[i]);
        }
    }
    for(int i=0;i<size;i++){
        // printf(" %d ",arr[i]);
        if(arr[i]>0){
            printf(" %d ",arr[i]);
        }
    }
    
    
    printf("\n");
}

int main(){
    int arr[]={2,-4,3,5,-2,-4,-8,7,8,};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr,n);

    
    return 0;
}
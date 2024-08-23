#include<stdio.h>
void calculateProduct(int arr[], int left[], int right[], int size) {
    
    left[0] = 1;
    for (int i = 1; i < size; i++) {
        left[i] = left[i-1] * arr[i-1];
    }

    
    right[size-1] = 1;
    for (int i = size - 2; i >= 0; i--) {
        right[i] = right[i+1] * arr[i+1];
    }
}
int divd(int a, int b){
    int c,res=0;
    c =a+b;
    while(c>b){
        c = c-b;
        res++;

    }
    return res;

}

void printArray(int arr[], int size) {
    int left[size], right[size], output[size];
    int div[size];
    
    
    calculateProduct(arr, left, right, size);
       
        for (int i = 0; i < size; i++) {
            output[i] = left[i] * right[i];
    }

    
    printf("\nThe Multiplication of  array is: ");
    printf(" %d ",output[0]);
    printf("\nThe divide output array is: \n");
    for (int i =0;i<size;i++){
        div[i]=divd(output[0],arr[i]);
        
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf(" %d  ",div[i]);
    }
    printf("\n");

}



int main(){
    int arr[]={1,2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr,n);

    return 0;
}
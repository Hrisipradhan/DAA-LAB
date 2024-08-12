#include<stdio.h>
void swap(int*arr,int i,int j){
    int temp =arr[i];
    arr[i]=arr[j];
    arr[j]= temp;
}
void bubblesort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr, j, j+1);
            }
        }
    }
}

void printarr(int arr[],int size,int sec){
    for(int i=0;i<size;i++){
        printf(" %d ",arr[i]);
        if(arr[i]==arr[size-2]){
            sec = arr[i];

        }
    }

    printf("\n The Second smallest :%d",arr[1]);
    printf("\n The second largest element in arr : %d",sec);   
    printf("\n");
}
int main(){
    int sec=0;
    int arr[]={2,3,42,32,12,11,10};
    int n = sizeof(arr)/ sizeof(arr[0]);
    // printf("%d",sizeof(arr));
    // printf("%d",n);
    bubblesort(arr,n);

    printf("sorted arry");
    printarr(arr,n,sec);
    return 0;

}
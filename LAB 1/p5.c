#include<stdio.h>

void exchange(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void rotateRight(int arr[], int n, int p2) {
    for (int i = 0; i < p2; i++) {
        exchange(&arr[n - 1], &arr[n - 2]);
        for (int j = n - 2; j > 0; j--) {
            exchange(&arr[j], &arr[j - 1]);
        }
    }
}
int main(){
    int n;
    int a;
    printf("Enter the number of Elemetn in  arry:");
    scanf("%d",&n);
    printf("Enter the element");
    scanf("%d",&a);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    rotateRight(arr, n, a);

    printf("After ROTATE: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    
    return 0;

}
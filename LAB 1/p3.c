#include <stdio.h>

void calculatePrefixSum(int arr[], int n) {
    int prefixSum[n];
    prefixSum[0] = arr[0];

    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    printf("Prefix Sum Array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    calculatePrefixSum(arr, n);
    return 0;
}

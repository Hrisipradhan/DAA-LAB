#include <stdio.h>

void dup(int arr[], int n) {
    int count[100] = {0};

    int total = 0;
    int mostrep = -1;
    int maxCount = 0;

    for (int i = 0; i < n;i++) {
        count[arr[i]]++;
        if (count[arr[i]] > 1) {
            total++;
        }
        if (count[arr[i]] > maxCount) {
            maxCount = count[arr[i]];
            mostrep = arr[i];
        }
    }

    printf("Total number of duplicate values: %d\n", total);
    printf("The most repeating element in the array: %d\n", mostrep);
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

    dup(arr, n);
    return 0;
}

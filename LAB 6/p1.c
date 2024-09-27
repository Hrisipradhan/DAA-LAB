#include <stdio.h>
#include <stdlib.h>

// Define the ITEM structure
struct ITEM {
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
};

// Function to swap two items
void swap(struct ITEM* a, struct ITEM* b) {
    struct ITEM temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function for heap sort
void heapify(struct ITEM arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;

    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap sort function to sort the items based on profit/weight ratio
void heapSort(struct ITEM arr[], int n) {
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Fractional Knapsack function
float fractionalKnapsack(struct ITEM items[], int n, float capacity) {
    float total_profit = 0.0;

    // Sort the items by profit/weight ratio using heap sort
    heapSort(items, n);

    // Iterate over the items
    for (int i = n - 1; i >= 0; i--) {
        if (capacity == 0)
            break;

        if (items[i].item_weight <= capacity) {
            // Take the full item
            capacity -= items[i].item_weight;
            total_profit += items[i].item_profit;
            printf("Item No %d %.6f %.6f 1.000000\n", items[i].item_id, items[i].item_profit, items[i].item_weight);
        } else {
            // Take a fraction of the item
            float fraction = capacity / items[i].item_weight;
            total_profit += items[i].item_profit * fraction;
            printf("Item No %d %.6f %.6f %.6f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, fraction);
            capacity = 0;
        }
    }

    return total_profit;
}

int main() {
    int n;
    float capacity;

    // Input number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Create an array of items
    struct ITEM items[n];

    // Input profit and weight of each item
    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    // Input the capacity of the knapsack
    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    // Calculate the maximum profit
    float max_profit = fractionalKnapsack(items, n, capacity);

    // Output the maximum profit
    printf("Maximum profit: %.6f\n", max_profit);

    return 0;
}

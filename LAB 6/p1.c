#include <stdio.h>

struct ITEM {
    int item_id;
    float item_profit, item_weight, profit_weight_ratio;
};

void take_input(struct ITEM item[], int n) {
    for(int i=0; i<n; i++) {
        printf("Enter the profit and weight of item %d : ", i+1);
        item[i].item_id = i+1;
        scanf("%f %f", &item[i].item_profit, &item[i].item_weight);
        item[i].profit_weight_ratio = item[i].item_profit/item[i].item_weight;
    }
}

void swap(struct ITEM *a, struct ITEM *b) {
    struct ITEM temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct ITEM arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio < arr[smallest].profit_weight_ratio)
        smallest = left;

    if (right < n && arr[right].profit_weight_ratio < arr[smallest].profit_weight_ratio)
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void heapSort(struct ITEM arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        minHeapify(arr, i, 0);
    }
}

float knapsack (struct ITEM items[], int n, float capacity) {
    float total_profit = 0;
    float weight_req = capacity;
    
    int i = 0;
    printf("Item No\tProfit\t\tWeight\t\tAmount to be taken\n");
    while (weight_req > 0) {
        float fraction = weight_req > items[i].item_weight ? 1 : weight_req / items[i].item_weight;

        weight_req -= fraction*items[i].item_weight;

        printf("%d\t%f\t%f\t%f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, fraction);

        total_profit += fraction*items[i].item_profit;
        i++;
    };

    while(i < n) {
        printf("%d\t%f\t%f\t%f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, weight_req);
        i++;
    }

    return total_profit;
}

int main() {
    int n;
    float capacity;
    printf("Enter the number of items : ");
    scanf("%d", &n);

    struct ITEM items[n];
    take_input(items, n);

    printf("Enter the capacity of knapsack : ");
    scanf("%f", &capacity);

    heapSort(items, n);

    float total_profit = knapsack(items, n, capacity);

    printf("Maximum profit : %f\n", total_profit);

}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparisons = 0;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int readFile(const char* filename, int arr[], int max_size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%d", &arr[count]) == 1 && count < max_size) {
        count++;
    }

    fclose(file);
    return count;
}

void writeFile(const char* filename, int arr[], int size) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s for writing\n", filename);
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

void sortAndMeasure(const char* input_file, const char* output_file) {
    int arr[500];  
    int size = readFile(input_file, arr, 500);

    if (size == 0) {
        printf("No data read from file.\n");
        return;
    }

    comparisons = 0;
    clock_t start = clock();
    mergeSort(arr, 0, size - 1);
    clock_t end = clock();

    double Exe_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    writeFile(output_file, arr, size);

    printf("Sorted data. \nTime taken: %f seconds. \nComparisons: %lld\n", Exe_time, comparisons);
}

int main() {
    int choice;

    while (1) {
        printf("\nMAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sortAndMeasure("inAsce.dat", "outMergeAsce.dat");
                break;
            case 2:
                sortAndMeasure("inDesc.dat", "outMergeDesc.dat");
                break;
            case 3:
                sortAndMeasure("inRand.dat", "outMergeRand.dat");
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
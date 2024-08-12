#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int count;

typedef struct stack {
    int arr[500];
    int size;
}ARRAY;

void readFile(FILE *file, char filename[], ARRAY* arr){
    file = fopen(filename, "r");

    if(file == NULL) {
        printf("Error opening %s\n", filename);
        exit(1);
    }

    arr->size = 0;
    while(fscanf(file, "%d", &arr->arr[arr->size]) == 1){
        arr->size++;

        if(arr->size > 499){
            printf("Error : Out of memory [Max 500 elements allowed]\n");
            exit(1);
        }
    }

    if(arr->size < 300) {
        printf("Minimum 300 elements required\n");
        exit(1);
    }
}

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
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
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
        count++;
        
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}

void execute_mergeSort(ARRAY *arr) {
    clock_t start, end;

    start = clock();

    mergeSort (arr->arr, 0, arr->size);

    end = clock();

    printf("\nNo of elements : %d", arr->size);
    printf("\nNo of comparisons : %d", count);
    printf("\nExecution time : %lf seconds\n", ((double)(end - start))/CLOCKS_PER_SEC);
}

void writeFile (FILE *file, char filename[], ARRAY arr) {
    file = fopen (filename, "w");

    if(file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    for(int i = 0; i <= arr.size; i++)
        fprintf(file, "%d ", arr.arr[i]);
    
}

int main() {
    printf("MAIN MENU (MERGE SORT)\n"
           "1. Ascending Data\n"
           "2. Descending Data\n"
           "3. Random Data\n"
           "4. ERROR (EXIT)\n");

    int option;
    printf("Enter option : \n");
    scanf("%d", &option);

    FILE *file;
    ARRAY arr;

    char InputFile[][20] = {"inAsce.dat", "inDesc.dat", "inRand.dat"};
    char OutputFile[][20] = {"outMergeAsce.dat", " outMergeDesc.dat", "outMergeRand.dat"};

    if(option > 0 && option < 4){
        readFile(file, InputFile[option-1], &arr);
        execute_mergeSort(&arr);
        writeFile(file, OutputFile[option-1], arr);
    }else {
        printf("Program closed\n");
    }
    return 0;
}
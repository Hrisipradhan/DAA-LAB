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

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        count++;
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void execute_quickSort(ARRAY *arr) {
    clock_t start, end;

    start = clock();

    quickSort (arr->arr, 0, arr->size-1);

    end = clock();

    printf("\nNo of elements : %d", arr->size);
    printf("\nNo of comparisons : %d", count);

    if(count == arr->size-1){
        printf("\nScenerio : Worst Case");
    }else{
        printf("\nScenero : Best Case");
    }
    
    printf("\nExecution time : %lf seconds\n", ((double)(end - start))/CLOCKS_PER_SEC);
}

void printElements(ARRAY arr){
    for(int i = 0; i < arr.size; i++)
        printf("%d ", arr.arr[i]);
    printf("\n");
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
    printf("MAIN MENU (QUICK SORT)\n"
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
    char OutputFile[][20] = {"outQuickAsce.dat", "outQuickDesc.dat", "outQuickRand.dat"};

    if(option > 0 && option < 4){
        readFile(file, InputFile[option-1], &arr);

        printf("Before sorting : \n");
        printElements(arr);

        execute_quickSort(&arr);

        printf("After sorting : \n");
        printElements(arr);

        writeFile(file, OutputFile[option-1], arr);
    }else {
        printf("Program closed\n");
    }
    return 0;
}
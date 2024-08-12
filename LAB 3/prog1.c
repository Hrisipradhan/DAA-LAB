

#include<stdio.h>
#include<stdlib.h>
#include<time.h>



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


void readinputFile(char *filename, int arr[], int *n) {

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error file %s\n", filename);
        exit(1);
    }

    *n = 0;
    while (fscanf(file, "%d", &arr[*n]) != EOF) {
        (*n)++;
    }
    fclose(fp);
}

void writeoutputFile(char *filename, int arr[], int n) {

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(fp);
}


void Menu()
{
	printf("1. Sort Ascending order\n");
    printf("2. Sort Descending order\n");
    printf("3. Sort Random\n");
    printf("4. Exit\n");
}

int main(){


	int inputarr[500], n, comparison = 0;
	char inputFile[40], outputFile[40];
	clock_t start, end;

	while(1)
	{
		Menu();
		int ch;
		printf("Enter Your Choice:\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				sprintf(inputFile, "inAsce.dat");
				sprintf(outputFile, "outMergeAsce.dat");
				break;

			case 2:

				//
				//

			case 3:

				//
				//
			case 4:

				//
				//

		}

	readinputFile(inputFile, arr, &n);

	start = clock();
	mergesort(arr, 0, n-1, &comparison);
	end = clock();

	double execution_time;

	execution_time = (double)(end-start)/(double)CLOCKS_PER_SEC;
	
	writeoutputfile(outputFile, arr, n);

    printf("Sorted array %s\n", outputFile);
    printf("Execution time: %.2f seconds\n", execution_time);
    printf("Number of comparisons: %d\n", comparisons);

	


	}
}



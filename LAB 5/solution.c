#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void ReadData(struct person *p, int n){
    if (n == 0){
        printf("No data found\n");
        return;
    }
    printf("Total No of persons: %d\n", n);
    printf("Id\tName\t\t\tAge\tHeight\tWeight(pound)\n");
    for(int i = 0; i<n; i++){
        printf("%d\t%s\t\t%d\t%d\t%d\n",
            p[i].id, p[i].name, p[i].age, p[i].height, p[i].weight);
    }
}

int compareByAge(const void *a, const void *b) {
    const struct person *personA = (const struct person *)a;
    const struct person *personB = (const struct person *)b;
    return personA->age - personB->age;
}
void minHeapify(struct person *arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && compareByAge(&arr[left], &arr[smallest]) < 0)
        smallest = left;

    if (right < n && compareByAge(&arr[right], &arr[smallest]) < 0)
        smallest = right;

    if (smallest != i) {
        struct person temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(struct person *arr, int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

void drawMinHeap(struct person *arr, int n, int i, int level) {
    if (i < n) {
        drawMinHeap(arr, n, 2 * i + 2, level + 1);

        for (int j = 0; j < level; j++) {
            printf("      ");
        }

        printf("%s (%d years old)\n", arr[i].name, arr[i].age);

        drawMinHeap(arr, n, 2 * i + 1, level + 1);
    }
}

void maxHeapify(struct person *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].weight > arr[largest].weight)
        largest = left;

    if (right < n && arr[right].weight > arr[largest].weight)
        largest = right;

    if (largest != i) {
        struct person temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(struct person *arr, int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void drawMaxHeap(struct person *arr, int n, int i, int level) {
    if (i < n) {
        drawMaxHeap(arr, n, 2 * i + 2, level + 1);

        for (int j = 0; j < level; j++) {
            printf("      ");
        }

        printf("%s (%d pounds)\n", arr[i].name, arr[i].weight);

        drawMaxHeap(arr, n, 2 * i + 1, level + 1);
    }
}

void displayYoungestWeight(struct person *arr, int n) {
    if (n > 0) {
        struct person youngest = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i].age < youngest.age) {
                youngest = arr[i];
            }
        }
        printf("Weight of the youngest person\n"
         "Name \t %s\nAge \t %d\nWeight \t %d\n", youngest.name, youngest.age,youngest.weight);
    } else {
        printf("No data available.\n");
    }
}
void insertPerson(struct person *arr, int *n) {
    struct person newPerson;
    printf("Insert new person :\n");
    printf("ID:\t");
    scanf("%d", &newPerson.id);
    printf("Name:\t");
    char fullname[100];
    scanf(" %99[^\n]", fullname);
    newPerson.name = strdup(fullname);
    printf("Age:\t");
    scanf("%d", &newPerson.age);
    printf("Height:\t");
    scanf("%d", &newPerson.height);
    printf("Weight:\t");
    scanf("%d", &newPerson.weight);

    (*n)++;
    int i = *n - 1;
    arr[i] = newPerson;

    while (i > 0 && compareByAge(&arr[i], &arr[(i - 1) / 2]) < 0) {
        struct person temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void deleteOldestPerson(struct person *arr, int *n) {
    struct person deletedPerson;
    if (*n <= 0) {
        printf("No data available to delete.\n");
        exit(1);
    }

    deletedPerson = arr[0];

    arr[0] = arr[*n - 1];
    (*n)--;

    minHeapify(arr, *n, 0);

    printf("Deleted person\n"
    "Name \t %s\nAge \t %d\nHeight \t %d\nWeight \t %d\n", deletedPerson.name, deletedPerson.age, deletedPerson.height, deletedPerson.weight);
}

int main() {
    FILE *file;
    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening data file\n");
        return 1;
    }

    struct person *p;
    p = (struct person *)malloc(50 * sizeof(struct person));
    if (p == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    int count = 0, choice;
    char line[50];
    
    while ((line[0] = fgetc(file)) != '\n' && line[0] != EOF);

    while (fgets(line, sizeof(line), file)) {
        char *token;
        token = strtok(line, ",");
        p[count].id = atoi(token);

        token = strtok(NULL, ",");
        p[count].name = (char *)malloc(strlen(token));
        strcpy(p[count].name, token);

        token = strtok(NULL, ",");
        p[count].age = atoi(token);

        token = strtok(NULL, ",");
        p[count].height = atoi(token);

        token = strtok(NULL, ",");
        p[count].weight = atoi(token);

        count++;

        if (count >= 50) {
            printf("Out of memory\n");
            return 1;
        }
    }

    printf("MAIN MENU (HEAP)\n"
           "1. Read Data\n"
           "2. Create a Min-heap based on the age\n"
           "3. Create a Max-heap based on the weight\n"
           "4. Display weight of the youngest person\n"
           "5. Insert a new person into the Min-heap\n"
           "6. Delete the oldest person\n"
           "7. Exit\n\n");

    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            ReadData(p, count);
            break;
        };
        case 2: {
            buildMinHeap(p, count);
            drawMinHeap(p, count, 0, 0);
            break;
        };
        case 3 : {
            buildMaxHeap(p, count);
            drawMaxHeap(p, count, 0, 0);
            break;
        };
        case 4 : {
            displayYoungestWeight(p, count);
            break;
        };
        case 5 : {
            insertPerson(p, &count);
            drawMinHeap(p, count, 0, 0);
            break;
        };case 6 : {
            deleteOldestPerson(p, &count);
            break;
        }
        default : printf("Program closed\n");
    }
    return 0;
}
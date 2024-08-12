#include <stdio.h>

int gcd (int x, int y) {
    if(x==0) return y;
    if(y==0) return x;
    return gcd(y, x%y);
}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Insufficient arguments\nUsage : %s <input_file> <output_file>\n\n", argv[0]);
        return 1;
    }

    int size = 0;
    int arr[50];

    FILE *file;
    file = fopen(argv[1], "r");

    if(file == NULL) {
        printf("Error opening file %s\n", argv[1]);
    }else {
        printf("Taking input from file %s\n", argv[1]);
    }

    while (fscanf(file, "%d", &arr[size]) == 1) {
        size++;
    }

    file = fopen(argv[2], "w");
    if(file == NULL) {
        printf("Error saving output file %s\n", argv[2]);
    }else{
        printf("Saving output to %s\n", argv[2]);
    }

    for(int i=0; i<size; i=i+2){
        fprintf(file, "The GCD of %d and %d is %d\n", arr[i], arr[i+1], gcd(arr[i], arr[i+1]));
    }
    return 0;
}
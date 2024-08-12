#include<stdio.h>
#include<stdlib.h>


int dec(int num){
    if(num == 0){
        return 0;
    }
    return (num %2 + 10 * (dec(num/2)));
}

int main(int argc,char *argv[]){
    // int num=20;
    // dec(20);
    // printf("\n");
    if(argc < 3){
        printf("Insufficient argruments\n Usage : %s <Input_files> <Output_files>\n\n",argv[0]);
        return 1;
    }
    int size=0;
    int arr[50];

    FILE *file;
    file = fopen(argv[1],"r");

    if(file==NULL){
        printf("Error Opeing file %s\n",argv[1]);
    }else{
        printf("Taking iput from files %s\n",argv[1]);
    }

    while(fscanf(file,"%d",&arr[size]) ==1){
        size++;
    }
    // int output=dec(arr[0]);


    file=fopen(argv[2],"w");
    if(file == NULL){
        printf("Error saving output files %s\n",argv[2]);
    }else{
        printf("Saving output to %s\n",argv[2]);
    }

    for(int i=0;i<size;i=i+2){
        fprintf(file,"The decimal conversion of %d is  %d \n",arr[i],dec(arr[i]));
    }

    
    // fprintf(file,"The Decimal conversion to binary is %d is %d\n",arr[0],dec(arr[0]));

    fclose(file);
}
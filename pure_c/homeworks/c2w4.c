#include <stdlib.h>
#include <stdio.h>

size_t count_entries(FILE *fp){
    size_t  lines = 0;
    fscanf(fp, "%d", &lines);
    printf("Number of entries: %ld\n", lines);
    return lines;
}
void read_numbers(FILE *fp, int read[], int *size, double *count, int *max){
    int i=0, readed;
    int lim = *size;
    while(i < lim && fscanf(fp, "%d", &read[i])==1){
        *count+=read[i++];
        if(i==0 || read[i-1]>*max){
            *max = read[i-1];
        }
    }
    *size = i;
}
void print_numbers(int readed[], int size){
    printf("Numbers to be averaged:");
    for(int i=0;i<size;i++){
        if( i%10 == 0){
            printf("\n");
        }
        printf("%d ",readed[i]);
    }
    printf("\n");
}

void main(int argc, char *args[]){
    char* fname;
    if(argc==1){
        printf("Please give a filename :");
        gets(fname);
        
    }else{
        fname = args[1];
    }

    
    FILE *fp = fopen(fname, "r");

    if(fp==NULL){
        printf("Your file doesn't exists");
        return;
    }
    
    size_t size = count_entries(fp);
    int readed[1000] = {0};
    int max;
    double count = 0;
    read_numbers(fp, readed, &size, &count, &max);
    print_numbers(readed,size);
    printf("Average: %4.2f \n", count/size);
    printf("Max: %d \n", max);
}
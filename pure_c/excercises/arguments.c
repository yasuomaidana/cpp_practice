#include <stdio.h>

int main(int argc, char *args[]){
    printf("%d", argc);
    printf("--------\n");
    for(int i=0; i<argc; i++){
        printf(args[i]);
        printf("\n");
    }
    printf("%%d");
}
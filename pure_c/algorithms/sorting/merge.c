#include <stdio.h>

void swap(int *a, int *b);
void merge_sort(int left, int right, int unsorted_array[]);
void merge(int left, int right, int middle, int unsorted_array[]);
void copy(int size, int offset, int fromArray[], int toArray[]);
void print_array(int elements, int array[]);

int main(void)
{
    int array[] = {10, 8, 6, 2, 55, 12, 1, 3, 22, 9};
    int n = sizeof array / sizeof(int);
    printf("elements: %d\n", n);
    printf("unsorted: \t");
    print_array(n, array);
    merge_sort(0, n-1, array);
    printf("sorted: \t");
    print_array(n, array);
    return 0;
}

void print_array(int elements, int array[])
{
    for (int i = 0; i < elements; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

void copy(int size, int offset, int fromArray[], int toArray[]){
    for(int i = 0;i<size;i++){
        toArray[i] = fromArray[i+offset];
    }
}
void merge(int left, int right, int middle, int unsorted_array[]){
    int i,j,k;
    int left_size = middle - left +1;
    int right_size = right - middle;

    int left_side[left_size], right_side[right_size];

    copy(left_size,left,unsorted_array,left_side);
    copy(right_size, middle+1 ,unsorted_array,right_side);

    i = 0;
    j = 0;
    k = left;

    while(i<left_size && j<right_size){
        if(left_side[i] <= right_side[j]){
            unsorted_array[k] = left_side[i];
            i++;
        }else{
            unsorted_array[k] = right_side[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        unsorted_array[k] = left_side[i];
        i++;
        k++;
    }
  
    while (j < right_size) {
        unsorted_array[k] = right_side[j];
        j++;
        k++;
    }

}

void merge_sort(int left, int right, int unsorted_array[])
{
    if(left<right){
        int middle = left + (right - left)/2;
        merge_sort(left,middle,unsorted_array);
        merge_sort(middle+1,right, unsorted_array);
        merge(left, right, middle, unsorted_array);
    }
}
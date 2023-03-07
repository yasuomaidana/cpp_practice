#include <stdio.h>

void swap(int *a, int *b);
void merge_sort(int left, int right, int unsorted_array[]);
void print_array(int elements, int array[]);

int main(void)
{
    int array[] = {10, 8, 6, 2, 55, 12, 1, 3, 22, 9};
    int n = sizeof array / sizeof(int);
    printf("elements: %d\n", n);
    printf("unsorted: \t");
    print_array(n, array);
    merge_sort(0, n, array);
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

void merge_sort(int elements, int unsorted_array[])
{
    printf("To define");
}
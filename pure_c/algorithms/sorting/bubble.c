#include <stdio.h>

void swap(int *a, int *b);
void bubble_sort(int elements, int unsorted_array[]);
void print_array(int elements, int array[]);

int main(void)
{
    int array[] = {10, 8, 6, 2, 55, 12, 1, 3, 22, 9};
    int n = sizeof array / sizeof(int);
    printf("elements: %d\n", n);
    printf("unsorted: \t");
    print_array(n, array);
    bubble_sort(n, array);
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

void bubble_sort(int elements, int unsorted_array[])
{
    for (int i = 0; i < elements; i++)
    {
        for (int j = 0; j < elements - i - 1; j++)
        {
            if (unsorted_array[j] > unsorted_array [j+1]){
                swap(&unsorted_array[j], &unsorted_array[j+1]);
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
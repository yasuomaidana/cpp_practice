#include <stdbool.h>
#include <stdio.h>

int main()
{
    int a = 0, b = 1, c = 2;
    if (a<b) printf ("TRUE\n"); else printf("FALSE\n");
    if (a < b - c) printf ("TRUE\n"); else printf("FALSE\n");
    if (b < c - 1) printf ("TRUE\n"); else printf("FALSE\n"); 
    if (!c) printf ("TRUE\n"); else printf("FALSE\n");
    return 0;
}
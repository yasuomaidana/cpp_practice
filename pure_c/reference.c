#include <stdio.h>

void modify_number(double *number);

int main()
{
    double radius = 0.0;
    modify_number(&radius);
    printf("%lf", radius);
}

void modify_number(double *number) {
    *number = *number +1;
}
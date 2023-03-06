#include <stdio.h>

void modify_number(double *number);

int main()
{
    double radius = 0.0;
    modify_number(&radius);
    printf("%lf", radius);
}

void modify_number(double *number) {
    double working_number = *number;
    working_number++;
    *number = working_number;
}
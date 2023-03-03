#include<stdio.h>

#define PI 3.14159

void calculate_circle_area(double radius);

int main()
{
    double radius = 0.0;
    printf("Previous size of radious :%lu bytes\n",sizeof(radius));
    printf("Enter radius: ");
    scanf("%lf", &radius);
    printf("Size of radious after input: %lu bytes\n",sizeof(radius));
    calculate_circle_area(radius);
}

void calculate_circle_area(double radius) {
    double area = PI * radius * radius;
    printf("radius of %lf meters\n \tarea is %lf sq. meters \n", radius, area);
}
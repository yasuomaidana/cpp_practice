#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;
    printf("Enter x: ");
    scanf("%lf",&x);
    if(0<x && x<1){
        printf("sin(%.2lf) = %.2lf\n", x, sin(x));
    }else{
        printf("invalid input");
    }
    
    
}
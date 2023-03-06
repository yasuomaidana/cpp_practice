#include <stdio.h>
#include <math.h> /* has  sin(), abs(), and fabs() */

void cosine_sine(double x);

int main(void)
{
    double x;
    printf("Calculate the sine and cosine of: ");
    scanf("%lf",&x);
    cosine_sine(x);
    return 0;
}

void cosine_sine(double x){
    if(x<0 || x>1) {
        printf("Invalid input\n");
        return;
    }
    printf("cos(%0.3lf)= %0.3lf\tsin(%0.3lf)= %0.3lf",x,cos(x),x,sin(x));
}
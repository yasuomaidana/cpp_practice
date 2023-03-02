#include <iostream>
#include<cstdlib>
#include<cstdio>

#define PI 3.14159 //Defining variable for all the program by using define, this is memory efficient but makes the value inmutable;
// constexpr is quite equivalent to #define
using namespace std;

void calculate_circle_area(double radius);

int main()
{
    auto result = (10 <=> 20) > 0;
    cout << "Hello World!\n";
    cout << "This is the result :" << result<< endl;
    printf("Using C way \n");
    

    double radius = 0.0;
    cout << "Enter radius:";
    cin >> radius; //scanf("%lf", &radius);
    calculate_circle_area(radius);
}

void calculate_circle_area(double radius) {
    double area = PI * radius * radius;
    printf("radius of %lf meters; area is %lf sq. meters \n",radius,area);
}
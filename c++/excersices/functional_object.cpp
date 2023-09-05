#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class gen{
    public:
    gen(double x_zero, double increment):x(x_zero), incr(increment){}
    double operator()(){ 
        x+= incr; 
        return x*x;}
    private:
    double x, incr;
};

double integrate(gen g, int n){
    vector<double> fx(n);
    generate(fx.begin(), fx.end(), g);
    return (accumulate(fx.begin(),fx.end(),0.0)/n);
}
int main(){
    double v1[3] = {1.0,2.5,4.6}, sum;
    sum = accumulate(v1,v1+3,0.0,minus<int>());
    cout <<"sum ="<<sum<<endl;

    const int n = 10000;
    gen g(0.0,1.0/n);
    cout <<"integration program x**2"<<endl;
    cout<<integrate(g,n)<<endl;
};
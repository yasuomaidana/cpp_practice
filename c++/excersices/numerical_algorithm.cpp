#include <numeric>
#include <vector>
#include <iostream>

using namespace std;
int main(){
    double v1[3] = {1.0, 2.5, 4.6}, v2[3] = {1.0 , 2.0 , -3.5};
    double sum, inner_p;

    sum = accumulate(v1, v1 + 3, 0.0);
    inner_p = inner_product(v1, v1+3, v2, 1.0);

    cout<<"sum: "<< sum<<"\ninner product: "<<inner_p<<endl;

    cout<<"Sensitive to initial type"<<endl;
    sum = accumulate(v1, v1 + 3, 0);
    inner_p = inner_product(v1, v1+3, v2, 1);

    cout<<"sum: "<< sum<<"\ninner product: "<<inner_p<<endl;
}
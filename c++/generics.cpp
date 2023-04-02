#include <complex>
#include <iostream>

template <class T>
inline void swap_(T& d, T& s){
    T temp = d;
    d = s;
    s =temp;
}

using namespace std;
int main(){
    int m = 5, n = 10;
    double x = 5.3, y = 10.6;
    
    complex<double> r(2.4,3.5), s(4,6.7);
    cout<<"inputs: "<<m<<", "<<n<<endl;
    swap_(m,n);
    cout<<"outputs: "<<m<<", "<<n<<endl;

    cout<<"inputs: "<<r<<", "<<s<<endl;
    swap_(r,s);
    cout<<"outputs: "<<r<<", "<<s<<endl;
}
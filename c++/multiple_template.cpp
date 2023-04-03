#include <iostream>
using namespace std;

template<class T1, class T2>
void copy(const T1 source[], T2 destination [], int size){
    for(int i=0; i<size;++i){
        destination[i] = static_cast<T2>(source[i])/2;
    }
}

int main(){
    int a[] = {1,2,3,4};
    double b[4];
    copy(a,b,4);
    for( double i: b){
        cout<<i<<endl;
    }
}

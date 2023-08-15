#include<iostream>
#include<iterator>
#include<fstream>
#include<vector>

using namespace std;

template<typename ForwardIterator>
void square(ForwardIterator first, ForwardIterator last){
    for(;first!=last;first++){
        *first = (*first)*(*first);
    }
}

int main(){
    vector<int> a = {1,2,3};
    cout<<"Before \n";
    for(auto squared: a){
        cout<<squared<<", ";
    }
    square(a.begin(),a.end());
    cout<<"\nAfter \n";
    for(auto squared: a){
        cout<<squared<<", ";
    }

    return 0;
}
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
using namespace std;

int main(void){
    ifstream datafile("data.txt");
    istream_iterator<int> start(datafile), end;

    vector<int> data(start,end);
    int sum = 0, res = 0;
    for(auto d:data){
        cout<<d<<"\t";
        sum += d;
    }
    
    
    cout<<endl;
    cout<<"sum: "<<sum<<endl;

    for(auto it = start; it != end; ++it){
        res -= *it;
        cout<<"it: "<<*it;
    }

    cout<<"res: "<<res;
}
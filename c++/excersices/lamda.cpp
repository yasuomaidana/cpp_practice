#include <algorithm>
#include <vector>
#include <iostream>


using namespace std;

int main(){
    vector<int> v(6);
    cout<<"New lambda"<<endl;
    for_each(v.begin(),v.end(), [](int &i){static int n = 1; i = n++;});
    for_each(v.begin(),v.end(), [](int i){cout << i<<endl;});
}

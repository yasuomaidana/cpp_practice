#include<iostream>
#include<string>
#include<map>
#include<unordered_map>

using namespace std;

int main(){
    map<unsigned long, string> worker; // orders before inserting
    unordered_map<unsigned long, unsigned> payroll;
    unsigned total_pay = 0;
    worker[9991] = "Harold Fish";
    payroll[9991] = 67300;

    worker[8881] = "Philp Fish";
    payroll[8881] = 87300;

    for(auto p = worker.begin(); p!=worker.end();++p){
        cout<< "name :" << (*p).second << "\t id no. :" << (*p).first<<endl;
    }

    for(auto p = payroll.begin(); p!=payroll.end();++p){
        cout<< "payrol total : $" << (*p).second << "\t id no. :" << (*p).first<<endl;
    }
    return 0;
}
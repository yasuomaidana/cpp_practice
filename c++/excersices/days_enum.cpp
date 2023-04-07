#include <iostream>
using namespace std;

typedef enum days{SUN,MON, TUE, WED, THU, FRI, SAT} days;

inline days operator++(days& d){
    d = static_cast<days>((static_cast<int>(d)+1)%7);
    return d;
}

ostream& operator<< (ostream& out, const days& d){
    switch(d){
        case SUN:
            out<<"SUN"; break;
        case MON:
            out<<"MON"; break;
        case TUE:
            out<<"TUE"; break;
        case WED:
            out<<"WED"; break;
        case THU:
            out<<"THU"; break;
        case FRI:
            out<<"FRI"; break;
        case SAT:
            out<<"SAT"; break;
    }
    return out;
}
inline days operator+ (days d, int n){
    return static_cast<days>((static_cast<int>(d)+n) % 7);
}



int main(){
    days day = SAT;
    cout<<"Original day "<<day<<endl;
    ++day;
    cout<<"day ++ "<<day<<endl;
    cout<<"day +  "<<day+10<<endl;
}
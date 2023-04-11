#include <iostream>
using namespace std;

class point{
    
    public:
        double x,y;
        
        point(double x, double y){
            this->x = x;
            this->y = y;
        }

    point operator+ (point& p2){
        point sum = {x + p2.x, y + p2.y};
        return sum;
    }
};

ostream& operator<< (ostream& out, const point& p){
    out <<"("<<p.x<<","<<p.y<<")";
}

int main(){
    point p1 = point(2,2);
    point p2 = point(1,-1);
    cout<<"Original point: "<<p1<<endl;
    cout<<"Sum point: "<<p1+p2<<endl;
}
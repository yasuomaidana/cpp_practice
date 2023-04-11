#include <iostream>
using namespace std;

class point{
    private:
        double x,y;


    public:
        point(double x, double y):x(x),y(y){}

        point operator+ (point& p2){
            point sum = {x + p2.x, y + p2.y};
            return sum;
        }

        double gx() const{
            return this->x;
        }
        double gy() const{
            return this->y;
        }
    };

ostream& operator<< (ostream& out, const point& p){
    
    out <<"("<<p.gx()<<","<<p.gy()<<")";
}

int main(){
    point p1 = point(2,2);
    point p2 = point(1,-1);
    cout<<"Original point: "<<p1<<endl;
    cout<<"Sum point: "<<p1+p2<<endl;
}
#include <iostream>
#include <math.h>

using namespace std;


class point
{
private:
    double x, y;

public:
    point(double x = 0, double y = 0) : x(x), y(y) {}

    point operator+(point p2)
    {
        point sum = {x + p2.x, y + p2.y};
        return sum;
    }

    point(double u):x(u), y(0){}

    operator double(){
        return sqrt(x*x+y*y);
    }

    friend ostream &operator<<(ostream &out, const point &p) //Allows to access to private fields
    {

        out << "(" << p.x << "," << p.y << ")";
    }

    ~point()
    {
        cout << "destroying " << x << "," << y << endl;
    }
};



int main()
{
    point* p1 = new point(2, 2);
    point p2 = point(1, -1);
    cout << "Original point: " << *p1 << endl;
    cout << "Sum point: " << *p1 + p2 << endl;

    double pd = *p1;
    cout<< "Point: "<<*p1<< " as double: "<<pd<<endl;
    
    point p3 = *p1 + p2 + p2;
    cout<< "Point 3: "<<p3<<endl;
    delete p1, p2,p3;
}
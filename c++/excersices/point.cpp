#include <iostream>
using namespace std;

class point
{
private:
    double x, y;

public:
    point(double x = 0, double y = 0) : x(x), y(y) {}

    point operator+(point &p2)
    {
        point sum = {x + p2.x, y + p2.y};
        return sum;
    }

    double gx() const
    {
        return this->x;
    }
    double gy() const
    {
        return this->y;
    }

    ~point()
    {
        cout << "destroying " << x << "," << y << endl;
    }
};

ostream &operator<<(ostream &out, const point &p)
{

    out << "(" << p.gx() << "," << p.gy() << ")";
}

int main()
{
    point* p1 = new point(2, 2);
    point p2 = point(1, -1);
    cout << "Original point: " << *p1 << endl;
    cout << "Sum point: " << *p1 + p2 << endl;

    delete p1, p2;
}
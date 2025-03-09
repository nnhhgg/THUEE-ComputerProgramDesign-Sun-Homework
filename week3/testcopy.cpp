#include <iostream>
using namespace std;
class Point
{
public:
    Point(int x = 0, int y = 0);
    ~Point();
    Point(const Point &p);
    int GetX();
    int GetY();

private:
    int x, y;
};
Point::Point(int x, int y)
{
    Point::x = x;
    Point::y = y;
    cout << "construct complete" << endl;
}
Point::~Point()
{
    cout << "destruct complete" << endl;
}
Point::Point(const Point &p)
{
    static int flag = 0;
    cout << "time:" << ++flag << endl;
    x = p.x;
    y = p.y;
}
int Point::GetX() { return (Point::x); }
int Point::GetY() { return (Point::y); }

void fun1(Point p)
{
}

Point fun2()
{
    Point p(3, 4);
    return (p);
}

int main()
{
    Point a(1, 2);
    Point b(a); // 1;
    fun1(a);    // 2;
    Point c;
    c = fun2(); // 3,4;
    return (0);
}
// 1. 先声明一个点类Point，成员为其坐标x，y，并设计构造函数（可赋初值也可以不赋初值）、
// 复制构造函数、析构函数（打印信息，表示其被调用），设置新值函数Set, 打印成员坐标值函数Print。
// 再声明一个矩形类Rectangle，其成员为矩形的左下角和右上角两个Point对象，
// 并设计Rectangle构造函数（分别由x1，y1，x2，y2坐标值构造，或由p1，p2两个点对象构造，
// 可赋初值也可以不赋初值）、复制构造函数、析构函数（打印信息，表示其被调用），
// 设置新值函数Set, 打印成员值函数Print，计算矩形面积函数Area，
// 以及其它你认为对访问此类对象有用的成员函数。并用此Rectangle类定义对象，调用所有成员函数。

#include <iostream>
#include <iomanip>
using namespace std;

class Point
{
public:
    Point(int a = 0, int b = 0)
    {
        x = a;
        y = b;
        cout << "construct complete" << " (" << x << ',' << y << ')' << endl;
    }
    Point(const Point &A)
    {
        x = A.x;
        y = A.y;
        cout << "copy complete" << " (" << x << ',' << y << ')' << endl;
    }
    ~Point()
    {
        cout << "destruct complete" << " (" << x << ',' << y << ')' << endl;
    }
    void Set(int a, int b)
    {
        x = a;
        y = b;
        return;
    }
    void Print() const
    {
        cout << '(' << x << ',' << y << ')';
        return;
    }
    int GetX() const
    {
        return (x);
    }
    int GetY() const
    {
        return (y);
    }

private:
    int x;
    int y;
};

class Rectangle
{
public:
    Rectangle(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : a(x1, y1), b(x2, y2) {};
    Rectangle(const Rectangle &A) : a(A.a), b(A.b) {};
    ~Rectangle()
    {
        cout << "destruct complete ";
        a.Print();
        b.Print();
        cout << endl;
    }
    void Set(int x1, int y1, int x2, int y2)
    {
        a = Point(x1, y1);
        b = Point(x2, y2);
        return;
    }
    void Print() const
    {
        cout << "Rectangle is:";
        a.Print();
        b.Print();
        cout << endl;
        return;
    }
    int Area() const
    {
        int area = 0;
        area = (a.GetX() - b.GetX()) * (a.GetY() - b.GetY());
        return (area);
    }

private:
    Point a;
    Point b;
};

int main()
{
    Rectangle r1(1, 2, 3, 4);
    r1.Print();
    cout << r1.Area() << endl;
    Rectangle r2;
    r2.Print();
    Rectangle r3(r1);
    return (0);
}
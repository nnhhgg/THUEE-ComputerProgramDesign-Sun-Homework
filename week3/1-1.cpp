// 1.编程实现：声明一个圆类Circle，其成员为 圆心的坐标 和 圆半径，
// 并设计构造函数（必须赋初值），复制构造函数，析构函数（打印信息，表示其被调用），
// 设置新值函数Set,打印成员值函数Print，计算圆面积函数Area，并用此类定义对象，
// 调用所有成员函数
#include <iostream>
using namespace std;

class Circle
{
public:
    Circle(double xx = 0, double yy = 0, double rr = 0);
    Circle(const Circle &p);
    ~Circle();
    void Set(double xx, double yy, double rr);
    void Print();
    double Area();

private:
    double x;
    double y;
    double r;
};

Circle::Circle(double xx, double yy, double rr)
{
    x = xx;
    y = yy;
    r = rr;
    cout << "construct complete" << endl;
}
Circle::Circle(const Circle &p)
{
    x = p.x;
    y = p.y;
    r = p.r;
    cout << "copy complete" << endl;
}
Circle::~Circle()
{
    cout << "destrucst complete" << endl;
}
void Circle::Set(double xx, double yy, double rr)
{
    x = xx;
    y = yy;
    r = rr;
    return;
}
void Circle::Print()
{
    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    cout << "r=" << r << endl;
    return;
}
double Circle::Area()
{
    double temp;
    temp = 3.14159 * r * r;
    return (temp);
}

int main()
{
    Circle a(1.0, 2.0, 3.0);
    a.Set(2.0, 3.0, 4.0);
    Circle b(a);
    a.Print();
    cout << a.Area() << endl;
    return (0);
}
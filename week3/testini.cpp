// 2.编程实现：声明一个矩形类Rectangle（矩形的边与坐标系的轴平行），
// 其成员为矩形的左下角和右上角两个点的坐标，并设计构造函数（可赋初值也可以不赋初值），
// 复制构造函数，析构函数（打印信息，表示其被调用），
// 设置新值函数Set,打印成员值函数Print，计算矩形面积函数Area，
// 以及其它你认为对访问此类对象有用的成员函数。并用此类定义对象，调用所有成员函数。
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Rectangle
{
public:
    Rectangle(double a1, double a2, double b1, double b2);
    Rectangle(Rectangle const &p);
    ~Rectangle();
    int Set(double a1, double a2, double b1, double b2);
    int Print();
    double Area();

private:
    double a1, a2, b1, b2;
};

using R = Rectangle;
R::Rectangle(double a1, double a2, double b1, double b2)
{
    R::a1 = a1;
    R::a2 = a2;
    R::b1 = b1;
    R::b2 = b2;
    cout << "construct completed" << endl;
}
R::Rectangle(Rectangle const &p)
{
    static int count = 0;
    count++;
    cout << "copy complete time" << count << endl;
    a1 = p.a1;
    a2 = p.a2;
    b1 = p.b1;
    b2 = p.b2;
}
R::~Rectangle()
{
    cout << "destruct completed" << endl;
}
int R::Set(double a1, double a2, double b1, double b2)
{
    R::a1 = a1;
    R::a2 = a2;
    R::b1 = b1;
    R::b2 = b2;
    return (1);
}
int R::Print()
{
    cout << setw(6) << '(' << a1 << ',' << a2 << ')' << " " << '(' << b1 << ',' << b2 << ')' << endl;
    return (0);
}
double R::Area()
{
    double temp = 0;
    temp = (a1 - b1) * (a2 - b2);
    return (fabs(temp));
}

int fun1(Rectangle const p)
{
    p;
    cout << "function1 complete" << endl;
    return (0);
}
int main()
{
    R Rec1(1, 2, 3, 4), Rec2;
    Rec1.Print();
    Rec2.Print();
    fun1(Rec1);
    R Rec3(Rec1);
    Rec3.Print();
    return (0);
}
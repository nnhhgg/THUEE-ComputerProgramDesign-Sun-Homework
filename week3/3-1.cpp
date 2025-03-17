// 编程实现：定义Boat与Car两个类，两者都有weight成员表示重量，
// 并为每个类设计构造函数（可赋初值也可以不赋初值），设置新值函数Set,打印成员值函数Print。
// 再定义两个类共同的一个友元函数TotalWeight(BoatB,CarC)，计算B、C两者的重量之和。
#include <iostream>
#include <cmath>
using namespace std;
class Car;
class Boat
{
public:
    Boat(double a = 0)
    {
        weight = a;
    }
    void Set(double a)
    {
        weight = a;
    }
    void Print()
    {
        cout << weight << endl;
    }
    friend double TotalWeight(Boat b, Car c);

private:
    double weight;
};
class Car
{
public:
    Car(double a = 0)
    {
        weight = a;
    }
    void Set(double a)
    {
        weight = a;
    }
    void Print()
    {
        cout << weight << endl;
    }
    friend double TotalWeight(Boat b, Car c);

private:
    double weight;
};
double TotalWeight(Boat b, Car c)
{
    double temp;
    temp = b.weight + c.weight;
    return (temp);
}

int main()
{
    Boat b;
    Car c;
    b.Set(20);
    c.Set(30);
    b.Print();
    c.Print();
    cout << TotalWeight(b, c) << endl;
    return (0);
}

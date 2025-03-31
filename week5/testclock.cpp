#include <iostream>
using namespace std;

class Clock
{
public:
    Clock(int h1 = 0, int m1 = 0, int s1 = 0)
    {
        h = h1;
        m = m1;
        s = s1;
    }
    void Set(int a, int b, int c)
    {
        h = a;
        m = b;
        s = c;
        return;
    }
    void Print()
    {
        cout << h << ':' << m << ':' << s << endl;
        return;
    }
    Clock operator++();
    Clock operator++(int);

private:
    int h;
    int m;
    int s;
};
Clock Clock::operator++()
{
    h++;
    m++;
    s++;
    return *this;
}
Clock Clock::operator++(int)
{
    Clock temp(*this);
    h++;
    m++;
    s++;
    return (temp);
}

int main()
{
    Clock a(1, 1, 1), b(3, 3, 3);
    Clock c, d;
    c = a++;
    d = ++b;
    c.Print();
    d.Print();
    return (0);
}
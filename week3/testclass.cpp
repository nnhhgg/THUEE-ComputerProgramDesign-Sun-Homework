#include <iostream>
using namespace std;
class Myclass
{
public:
    Myclass(int i = 0);
    ~Myclass();
    void Print();

private:
    int member;
};
Myclass::Myclass(int i)
{
    Myclass::member = i;
    cout << "construct complete;" << endl;
}
Myclass::~Myclass()
{
    cout << member << endl;
    cout << "destruct complete;" << endl;
}
void Myclass::Print()
{
    cout << member << endl;
    return;
}

int main()
{
    Myclass a;
    a.Print();
    Myclass b(10);
    b.Print();
    return (0);
}
#include <iostream>
using namespace std;
void swap1(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
    return;
}
class C
{
public:
    C(int x, int y)
    {
        a = x;
        b = y;
    }
    void swap()
    {
        swap1(&a, &b);
        cout << a << b << endl;
    }

private:
    int a;
    int b;
};
int main()
{
    C a(1, 2);
    a.swap();
    return (1);
}
#include <iostream>
#include <cmath>
using namespace std;
class C
{
public:
    C(int a)
    {
        x = a;
    }
    void Printa(C A)
    {
        cout << A.x << endl;
        return;
    }

private:
    int x;
};
int main()
{
    C a(1), b(3);
    b.Printa(a);
    return (0);
}
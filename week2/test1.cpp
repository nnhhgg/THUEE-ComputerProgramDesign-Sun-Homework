#include <iostream>
using namespace std;

int &max(int a, int b)
{
    return (a > b ? a : b);
}

int main()
{
    int a;
    a = max(1, 2);
    cout << a << endl;
    return (0);
}
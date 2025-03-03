// 用C＋＋编程打印杨晖三角形，直到第10行。
// 格式为：
// 11112113311464115101051...........................................................
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int(*a)[11] = new int[10][11];
    a[0][0] = 0;
    a[0][1] = 1;
    a[0][2] = 0;
    for (int i = 0; i < 10; i++)
    {
        int j;
        a[i][0] = 0;
        cout << setw(9 - i) << " ";
        for (j = 0; j < i + 1; j++)
        {
            if (i > 0)
                a[i][j + 1] = a[i - 1][j] + a[i - 1][j + 1];
            cout << a[i][j + 1] << " ";
        }
        cout << endl;
        a[i][j + 1] = 0;
    }
    delete[] a;
    return (0);
}
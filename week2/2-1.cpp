// 用C＋＋编程实现：
//  动态一维数组a（100）、动态二维数组b（20×25）、动态三维数组c（9×8×5）、
//  动态二维数组d（m×n，m和n由键盘输入，可以输入25和20）的申请和释放，
//  将数组元素的值赋值为下标的组合：a[i]=i;b[i][j]=i*25+j;c[i][j][k]=i*100+j*10+k，d[i][j]=i*n+j;
//  并求每个数组的元素之和。

#include <iostream>
using namespace std;
int main()
{
    int *a = new int[100];
    int(*b)[25] = new int[20][25];
    int(*c)[8][5] = new int[9][8][5];
    int **d;
    int i, j;
    int asum(0), bsum(0), csum(0), dsum(0);
    cout << "Input i, j:" << endl;
    cin >> i >> j;
    d = new int *[i];
    for (int t = 0; t < i; t++)
    {
        d[t] = new int[j];
    }

    for (int t = 0; t < 100; t++)
    {
        a[t] = t;
        asum += a[t];
    }

    for (int t1 = 0; t1 < 20; t1++)
        for (int t2 = 0; t2 < 25; t2++)
        {
            b[t1][t2] = t1 * 25 + t2;
            bsum += b[t1][t2];
        }

    for (int t1 = 0; t1 < 9; t1++)
        for (int t2 = 0; t2 < 8; t2++)
            for (int t3 = 0; t3 < 5; t3++)
            {
                c[t1][t2][t3] = t1 * 100 + t2 * 10 + t3;
                csum += c[t1][t2][t3];
            }

    for (int t1 = 0; t1 < i; t1++)
        for (int t2 = 0; t2 < j; t2++)
        {
            d[t1][t2] = t1 * j + t2;
            dsum += d[t1][t2];
        }

    cout << asum << " " << bsum << " " << csum << " " << dsum << " " << endl;
    delete[] a;
    delete[] b;
    delete[] c;
    delete[] d;
    return (0);
}
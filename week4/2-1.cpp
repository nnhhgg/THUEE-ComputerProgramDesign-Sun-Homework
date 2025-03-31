#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Point
{
public:
    Point(int a = 0, int b = 0, int c = 0)
    {
        x = a;
        y = b;
        z = c;
    }
    Point(Point const &A)
    {
        x = A.x;
        y = A.y;
        z = A.z;
    }
    ~Point()
    {
        cout << "destruct complete ";
        Print();
        cout << endl;
    }

    void Print()
    {
        cout << "(" << x << ',' << y << ',' << z << ')';
        return;
    }
    void Set(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
    int GetX() const { return (x); }
    int GetY() const { return (y); }
    int GetZ() const { return (z); }

private:
    int x;
    int y;
    int z;
};

class Ball
{
public:
    Ball(int a = 0, int b = 0, int c = 0, int r = 0) : o(a, b, c)
    {
        cout << "construct complete" << endl;
        Ball::r = r;
    }
    Ball(const Ball &A) : o(A.o)
    {
        cout << "copy construct complete" << endl;
        r = A.r;
    }
    ~Ball()
    {
        cout << "destruct complete ";
        cout << o.GetX() << ',' << o.GetY() << ',' << o.GetZ() << ',' << r << endl;
    }
    void Set(int a, int b, int c, int r)
    {
        Ball::r = r;
        o.Set(a, b, c);
        return;
    }
    void Print()
    {
        o.Print();
        cout << ',' << r << endl;
        return;
    }
    int GetX() const { return (o.GetX()); }
    int GetY() const { return (o.GetY()); }
    int GetZ() const { return (o.GetZ()); }
    int GetR() const { return (r); }
    double Volume()
    {
        double temp;
        temp = 3.1415 * 4 / 3 * r * r * r;
        return (temp);
    }

private:
    Point o;
    int r;
};

Ball Average(const Ball *B, const Ball *C, int s1, int s2)
{
    int sumX = 0, sumY = 0, sumZ = 0, sumR = 0;
    int num = s1 + s2;
    for (int i = 0; i < s1; i++)
    {
        sumX += B[i].GetX();
        sumY += B[i].GetY();
        sumZ += B[i].GetZ();
        sumR += B[i].GetR();
    }
    for (int i = 0; i < s2; i++)
    {
        sumX += C[i].GetX();
        sumY += C[i].GetY();
        sumZ += C[i].GetZ();
        sumR += C[i].GetR();
    }
    return (Ball((double)sumX / num, (double)sumY / num, (double)sumZ / num, (double)sumZ / num));
}

double Average(const double *arr1, const double *arr2, int s1, int s2)
{
    double sumV = 0;
    for (int i = 0; i < s1; i++)
    {
        sumV += arr1[i];
    }
    for (int i = 0; i < s2; i++)
    {
        sumV += arr2[i];
    }
    return (sumV / (s1 + s2));
}

int Rand()
{
    return (rand() % 100);
}

void Sort(Ball arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j].GetR() > arr[j + 1].GetR())
            {
                Ball temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return;
}

int main()
{
    Ball B[10];
    Ball *C;
    C = new Ball[20];
    srand(0);
    for (int i = 0; i < 10; i++)
    {
        B[i].Set(Rand(), Rand(), Rand(), abs(Rand()));
    }
    for (int i = 0; i < 20; i++)
    {
        C[i].Set(Rand(), Rand(), Rand(), abs(Rand()));
    }
    // 打印每个球对象的(x,y,z)、r和体积；
    for (int i = 0; i < 10; i++)
    {
        B[i].Print();
    }
    for (int i = 0; i < 20; i++)
    {
        C[i].Print();
    }
    cout << "-------------------------" << endl;
    // 然后分别将对象数组按照其r值从小到大排序，并打印排序后每个对象的(x,y,z)、r和体积；
    Sort(B, 10);
    Sort(C, 20);
    double Bv[10];
    double Cv[20];
    for (int i = 0; i < 10; i++)
    {
        B[i].Print();
        cout << "Volume=" << (Bv[i] = B[i].Volume()) << endl;
    }
    for (int j = 0; j < 20; j++)
    {
        C[j].Print();
        cout << "Volume=" << (Cv[j] = C[j].Volume()) << endl;
    }
    cout << "-------------------------" << endl;
    Ball aver = Average(B, C, 10, 20);
    double averV = Average(Bv, Cv, 10, 20);
    aver.Print();
    cout << averV << endl;
    delete[] C;
    return (0);
}

// String类的友元函数。
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class String
{
public:
    String(char *a, int len)
    {
        this->str = new char[len];
        strcpy(str, a);
        cout << "constructor" << '(' << str << ')' << endl;
    }
    String(const String &A)
    {

        int len = strlen(A.str) + 1;
        str = new char[len];
        strcpy(str, A.str);
        cout << "copy constructor" << '(' << str << ')' << endl;
    }
    ~String()
    {
        cout << "destructor" << '(' << str << ')' << endl;
        delete[] str;
    }
    void Set(char *a, int len)
    {
        delete[] str;
        str = new char[len];
        strcpy(str, a);
        return;
    }
    void Print()
    {
        cout << str << endl;
        return;
    }
    //"=="、">"、“<"、"!="、">="、"<="
    friend int operator==(const String op1, const String op2);
    friend int operator>(const String op1, const String op2);
    friend int operator<(const String op1, const String op2);
    friend int operator!=(const String op1, const String op2);
    friend int operator>=(const String op1, const String op2);
    friend int operator<=(const String op1, const String op2);

private:
    char *str;
};

int operator==(const String op1, const String op2)
{
    if (strcmp(op1.str, op2.str) == 0)
        return (1);
    else
        return (0);
}
int operator>(const String op1, const String op2)
{
    if (strcmp(op1.str, op2.str) == 1)
        return (1);
    else
        return (0);
}
int operator<(const String op1, const String op2)
{
    if (strcmp(op1.str, op2.str) == -1)
        return (1);
    else
        return (0);
}
int operator!=(const String op1, const String op2)
{
    if (strcmp(op1.str, op2.str))
        return (1);
    else
        return (0);
}
int operator>=(const String op1, const String op2)
{
    if ((op1.str == op2.str) || (op1.str > op2.str))
        return (1);
    else
        return (0);
}
int operator<=(const String op1, const String op2)
{
    if ((op1.str == op2.str) || (op1.str < op2.str))
        return (1);
    else
        return (0);
}
int main()
{
    char a[] = "abcd", b[] = "abce";
    String s1(a, strlen(a) + 1), s2(b, strlen(b) + 1);
    if (s1 > s2)
        cout << "s1 > s2!\n";
    else if (s1 < s2)
        cout << "s1 < s2!\n";
    if (s1 >= s2)
        cout << "s1 >= s2!\n";
    else if (s1 <= s2)
        cout << "s1 <= s2!\n";
    if (s1 == s2)
        cout << "s1 == s2\n";
    else if (s1 != s2)
        cout << "s1 != s2\n";
    return (0);
}
// 复制构造中不要有delete！！！
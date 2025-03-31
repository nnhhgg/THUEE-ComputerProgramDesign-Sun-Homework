// 编写程序，通过定义一个字符串类String， 其私有成员为一个字符串指针。

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class String
{
public:
    String()
    {
        str = new char;
        strcpy(str, "\0");

        cout << "constructor" << '(' << str << ')' << endl;
    }
    String(char *c)
    {
        int len = strlen(c) + 1;
        str = new char[len];
        strcpy(str, c);
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
    void Set(char *c)
    {
        delete[] str;
        int len = strlen(c) + 1;
        str = new char[len];
        strcpy(str, c);
        return;
    }
    void Print()
    {
        cout << str << endl;
        return;
    }
    // 将6个关系运算操作符"=="、">"、“<"、"!="、">="、"<="的重载函数重载为String类的成员函数
    int operator==(const String op)
    {
        if (strcmp(str, op.str) == 0)
        {
            return (1);
        }
        else
            return (0);
    }
    int operator>(const String op)
    {
        if (strcmp(str, op.str) == 1)
            return (1);
        else
            return (0);
    }
    int operator<(const String op)
    {
        if (strcmp(str, op.str) == -1)
            return (1);
        else
            return (0);
    }
    int operator!=(const String op)
    {
        if (strcmp(this->str, op.str) != 0)
            return (1);
        else
            return (0);
    }
    int operator>=(const String op)
    {
        if ((this->str > op.str) || (this->str == op.str))
            return (1);
        else
            return (0);
    }
    int operator<=(const String op)
    {
        if ((this->str < op.str) || (this->str == op.str))
            return (1);
        else
            return (0);
    }

private:
    char *str;
};

int main()
{
    char a[] = "abcd", b[] = "abce";
    String s1(a), s2(b);
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
        cout << "s1!=s2\n";
    return (0);
}
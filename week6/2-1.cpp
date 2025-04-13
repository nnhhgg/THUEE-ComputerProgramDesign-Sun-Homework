#include <iostream>
#include <cstring>
using namespace std;
class String
{
    // 设计带缺省值的构造函数、复制构造函数、析构函数、设置新值函数Set、打印成员值函数Print。
public:
    String(char *s = "");
    String(const String &p);
    ~String();
    void Set(char *p);
    void Print();
    String &operator=(const String &);
    String &operator+=(const String &);
    friend String operator+(const String &, const String &);

private:
    char *str;
};

String::String(char *p)
{
    int len = strlen(p);
    str = new char[len + 1];
    strcpy(str, p);
    cout << "constructor" << endl;
}
String::String(const String &p)
{
    int len = strlen(p.str);
    str = new char[len + 1];
    strcpy(str, p.str);
    cout << "copy constructor" << endl;
}
String::~String()
{
    delete[] str;
    cout << "destructor" << endl;
}
void String::Set(char *p)
{
    delete[] str;
    int len = strlen(p);
    str = new char[len + 1];
    strcpy(str, p);
    return;
}
void String::Print()
{
    cout << str << endl;
    return;
}
// 将操作符 + 重载函数设置为String类的友元函数，将操作符 = 重载函数设置为String类的成员函数，
//+和=重载操作符函数形参都用常引用方式。实现对操作符 + 和 = 的重载，
// 使之能直接把两个String类类型的字符串进行串接并赋值。
String operator+(const String &obj1, const String &obj2)
{
    int len = strlen(obj1.str) + strlen(obj2.str);
    char *temp = new char[len + 1];
    strcpy(temp, obj1.str);
    strcat(temp, obj2.str);
    return (String(temp));
}
String &String::operator=(const String &obj)
{
    delete[] str;
    int len = strlen(obj.str);
    str = new char[len + 1];
    strcpy(str, obj.str);
    return *this;
}
// String类的定义同上题。借助此String类，将操作符 += 重载函数设置为String类的成员函数，
// 操作符函数形参用常引用方式。实现对操作符 += 的重载，使 s1 += s2;
// 能直接把一个String类类型的字符串s2串接在另一个String类类型的字符串s1尾上，类似strcat(s1,s2);
String &String::operator+=(const String &obj)
{
    int len2 = strlen(obj.str);
    char *temp2 = new char[len2 + 1];
    strcpy(temp2, obj.str);
    int len1 = strlen(str);
    char *temp1 = new char[len1 + 1];
    strcpy(temp1, str);
    delete[] str;

    str = new char[len1 + len2 + 1];
    strcpy(str, temp1);
    strcat(str, temp2);
    return (*this);
}

int main()
{
    // String s1("abcd"), s2("efghij"), s3("lmnop"), s4, s5;

    // s4 = s1 + s2 + s3;
    // s4.Print(); // 输出结果应该是 abcdefghijlmnop

    // s5 = s5 + s3 + s4;
    // s5.Print(); // 输出结果应该是 lmnopabcdefghijlmnop
    // String str1("abcd"), str2("abcde"), str3("a");
    // str1.Print();
    // (str1 = str2) = str3;
    // str1.Print();
    // str1 = str3 + str2;
    // str1.Print();
    String s1("abcd"), s2("efghij"), s3("lmnop");
    s1.Print();
    s2.Print();
    s1 += s2;
    s1.Print(); // 输出结果应该是 abcdefghij

    s3 += s3 += s2;
    s3.Print(); // 输出结果应该是 lmnopefghij lmnop efghij
    return (0);
}

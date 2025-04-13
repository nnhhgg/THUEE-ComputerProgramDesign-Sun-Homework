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

int main()
{
    String s1("abcd"), s2("efghij"), s3("lmnop"), s4, s5;

    s4 = s1 + s2 + s3;
    s4.Print(); // 输出结果应该是 abcdefghijlmnop

    s5 = s5 + s3 + s4;
    s5.Print(); // 输出结果应该是 lmnopabcdefghijlmnop
    String str1("abcd"), str2("abcde"), str3("a");
    str1.Print();
    (str1 = str2) = str3;
    str1.Print();
    str1 = str3 + str2;
    str1.Print();
    return (0);
}
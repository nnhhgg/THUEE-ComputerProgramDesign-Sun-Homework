#include <iostream>
#include <cstring>
using namespace std;
class String
{
public:
    String(const char *a = "");
    // 注意：这里缺省值应设为空字符串""而不是NULL空指针
    ~String();
    String(const String &str2);
    void Set(const char *a);
    void Print() const;
    String operator=(String str2);

private:
    char *p;
};
String::String(const char *a)
{
    this->p = new char[strlen(a) + 1];
    strcpy(p, a);
    cout << "****constructor****";
    Print();
}
String String::operator=(String str2)
{
    delete[] this->p;
    this->p = new char[strlen(str2.p) + 1];
    strcpy(this->p, str2.p);
    return *this;
}
String::String(const String &str2)
{
    this->p = new char[strlen(str2.p) + 1];
    strcpy(this->p, str2.p);
    cout << "****copy constructor****";
    Print();
}
String ::~String()
{
    delete[] p;
    cout << "****destructor****" << endl;
}
void String::Set(const char *a)
{
    delete[] p;
    this->p = new char[strlen(a) + 1];
    strcpy(this->p, a);
}
void String::Print() const
{
    cout << "string: " << p << endl;
}

int main()
{
    String str1("abcd"), str2("abc"), str3("ab");
    str1.Print();
    str2.Print();
    str3.Print();
    (str1 = str2) = str3;
    str1.Print();
    return (0);
}
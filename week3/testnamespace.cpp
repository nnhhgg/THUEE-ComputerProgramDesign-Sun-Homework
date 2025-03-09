#include <iostream>
using namespace std;
int const num = 1;
namespace n1
{
    int num = 5;
    int add(int num)
    {
        num = num + n1::num + ::num;
        return (num); // 11;
    }
}
int main()
{
    using namespace n1;
    cout << ::num << endl;
}
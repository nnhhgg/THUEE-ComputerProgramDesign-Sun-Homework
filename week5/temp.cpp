#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Account
{
private:
    int no;
    char name[10];
    float money;

public:
    Account(int id, char *n, float m);
    void Deposit();
    void Withdraw();
    void Show();
};
Account::Account(int id, char *n, float m)
{
    no = id;
    strcpy(name, n);
    money = m;
}
void Account::Show()
{
    cout << no << ":" << money << endl;
}
void Account::Deposit()
{
    float amount;
    cin >> amount;
    money += amount;
    Show();
}
void Account::Withdraw()
{
    float amount;
    cin >> amount;
    if (money < amount)
    {
        cout << no << ":" << money << endl;
    }
    else
    {
        money -= amount;
        Show();
    }
}
int main()
{
    int objno;
    char objname[10];
    float objmoney;
    cin >> objno >> objname >> objmoney;
    Account obj(objno, objname, objmoney);

    int choice;
    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.Deposit();
            break;
        case 2:
            obj.Withdraw();
            break;
        case 3:
            obj.Show();
            break;
        case 0:
            return 0;
        }
    }
    return 0;
}
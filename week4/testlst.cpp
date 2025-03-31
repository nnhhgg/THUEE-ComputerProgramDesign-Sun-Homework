#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
class List
{
public:
    List()
    {
        first = current = NULL;
    }
    int Insert(int x, int i); // 在第i个元素后面插入节点，节点为x；
    int Remove(int &x, int i);
    int Print();

private:
    class ListNode
    {
    public:
        int data;
        ListNode *next;
        ListNode(int x, ListNode *p)
        {
            data = x;
            next = p;
        }
    };
    ListNode *first, *current;
};

int List::Insert(int x, int i)
{
    ListNode *p = current;
    current = first;
    for (int k = 0; k < i - 1; k++)
    {
        if (current == NULL)
            break;
        else
            current = current->next;
    }
    if (current == NULL && first != NULL) ///
    {
        cout << "invalid insert node!" << endl;
        current = p;
        return (0);
    } // 此时已经能成功插入；
    ListNode *newnode = new ListNode(x, NULL);
    if (first == NULL || i == 0)
    {
        newnode->next = first;
        first = current = newnode;
    }
    else
    {
        newnode->next = current->next;
        current->next = newnode;
        current = newnode;
    }
    return (1);
}
int List::Remove(int &x, int i)
{
    if (first == NULL)
    {
        cout << "empty list" << endl;
        return (0);
    }
    ListNode *p = current;
    ListNode *q = NULL; // q为要删除的节点；
    current = first;
    if (i == 0)
    {
        q = first;
        current = first = first->next;
    }
    else
    {
        for (int k = 0; k < i - 1; k++) // 找到前一个节点，方便删除；
        {
            if (current == NULL)
                break;
            current = current->next;
        }
        if (current->next == NULL)
        {
            cout << "invalid node position" << endl;
            current = p;
            return (0);
        }
        else
        {
            q = current->next;
        }
    }
    x = q->data;
    delete q;
    return (1);
}
int List::Print()
{
    current = first;
    ListNode *p;
    if (current == NULL)
    {
        cout << "empty list" << endl;
        return (0);
    }
    else
    {
        while (current)
        {
            cout << current->data;
            if (current->next)
            {
                cout << "-->";
            }
            p = current;
            current = current->next;
        }
        current = p;
        cout << endl;
        return (1);
    }
}

int main()
{
    class List a;
    a.Insert(1, 0);
    a.Insert(2, 0);
    a.Insert(3, 0);
    a.Print();
    return (0);
}
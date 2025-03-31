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
    int Len();
    int Print();
    int Swap(int i, int j);
    int GetData(int &x, int i);

    int Sort(); // small->big

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
int List::Swap(int i, int j)
{
    if (i == j)
        return (1);
    if (j == 0)
    {
        int temp = i;
        i = j;
        j = temp;
    }

    ListNode *p = first, *q = first;
    for (int a; a < i - 1; a++)
    {
        if (p == NULL)
        {
            cout << "invalid swap" << endl;
            return (0);
        }
        else
            p = p->next;
    }
    for (int b; b < j - 1; b++)
    {
        if (q == NULL)
        {
            cout << "invalid swap" << endl;
            return (0);
        }
        else
            q = q->next;
    }
    if (p->next == NULL || q->next == NULL)
    {
        cout << "invalid swap" << endl;
        return (0);
    }
    if (i == 0)
    {
        ListNode *temp = q->next;
        q->next = first;
        // swap:first->next = temp->next;
        {
            ListNode *t = first->next;
            first->next = temp->next;
            temp->next = t;
        }
        first = temp;
    }
    else
    {
        ListNode *p1 = p->next,
                 *q1 = q->next;
        {
            ListNode *t = p->next;
            p->next = q->next;
            q->next = t;
        }
        {
            ListNode *t = p1->next;
            p1->next = q1->next;
            q1->next = t;
        }
    }
    return (1);
}
int List::Len()
{
    int num = 0;
    current = first;
    while (current)
    {
        num++;
        current = current->next;
    }
    return (num);
}
int List::GetData(int &x, int i)
{
    current = first;
    if (i == 0)
        return (first->data);
    else
    {
        for (int k = 0; k < i - 1; k++)
        {
            if (current == NULL)
            {
                cout << "invalid" << endl;
                return (0);
            }
            current = current->next;
        }
        if (current->next == NULL)
        {
            cout << "invalid position" << endl;
            return (0);
        }
        else
        {
            x = current->next->data;
            return (1);
        }
    }
}
int List::Sort()
{
    int len = Len();
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            int x(0), y(0);
            GetData(x, j);
            GetData(y, j + 1);
            if (x > y)
            {
                Swap(j, j + 1);
            }
        }
    }
    return (1);
}

// 从键盘上读入若干无序正整数，用类方式封装建立从小到大的有序单链表，打印排序后的单链表元素值，并释放单链表。
int main()
{
    class List a;
    a.Insert(1, 0);
    a.Insert(2, 0);
    a.Insert(3, 0);
    a.Print();
    a.Swap(0, 1);
    a.Print();
    a.Swap(1, 2);
    a.Print();
    a.Sort();
    a.Print();

    return (0);
}
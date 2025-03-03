// 口袋中有红、橙、黄、绿、青、蓝、紫7种颜色的球，每次从口袋中取出3个不同颜色的球，
// 问有多少种取法(认为“红、黄、蓝”和“红、蓝、黄”是同一种)，并给出每种取法的球的颜色。试用C++编程实现。
#include <iostream>
using namespace std;
typedef struct node
{
    int a[3];
    struct node *next;
} NODE;

void create(NODE *&q, int t[3]) // q--last node
{
    NODE *p, *temp, *qp = q;
    p = new NODE;
    for (int i = 0; i < 3; i++)
    {
        p->a[i] = t[i];
    }
    p->next = NULL;
    temp = q;
    if (q == NULL)
        q = p;
    else
    {
        while (qp)
        {
            temp = qp;
            qp = qp->next;
        }
        temp->next = p;
    }
    return;
}

int isRe(NODE *head, int t[3]) //
{
    while (head)
    {
        int flag[3] = {0, 0, 0};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (t[i] == head->a[j])
                    flag[i] = 1;
            }
        }
        if ((flag[0] == 1) && (flag[1] == 1) && flag[2] == 1)
            return (1);
        head = head->next;
    }
    return (0);
}

void printlst(NODE *head)
{
    char c[7][10] =
        {
            {"1"},
            {"2"},
            {"3"},
            {"4"},
            {"5"},
            {"6"},
            {"7"}};
    while (head)
    {
        cout << c[head->a[0]] << " " << c[head->a[1]] << " " << c[head->a[2]] << endl;
        head = head->next;
    }
    return;
}

int main()
{
    NODE *head(NULL);
    int a[3];
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            for (int k = 0; k < 7; k++)
            {
                a[0] = i, a[1] = j, a[2] = k;
                if (((i != j) && (k != j) && (i != k)) && (!isRe(head, a)))
                {
                    create(head, a);
                }
            }
    printlst(head);
    system("pause");
    return (0);
}
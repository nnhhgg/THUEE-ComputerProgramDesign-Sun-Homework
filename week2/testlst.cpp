#include <iostream>
using namespace std;
typedef struct node
{
    int a[3];
    struct node *next;
} NODE;

void create()
{
    NODE *head, *p, *q;
    p = new NODE;
    for (int i = 0; i < 3; i++)
        p->a[i] = 0;
    p->next = NULL;
}
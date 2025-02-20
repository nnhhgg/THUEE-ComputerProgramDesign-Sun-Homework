// 141. 编写程序，从文本文件中读入一篇英文文章，统计这篇文章中所使用的单词的个数与词频，
// 并按词频从高到低依次逐行列出本文所使用的单词与词频（词频相同时单词按字典序列出）。
// 说明：
// 英文段落中包含各种标点符号，某些单词开头字母可能大写或者全单词大写，
// 文中也可能包含数字等，请尽量考虑各种英文文章的实际情况，使得你编写的程序具有通用性。
// 链表来写
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char c[20];
    int t;
    struct node *next;
} NODE;

NODE *lstend(NODE *head)
{
    NODE *temp = head;
    while (head)
    {
        temp = head;
        head = head->next;
    }
    return (temp); // 如果是空链表，则返回NULL；
}

NODE *lstfind(char *str, NODE *head)
{
    while (head)
    {
        if (strcmp(str, head->c) == 0)
            return (head);
        head = head->next;
    }
    return (head);
}

void add(NODE *p)
{
    p->t++;
    return;
}

void creat(char *str, NODE **head)
{
    NODE *q = lstend(*head);
    NODE *p;
    p = (NODE *)malloc(sizeof(NODE));
    if (p == NULL)
    {
        printf("Can't creat!\n");
        exit(2);
    }
    strcpy(p->c, str);
    p->t = 1;
    p->next = NULL;
    if (q == NULL) // head原本就是个空链表；
    {
        *head = p;
    }
    else
        q->next = p;
    return;
}

void lstprint(NODE *head)
{
    while (head)
    {
        printf("%s : ", head->c);
        printf("%d\n", head->t);
        head = head->next;
    }
    return;
}

int main()
{
    FILE *fp;
    NODE *head = NULL, *temp;
    char str[20] = {0};
    fp = fopen("1.dat", "r");
    if (fp == NULL)
    {
        printf("Can't open file!\n");
        exit(1);
    }
    while (!feof(fp))
    {
        fscanf(fp, "%s", str);

        temp = lstfind(str, head);
        if (temp == NULL)
        {
            creat(str, &head);
        }
        else
        {
            add(lstfind(str, head));
        }
    }
    lstprint(head);
}
// 141. 编写程序，从文本文件中读入一篇英文文章，统计这篇文章中所使用的单词的个数与词频，
// 并按词频从高到低依次逐行列出本文所使用的单词与词频（词频相同时单词按字典序列出）。
// 说明：
// 英文段落中包含各种标点符号，某些单词开头字母可能大写或者全单词大写，
// 文中也可能包含数字等，请尽量考虑各种英文文章的实际情况，使得你编写的程序具有通用性。
// 数组来写
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <ctype.h>
int l = 0; // 表示总共有多少个不同单词

int isAlpha(char c)
{
    if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'))
        return (1);
    else
        return (0);
}

int toWord(char *c)
{
    int left = 0, right = 19;
    int i = 0;
    char temp[20];
    strcpy(temp, c);
    while ((left < 20) && (!isAlpha(c[left])))
        left++;
    while ((right > -1) && (!isAlpha(c[right])))
        right--;
    if (left == 20)
        return (0); // 意味着没有c里面没有字母；
    else
    {
        for (i = 0; i < right - left + 1; i++)
        {
            c[i] = temp[left + i];
        }
        c[i] = '\0';
        return (1);
    }
}

int same(char *a, char *b) // 相同返回1，不相同返回0；
{
    if (a == NULL)
        return (0);
    else if ((a == strstr(a, b)) && (strlen(a) == strlen(b)))
        return (1);
    else
        return (0);
}

int count(char *c, int **a, char((**p)[20]))
{
    int i;
    for (i = 0; i < l; i++)
    {
        if (same((*p)[i], c))
        {
            (*a)[i]++;
            break;
        }
    }
    if (i == l)
    {
        *p = (char(*)[20])realloc(*p, sizeof(char) * 20 * (l + 1));
        *a = (int *)realloc(*a, sizeof(int) * (l + 1));
        strcpy((*p)[l], c);
        (*a)[l] = 1;
        l++;
    }
    return (0);
}

int main()
{
    FILE *fp;
    char str[20] = {0};
    int *a = NULL;
    char(*p)[20] = NULL;
    fp = fopen("1.dat", "r");
    while (!feof(fp))
    {
        for (int i = 0; i < 20; i++)
        {
            str[i] = '\0';
        }
        fscanf(fp, "%s", str);
        if (toWord(str) == 0)
            continue;
        count(str, &a, &p);
    }
    for (int i = 0; i < l; i++)
    {
        printf("%s : ", p[i]);
        printf("%d\n", a[i]);
    }
}

// 链表来写
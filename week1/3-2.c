// （探究题，选做）编写程序，将一段文字中出现的所有英文阿拉伯数字和中文阿拉伯数字转化成（按照人们习惯的读音）中文。
// 比如：“我去购物中心花2021元买了一块手表”，其中的：“2021”是英文阿拉伯数字，
// 每个数字占一个字节，应该按照读音转化为：“两千零二十一”。
// 也可能写作：“我去购物中心花２０２１元买了一块手表”，
// 其中的“２０２１”是中文格式的阿拉伯数字，每个数字占两个字节，也应该按照读音转化为：“两千零二十一”。
// 又比如：“他花108050元买了一辆新电动车"，其中的："108050"应该按照人们读音习惯转化为："十万八千零五十"。
// 转化单位包括：亿、万、千、百、十......
// 更进一步，可以转化带小数的数字，例如将："121.14156“ 转化为:"一百二十一点一四一五六"。
// 如何判断是否是英文阿拉伯数字和中文阿拉伯数字:
// for(k=0; k<strlen(str); k++)
//     if (str[k]>=‘0’ && str[k]<=‘9’)
// unsigned char zero[]="０", nine[]="９";
// for(k=0; k<strlen(str); k++)
//     if ((str[k]>=zero[0] && str[k]<=nine[0]) && (str[k+1]>=zero[1]) && str[k+1]<=nine[1]))
// 注意：
// ①在VS上调试程序时，用GBK编码方式（两个字节），不要用Unicode方式（多字节）。
// ②不要出现跨字的问题，因为每个汉字占两个字节，顺序向后遍历字符串时，
//  容易出现把第一个汉字的第二个字节与第二个汉字的第一个字节当作一个汉字来判断，出现跨字错误。
// 我们这里用utf-8编码方式。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void pre(int *n1, int w1, int *n2, int w2, FILE *fout)
{
    char Cnum[10][20] =
        {
            "零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};
    char Cpos[10][20] =
        {
            "个", "十", "百", "千", "万", "十万", "百万", "千万", "亿"};
    int i;
    int pos;
    int flag = 0;
    for (i = 0; i < w1; i++)
    {
        pos = w1 - 1 - i;

        switch (flag)
        {
        case (1): // 一直到这里是0；
        {
            if (*n1)
            {
                fprintf(fout, "零");

                fprintf(fout, "%s", Cnum[*n1]);
                if (pos % 4)
                    fprintf(fout, "%s", Cpos[pos % 4]);
                flag = 0;
            }
            else if (!*n1)
                ;
        }
        case (0):
        {
            if (*n1 == 0)
                flag = 1;
            else
            {
                fprintf(fout, "%s", Cnum[*n1]);
                if (pos % 4)
                    fprintf(fout, "%s", Cpos[pos % 4]);
            }
        }
        }
        if (!(pos % 4) && pos)
            fprintf(fout, "%s", Cpos[pos]);
        n1++;
    }

    for (i = 0; i < w2; i++)
    {
        fprintf(fout, "%s", Cnum[*n2]);
        n2++;
    }
    fprintf(fout, "\n");
    return;
}

int main()
{
    FILE *fin, *fout;
    char c;
    int w1, w2;
    int n1[30], n2[30]; // n1.n2;
    int a;

    fin = fopen("3.dat", "r");
    fout = fopen("3out.dat", "w");
    if (fin == NULL || fout == NULL)
    {
        printf("Can't open file");
        exit(1);
    }
    c = fgetc(fin);
    while (c != EOF)
    {
        if (isdigit(c))
        {
            int i = 0, j = 0;
            while (isdigit(c))
            {
                n1[i] = c - '0';
                i++;
                c = fgetc(fin);
            }
            w1 = i; // w1是n1的位数；

            i = 0;
            if (c == '.')
            {
                c = fgetc(fin);
                while (isdigit(c))
                {
                    n2[i] = c - '0';
                    i++;
                    c = fgetc(fin);
                }
            }
            w2 = i; // w2是n2的位数；

            pre(n1, w1, n2, w2, fout);
        }
        else
            c = fgetc(fin);
    }
    fclose(fin);
    fclose(fout);
}
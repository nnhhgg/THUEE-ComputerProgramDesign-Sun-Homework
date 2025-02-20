// 2. 编写程序，从一个二进制文件中读入若干个字节，将每一个字节的8位逆转后，
// 按字节的输入顺序输出到另一个二进制文件中。这里的逆转是指：
// 当unsigned char k=0xAC(二进制值为：10101100)逆转后k的值为：0x35(二进制值为：00110101)
// 并考虑当文件中的数据量很大时（比如，几百MB, 几百GB甚至几百TB），如何优化此程序，使其执行效率最高。
// 写出优化思路并给出优化后的程序。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct a
{
    char c[5];
} A;

int inifile(FILE *fp)
{
    int x[5] = {10000000, 20000000, 30000000, 40000000, 50000000};
    for (int i = 0; i < 9999; i++)
    {
        fwrite(x, sizeof(int), 5, fp);
    }
    return (0);
}

int reverse(int a)
{
    int i;
    int temp = 0;
    temp = temp | (((a << 7) & 0x80808080) | ((a >> 7) & 0x01010101));
    temp = temp | (((a << 5) & 0x40404040) | ((a >> 5) & 0x02020202));
    temp = temp | (((a << 3) & 0x20202020) | ((a >> 3) & 0x04040404));
    temp = temp | (((a << 1) & 0x10101010) | ((a >> 1) & 0x08080808));
    return (temp);
}
int main()
{
    FILE *fp, *fin, *fout;
    int a, b, i;
    fp = fopen("2.dat", "wb");
    inifile(fp);
    fclose(fp);

    fin = fopen("2.dat", "r+b");
    fout = fopen("2out.dat", "wb");

    while (i = fread(&a, sizeof(int), 1, fin))
    {
        b = reverse(a);
        fwrite(&b, sizeof(int), 1, fout);
    }
    fclose(fin);
    fclose(fout);
    return (0);
}

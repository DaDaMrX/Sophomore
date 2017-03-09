/*
1.序列可简单图化
Description
判断数列是否可序列化。给定一个非负整数序列 (d1,d2,...dn) ，若存在一个无向简单图使得图中各点的度与此序列一一对应，则称此序列可简单图化。

Input
输入有两行
第一行输入一个整数 N ，代表序列中非负整数的个数。 N <= 3000
第二行 N 个元素以空格隔开，代表这 N 个非负整数所组成的序列。

Output
测试结果有一行输出
yes 代表此序列可简单图化
no 代表此序列不可简单图化
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 3e3 + 10;

int n, sum;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        int d;
        scanf("%d", &d);
        sum += d;
    }
    printf("%s\n", sum & 1 ? "no" : "yes");
    return 0;
}

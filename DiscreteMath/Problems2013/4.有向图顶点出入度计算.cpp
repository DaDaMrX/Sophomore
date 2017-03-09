/*
4.有向图顶点出入度计算
Description
求有向图所有顶点的出度与入度。

Input
输入若干行
第一行为正整数N（0<N<=100），代表图中点的个数
接下来N行，每行有N个数据，每个数据以空格分隔，代表邻接矩阵。
注意：输入的都是有向图

Output
输出有N行 每行都是数字，每行格式都是：a b 其中a为出度，b为入度
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 110;

int n, out[N], in[N];

int main()
{
    scanf("%d", &n);
    memset(out, 0, sizeof(out));
    memset(in, 0, sizeof(in));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int a;
            scanf("%d", &a);
            out[i] += a;
            in[j] += a;
        }
    for (int i = 1; i <= n; i++) printf("%d %d\n", out[i], in[i]);
    return 0;
}

/*
3.无向图连通性判断
Description
判断一个无向图是否为连通图。输入为无向图的邻接矩阵。

Input
输入有若干行
第一行为正整数N（0<N<=3000），代表图中点的个数
接下来N行，每行有N个数据，每个数据以空格分隔，代表邻接矩阵。

Output
一行。
连通，输出yes；
否则，输出no。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 3e3 + 10;

int n, adj[N][N];

void warshall()
{
    for (int i = 1; i <= n; i++) adj[i][i] = 1;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
    }
}

bool connected()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!adj[i][j]) return false;
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);
    warshall();
    printf("%s\n", connected() ? "yes" : "no");
    return 0;
}

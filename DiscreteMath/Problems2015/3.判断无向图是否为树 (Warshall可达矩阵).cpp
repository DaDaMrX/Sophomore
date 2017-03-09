/********************************************************************************
3.判断无向图是否为树 (Warshall可达矩阵)
树的若干等价定义：1.m=n-1 2.连通
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

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
    int m = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &adj[i][j]);
            m += adj[i][j];
        }
    if (m / 2 != n - 1)
    {
        printf("no\n");
        return 0;
    }
    warshall();
    printf("%s\n", connected() ? "yes" : "no");
    return 0;
}

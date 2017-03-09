/*
2.图的连通性强弱判断
Description
判断一个图是否为强连通图、单向连通图、弱连通图。以有向图的邻接矩阵形式输入。

Input
输入有若干行
第一行为正整数N（0<N<=100），代表图中点的个数
接下来N行，每行有N个数据，每个数据以空格分隔，代表邻接矩阵。
注意：输入的都是连通图。

Output
输出有一行，数字1,2,3
1代表强连通图
2代表单向连通图
3代表弱连通图
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 110;

int n, adj[N][N];

void warshall()
{
    for (int i = 1; i <= n; i++) adj[i][i] = 1;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
}

int check()
{
    int flag = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (!adj[i][j] && !adj[j][i]) return 3;
            if ((adj[i][j] && !adj[j][i]) || (!adj[i][j] && adj[i][j])) flag = 2;
        }
    return flag;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);
    warshall();
    printf("%d\n", check());
    return 0;
}

/*
Minimum Spanning Tree (Prim)
1. 时间复杂度 O(n^2)，与边数无关，适于边稠密的图
2. 图以邻接矩阵存储
3. 辅助数组dis[i]: 节点i到当前生成树的距离
   节点i与生成树不连通 dis[i] = INF
   节点i已在生成树中 dis[i] = 0
4. 算法描述
   初始化dis[]数组，从节点1开始添加
   以此添加其余n-1个节点
        选出当前不在生成树中的，距生成树最近的节点u
        把u加到生成树中
        用u松弛不在生成树的中的其他节点
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int adj[N][N];
int n, m;

int dis[N];
int prim()
{
    int ans = 0;
    dis[1] = 0;
    for (int i = 2; i <= n; i++) dis[i] = adj[1][i];
    for (int i = 2; i <= n; i++)
    {
        int u = -1;
        for (int j = 1; j <= n; j++)
            if (dis[j] && (u == -1 || dis[j] < dis[u]))
                u = j;
        ans += dis[u];
        dis[u] = 0;
        for (int v = 1; v <= n; v++)
            if (adj[u][v] < INF && dis[v])
                dis[v] = min(dis[v], adj[u][v]);
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(adj, 0x7f, sizeof(adj));
    while (m--)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (w < adj[u][v]) adj[u][v] = adj[v][u] = w;
    }

    int ans = prim();

    printf("%d\n", ans);
    return 0;
}

/*
INPUT
6 10
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6

OUTPUT
15

*/

/************************************************************
S15.无向图的各连通分支
因为对输出有顺序要求，故图选用邻接矩阵存储为宜。
************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int n, m;
int adj[N][N];

bool vis[N];
queue<int> q;
void bfs(int start)
{
    while (!q.empty()) q.pop();
    printf("%d", start);
    q.push(start); vis[start] = true;
    while (!q.empty())
    {
        int from = q.front(); q.pop();
        for (int to = 1; to <= n; to++)
            if (adj[from][to] && !vis[to])
            {
                printf("-%d", to);
                q.push(to); vis[to] = true;
            }
    }
    printf("\n");
}

int main()
{
    scanf("%d", &n);
    memset(adj, 0, sizeof(adj));
    int u, v;
    while (scanf("%d%d", &u, &v), u != -1)
        adj[u][v] = adj[v][u] = 1;

    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
        if (!vis[i]) bfs(i);
    return 0;
}

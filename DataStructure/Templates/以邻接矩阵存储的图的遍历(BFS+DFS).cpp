/*
以邻接矩阵存储的图的遍历(DFS+BFS)

INPUT
节点数n，边数m
每条无向边的两个端点u, v (编号从1开始)

OUTPUT
从1开始的DFS序
从1开始的BFS序
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int n, m;
bool map[N][N];

bool vis[N];
void dfs(int u)
{
    printf("%d ", u); vis[u] = true;
    for (int v = 1; v <= n; v++)
        if (map[u][v] && !vis[v])
        {
            dfs(v);
        }
}

queue<int> q;
void bfs(int start)
{
    while (!q.empty()) q.pop();
    memset(vis, false, sizeof(vis));
    printf("%d ", start);
    q.push(start); vis[start] = true;
    while (!q.empty())
    {
        int from = q.front(); q.pop();
        for (int to = 1; to <= n; to++)
            if (map[from][to] && !vis[to])
            {
                printf("%d ", to);
                q.push(to); vis[to] = true;
            }
    }
}

int main()
{
    memset(map, false, sizeof(map));
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        map[u][v] = map[v][u] = true;
    }

    memset(vis, false, sizeof(vis));
    dfs(1);
    printf("\n");

    bfs(1);
    printf("\n");
    return 0;
}

/*
SAMPLE INPUT
8 9
1 2
1 3
2 4
2 5
3 6
3 7
4 8
5 8
6 7

SAMPLE OUTPUT
1 2 4 8 5 3 6 7 
1 2 3 4 5 6 7 8 

*/

/*
以静态邻接表存储的图的遍历(DFS+BFS)

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
const int M = 1e3 + 10;

struct Edge
{
    int to, next;
} edge[M];
int head[N], no;
int n, m;

void init()
{
    memset(head, -1, sizeof(head));
    no = 0;    
}

void add(int u, int v)
{
    edge[no].to = v;
    edge[no].next = head[u];
    head[u] = no++;
}

bool vis[N];
void dfs(int u)
{
    printf("%d ", u);
    vis[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next)
        if (!vis[edge[i].to])
        {
            dfs(edge[i].to);
        }
}

queue<int> q;
void bfs(int start)
{
    memset(vis, false, sizeof(vis));
    while (!q.empty()) q.pop();
    printf("%d ", start);
    q.push(start); vis[start] = true;
    while (!q.empty())
    {
        int from = q.front(); q.pop();
        for (int i = head[from]; i != -1; i = edge[i].next)
            if (!vis[edge[i].to])
            {
                Edge &e = edge[i];
                printf("%d ", e.to);
                q.push(e.to); vis[e.to] = true;
            }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    init();
    while (m--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
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
1 3 7 6 2 5 8 4 
1 3 2 7 6 5 4 8 

*/

/*
以邻接链表存储的图的遍历(DFS+BFS)

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
    int to;
    Edge *next;
    Edge(): next(NULL) {}
    Edge(int to, Edge *next = NULL): to(to), next(next) {}
} edge[M];
Edge *head[N];
int n, m;

void init()
{
    memset(head, 0, sizeof(head));
}

void add(int u, int v)
{
    head[u] = new Edge(v, head[u]);
}

bool vis[N];
void dfs(int u)
{
    printf("%d ", u);
    vis[u] = true;
    for (Edge *p = head[u]; p != NULL; p = p->next)
        if (!vis[p->to])
        {
            dfs(p->to);
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
        for (Edge *p = head[from]; p != NULL; p = p->next)
        {
            int to = p->to;
            if (vis[to]) continue;
            printf("%d ", to);
            q.push(to); vis[to] = true;
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

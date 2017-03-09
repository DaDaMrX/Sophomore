/*
18.图的广度优先遍历
PS: 输入的图不一定为连通图
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
    int v, next;
} edge[M];
int adj[N], no;
int n;
char sign[N];

void init()
{
    memset(adj, -1, sizeof(adj));
    no = 0;    
}

void add(int u, int v)
{
    edge[no].v = v;
    edge[no].next = adj[u];
    adj[u] = no++;
}

void output()
{
    for (int u = 0; u < n; u++)
    {
        printf("%c", sign[u]);
        for (int i = adj[u]; i != -1; i = edge[i].next)
            printf(" %d", edge[i].v);
        printf("\n");
    }
}

bool vis[N];
queue<int> q;
void bfs(int start)
{
    while (!q.empty()) q.pop();
    printf("%c", sign[start]);
    q.push(start); vis[start] = true;
    while (!q.empty())
    {
        int from = q.front(); q.pop();
        for (int i = adj[from]; i != -1; i = edge[i].next)
            if (!vis[edge[i].v])
            {
                Edge &e = edge[i];
                printf("%c", sign[e.v]);
                q.push(e.v); vis[e.v] = true;
            }
    }
}

int main()
{
    n = 0;
    char c;
    while (scanf("%c%*c", &c), c != '*') sign[n++] = c;
    init();
    int u, v;
    while (scanf("%d,%d", &u, &v), ~u)
    {
        add(u, v);
        add(v, u);
    }

    printf("the ALGraph is\n");
    output();

    printf("the Breadth-First-Seacrh list:");
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
        if (!vis[i])
            bfs(i);
    printf("\n");
    return 0;
}

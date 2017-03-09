/*
Topological Sort (DFS)
O(n+m)
DFS逆序输出，故用栈存储
Description：
    对每一个节点u
        发现节点u，标记
        遍历与u相邻且没有访问过的节点
        离开节点u，压栈

*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;
const int M = 1e3 + 10;

struct Edge
{
    int v, next;
} edge[M];
int adj[N], no;
int n, m;

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

bool vis[N];
stack<int> s;
void dfs(int u)
{
    vis[u] = true;
    for (int i = adj[u]; i != -1; i = edge[i].next)
        if (!vis[edge[i].v])
        {
            dfs(edge[i].v);
        }
    s.push(u);
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
    }

    memset(vis, false, sizeof(vis));
    while (!s.empty()) s.pop();
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);

    while (s.size() > 1)
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("%d\n", s.top());
    return 0;
}

/*
INPUT
6 8
1 2
1 3
1 4
3 2
3 5
4 5
6 4
6 5

OUTPUT
6 1 3 2 4 5

*/

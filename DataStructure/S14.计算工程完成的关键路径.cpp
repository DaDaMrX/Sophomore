/*
S14.计算工程完成的关键路径
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int adj[N][N];
int n, m;

char name[N][10];
int indeg[N];
int ve[N], vl[N];
bool key[N][N];

void init()
{
    memset(adj, 0, sizeof(adj));
    memset(indeg, 0, sizeof(indeg));
}

void get_name()
{
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        char c;
        while ((c = getchar()) != ',' && c != '\n') name[i][j++] = c; 
        name[i][j] = '\0';
    }
    getchar();
}

int topo_order[N];
bool vis[N];
priority_queue<int, vector<int>, greater<int> > pq;
bool topo_sort()
{
    memset(vis, false, sizeof(vis));
    while (!pq.empty()) pq.pop();
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            pq.push(i);
    memset(ve, 0, sizeof(ve));

    while (!pq.empty())
    {
        int u = pq.top(); pq.pop();
        topo_order[cnt++] = u;
        for (int v = 0; v < n; v++)
            if (adj[u][v])
            {
                indeg[v]--;
                if (indeg[v] == 0) pq.push(v);
                ve[v] = max(ve[v], ve[u] + adj[u][v]);
            }
    }
    return cnt == n ? true : false;
}

void get_lv()
{
    memset(vl, 0x7f, sizeof(vl));
    vl[n - 1] = ve[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        int v = topo_order[i];
        for (int u = 0; u < n; u++)
            if (adj[u][v])
                vl[u] = min(vl[u], vl[v] - adj[u][v]);
    }
}

void get_key_edge()
{
    memset(key, false, sizeof(key));
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++)
            if (adj[u][v] && ve[u] == vl[v] - adj[u][v])
                key[u][v] = true;
}

int path[N];
void dfs(int u, int step)
{
    path[step] = u;
    if (u == topo_order[n - 1])
    {
        for (int i = 0; i < step; i++) printf("%s-", name[path[i]]);
        printf("%s\n", name[path[step]]);
        return;
    }
    for (int v = 0; v < n; v++)
        if (key[u][v])
            dfs(v, step + 1);
}

void get_key_path()
{
    get_lv();
    get_key_edge();
    dfs(topo_order[0], 0);
}

int main()
{
    scanf("%d,%d%*c", &n, &m);
    get_name();
    init();
    while (m--)
    {
        int u, v, w;
        scanf("<%d,%d,%d>%*c", &u, &v, &w);
        adj[u][v] = w;
        indeg[v]++;
    }

    if (!topo_sort())
    {
        printf("NOT OPOLOGICAL PATH\n");
        return 0;
    }
    printf("%s", name[topo_order[0]]); 
    for (int i = 1; i < n; i++) printf("-%s", name[topo_order[i]]);
    printf("\n");

    get_key_path();
    return 0;
}

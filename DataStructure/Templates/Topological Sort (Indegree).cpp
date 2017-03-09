/*
Topological Sort (Indegree)
Time complexity: O(n+m)
Description:
    每次从图中选择一个入度为0的点，将其输出
    从图中删除这个点以及所有从这个点出发的有向边
Optimize:
    用栈或队列存储入队为0的节点，从而实现O(1)获得下一个要输出的点
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

stack<int> s;
int indeg[N];
void topo_sort()
{
    while (!s.empty()) s.pop();
    memset(indeg, 0, sizeof(indeg));
    for (int u = 1; u <= n; u++)
    {
        for (int i = adj[u]; i != -1; i = edge[i].next)
        {
            indeg[edge[i].v]++;
        }
    }
    for (int u = 1; u <= n; u++)
        if (indeg[u] == 0) s.push(u);
    
    int cnt = 0;
    while (!s.empty())
    {
        int u = s.top(); s.pop();
        cnt++;
        printf("%d%c", u, cnt < n ? ' ' : '\n');
        for (int i = adj[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            indeg[v]--;
            if (indeg[v] == 0) s.push(v);
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
    }

    topo_sort();
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

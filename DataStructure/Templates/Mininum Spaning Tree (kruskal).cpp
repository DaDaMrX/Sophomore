/*
Mininum Spaning Tree (kruskal)
1. 时间复杂度O(mlogm)，主要用在排序上
2. 图以边集数组存储
3. 算法描述
        对边集数组按边权升序排序
        从小到大检查每一条边
            若这条边的两个端点不在同一棵树中，
            则将这条边加入生成树
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;
const int M = 1e3 + 10;

struct Edge
{
    int u, v, w;
} e[M];
int n, m;

int fa[N], deep[N];
void init()
{
    memset(fa, -1, sizeof(fa));
    memset(deep, 0, sizeof(deep));
}
int find(int x)
{
    if (fa[x] == -1) return x;
    return fa[x] = find(fa[x]);
}
void unite(int x, int y)
{
    x = find(x); y = find(y);
    if (x == y) return;
    if (deep[x] < deep[y]) fa[x] = y;
    else
    {
        fa[y] = x;
        if (deep[x] == deep[y]) deep[x]++;
    }
}
bool same(int x, int y)
{
    return find(x) == find(y);
}

bool cmp(Edge &e1, Edge &e2)
{
    return e1.w < e2.w;
}

int kruskal()
{
    sort(e, e + m, cmp);
    init();
    int cnt = 0, ans = 0;
    for (int i = 0; i < m && cnt < n - 1; i++)
    {
        if (same(e[i].u, e[i].v)) continue;
        ans += e[i].w;
        unite(e[i].u, e[i].v);
        cnt++;
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) 
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

    int ans = kruskal();

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

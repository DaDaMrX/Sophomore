#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1500 + 10;
const int M = 1500 + 10;

struct Edge
{
	int to, next;
} edge[2 * M];
int adj[N], no;

void init()
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}

void add(int u, int v)
{
	edge[no].to = v;
	edge[no].next = adj[u];
	adj[u] = no++;
}

int dfn[N], t, fa[N];
void dfs(int u, int f)
{
	dfn[t++] = u;
	fa[u] = f;
	for (int i = adj[u]; i != -1; i = edge[i].next)
	{
		Edge &e = edge[i];
		if (e.to == f) continue;
		dfs(e.to, u);
	}
}

bool s[N];

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		init();
		for (int i = 0; i < n; i++)
		{
			int u, sum;
			scanf("%d:(%d)", &u, &sum);
			for (int i = 1; i <= sum; i++)
			{
				int v;
				scanf("%d", &v);
				add(u, v); add(v, u);
			}
		}
		
		t = 0;
		dfs(0, -1);

		memset(s, false, sizeof(s));
		int ans = 0;
		for (int i = n - 1; i > 0; i--)
			if (!s[dfn[i]] && !s[fa[dfn[i]]])
				s[fa[dfn[i]]] = true, ans++;

		printf("%d\n", ans);
	}
	return 0;
}

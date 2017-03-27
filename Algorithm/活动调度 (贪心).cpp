#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;

pii a[2 * N];

bool cmp(pii p1, pii p2)
{
	if (p1.first != p2.first) return p1.first < p2.first;
	return p1.second > p2.second;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[2 * i - 1].first);
		a[2 * i - 1].second = 0;
		scanf("%d", &a[2 * i].first);
		a[2 * i].second = 1;
	}	
	sort(a + 1, a + 2 * n + 1, cmp);
	int num = 0, ans = 0;
	for (int i = 1; i <= 2 * n; i++)
	{
		if (a[i].second == 0) num++, ans = max(ans, num);
		else num--;
	}
	printf("%d\n", ans);
	return 0;
}

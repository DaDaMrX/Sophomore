#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int a[N];

int main()
{
	int n;
	while (~scanf("%d", &n), n)
	{
		int s = 0;
		for (int i = 1; i <= n; i++) scanf("%d", a + i), s ^= a[i];
		if (s == 0)
		{
			printf("0\n");
			continue;
		}
		int t = 1 << 30;
		while ((t & s) == 0) t >>= 1;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (t & a[i]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}

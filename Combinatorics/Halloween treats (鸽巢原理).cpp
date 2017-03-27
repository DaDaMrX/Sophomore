#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

ll s[N];
int f[N];

int main()
{
	int c, n;
	while (scanf("%d%d", &c, &n), c)
	{
		s[0] = 0;
		for (int i = 1; i <= n; i++) scanf("%lld", s + i), s[i] += s[i - 1];
		memset(f, -1, sizeof(f));
		f[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			int r = s[i] % c;
			if (f[r] != -1)
			{
				for (int j = f[r] + 1; j < i; j++) printf("%d ", j);
				printf("%d\n", i);
				break;
			}
			f[r] = i;
		}
	}
	return 0;
}

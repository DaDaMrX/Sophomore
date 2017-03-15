#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 15;

int a[N], b[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		ll k;
		scanf("%d%lld", &n, &k);
		k--;
		for (int i = 1; i <= n; i++)
		{
			b[n + 1 - i] = k % i;
			k /= i;
		}
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++)
		{
			int j = 0, s = 0;
			while (s <= b[i])
			{
				j++;
				if (a[j] == 0) s++;
			}
			a[j] = i;
		}
		for (int i = 1; i < n; i++) printf("%d ", a[i]);
		printf("%d\n", a[n]);
	}
	return 0;
}

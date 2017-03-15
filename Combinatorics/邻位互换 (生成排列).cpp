#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 15;

int a[N];

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
		memset(a, 0, sizeof(a));
		for (int i = n; i >= 1; i--)
		{
			// printf("i = %d\n", i);
			int r = k % i;
			k /= i;
			int j, d;
			if (k & 1) j = 1, d = 1;
			else j = n, d = -1;
			// printf("r = %d, k = %lld, j = %d\n", r, k, j);
			int s = -1;
			while (s < r)
			{
				if (a[j] == 0) s++;
				j += d;
			}
			j -= d;
			// printf("final j = %d\n", j);
			a[j] = i;
		}
		for (int i = 1; i < n; i++) printf("%d ", a[i]);
		printf("%d\n", a[n]);
	}
	return 0;
}

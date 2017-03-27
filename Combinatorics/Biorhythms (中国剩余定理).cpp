#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 5;

ll ext_gcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1; y = 0;
		return a;
	}
	ll d = ext_gcd(b, a % b, y, x);
	y -= (a / b) * x;
	return d;
}

ll inverse(ll a, ll mod)
{
    ll x, y;
    ext_gcd(a, mod, x, y);
    x = (x % mod + mod) % mod;
    return x;
}

int m[N], a[N], M[N], y[N];

int main()
{
	m[1] = 23; m[2] = 28; m[3] = 33;
	int n = 3;
	int s = 1;
	for (int i = 1; i <= n; i++) s *= m[i];
	int d, cas = 0;
	while (scanf("%d%d%d%d", a + 1, a + 2, a + 3, &d), ~d)
	{
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			a[i] %= m[i];
			M[i] = s / m[i];
			y[i] = inverse(M[i], m[i]);
			sum += a[i] * M[i] * y[i];
		}	
		sum %= s;
		int ans = ((sum - d) % s + s) % s;
		if (ans == 0) ans = s;
		printf("Case %d: the next triple peak occurs in %d days.\n", ++cas, ans);
	}
	return 0;
}

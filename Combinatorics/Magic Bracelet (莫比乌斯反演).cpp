#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 13;
const int mod = 9973;

struct Matrix
{
	ll a[N][N], n;
	Matrix() {}
	Matrix(int n, ll x = 0) : n(n)
	{
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) a[i][i] = x;
	}
	ll* operator[](int i)
	{
		return a[i];
	}
};

Matrix multi(Matrix &A, Matrix &B, int mod)
{
	int n = A.n;
	Matrix C(n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
	return C;
}

int n, m, k;
Matrix B;

int phi(int n)
{
	int ans = n;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
		{
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}

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

Matrix power(Matrix A, int n, int mod)
{
	Matrix C(A.n, 1);
	while (n)
	{
		if (n & 1) C = multi(C, A, mod);
		A = multi(A, A, mod);
		n >>= 1;
	}
	return C;
}

ll calc(ll d)
{
	Matrix A = power(B, d, mod);
	ll sum = 0;
	for (int i = 1; i <= m; i++) sum = (sum + A[i][i]) % mod;
	sum = sum * phi(n / d) % mod;
	return sum;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &k);
		B = Matrix(m);
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				B[i][j] = 1;
		while (k--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			B[u][v] = B[v][u] = 0;
		}
		int s = sqrt((double)n);
		int ans = 0;
		for (int d = 1; d <= s; d++)
			if (n % d == 0)
			{
				ans = (ans + calc(d)) % mod;
				if (d * d == n) break;
				ans = (ans + calc(n / d)) % mod;
			}
		ans = ans * inverse(n, mod) % mod;
		printf("%d\n", ans);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 13;

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

Matrix multi(Matrix &A, Matrix &B)
{
	int n = A.n;
	Matrix C(n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				C[i][j] += A[i][k] * B[k][j];
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

Matrix power(Matrix A, int n)
{
	Matrix C(A.n, 1);
	while (n)
	{
		if (n & 1) C = multi(C, A);
		A = multi(A, A);
		n >>= 1;
	}
	return C;
}

ll calc(ll d)
{
	Matrix A = power(B, d);
	ll sum = 0;
	for (int i = 1; i <= m; i++) sum += A[i][i];
	sum = sum * phi(n / d);
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
				ans +=calc(d);
				if (d * d == n) break;
				ans +=calc(n / d);
			}
		ans = ans / n;
		printf("%d\n", ans);
	}
	return 0;
}

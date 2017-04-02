#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 9973;
const int N = 5;

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

int main()
{
	int n;
	while (scanf("%d", &n), ~n)
	{
		if (n & 1)
		{
			printf("0\n");
			continue;
		}
		n >>= 1;
		if (n == 1 || n == 2)
		{
			printf("%d\n", n == 1 ? 3 : 11);
			continue;
		}
		Matrix A(2);
		A[1][1] = 4; A[1][2] = -1;
		A[2][1] = 1; A[2][2] = 0;
		A = power(A, n - 2, mod);
		int ans = ((A[1][1] * 11 + A[1][2] * 3) % mod + mod) % mod;
		printf("%d\n", ans);
	}
	return 0;
}

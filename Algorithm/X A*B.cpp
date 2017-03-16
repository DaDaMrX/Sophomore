#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

char x[N], y[N], z[N];

int equal(char a[], char b[])
{
	int la = strlen(a);
	int lb = strlen(b);
	int len = max(la, lb);
	while (la < len) a[la++] = '0';
	a[la] = '\0';
	while (lb < len) b[lb++] = '0';
	b[lb] = '\0';
	return len;
}

bool larger(char a[], int la, char b[], int lb)
{
	if (la > lb) return true;
	if (la < lb) return false;
	for (int i = la - 1; i >= 0; i--)
	{
		if (a[i] > b[i]) return true;
		if (a[i] < b[i]) return false;
	}
	return true;
}

char ta[N], tb[N];
int mminus(char a[], int la, char b[], int lb, char c[])
{
	memset(ta, 0, sizeof(ta));
	memset(tb, 0, sizeof(tb));
	// memset(c, 0, sizeof(c));
	int sign = larger(a, la, b, lb);
	int lta, ltb;
	if (sign)
	{
		int i = la - 1;
		while (a[i] == '0' && i > 0) i--;
	 	lta = i + 1;
		for (; i >= 0; i--) ta[i] = a[i] - '0';

		i = lb - 1;
		while (b[i] == '0' && i > 0) i--;
		ltb = i + 1;
		for (; i >= 0; i--) tb[i] = b[i] - '0';
	}
	else
	{
		int i = lb - 1;
		while (b[i] == '0' && i > 0) i--;
		lta = i + 1;
		for (; i >= 0; i--) ta[i] = b[i] - '0';

		i = la - 1;
		while (a[i] == '0' && i > 0) i--;
		ltb = i + 1;
		for (; i >= 0; i--) tb[i] = a[i] - '0';
	}

	int lc = max(lta, ltb);
	for (int i = 0; i < lc; i++)
	{
		if (ta[i] < tb[i]) ta[i + 1]--, ta[i] += 10;
		c[i] = ta[i] - tb[i];
	}
	int i = lc - 1;
	while (c[i] == 0 && i > 0) i--;
	for (; i >= 0; i--) c[i] += '0';
	return sign;
}

int add(char a[], char b[],char c[])
{
	int la = strlen(a);
	int lb = strlen(b);
	int len = equal(a, b);
	for (int i = 0; i < len; i++) a[i] -= '0', b[i] -= '0', c[i] = 0;
	c[len] = 0;
	for (int i = 0; i < len; i++)
	{
		c[i] += a[i] + b[i];
		c[i + 1] = c[i] / 10;
		c[i] %= 10;
	}
	for (int i = 0; i < la; i++) a[i] += '0';
	for (int i = 0; i < lb; i++) b[i] += '0';
	if (c[len]) c[++len] = '\0';
	for (int i = 0; i < len; i++) c[i] += '0';
	return len;
}

void left(char a[], int n)
{
	int len = strlen(a);
	for (int i = len + n; i >= n; i--) a[i] = a[i - n];
	for (int i = n - 1; i >= 0; i--) a[i] = '0';
}

int multi(char x[], char y[], int l, int r, char z[])
{
	if (l == r)
	{
		int s = (x[l] - '0') * (y[l] - '0');
		z[0] = s % 10 + '0';
		z[1] = s / 10;
		int lz = 1;
		if (z[lz]) z[lz] += '0', z[++lz] = '\0';
		return lz;
	}

	int m = l + r >> 1;
	char* ac = new char[N];
	char* bd = new char[N];
	int lac = multi(x, y, m + 1, r, ac);
	int lbd = multi(x, y, l, m, bd);

	char* a_b = new char[N];
	char* d_c = new char[N];
	int sign = mminus(x + m + 1, r - m, x + l, m + 1 - l, a_b);
	sign ^= mminus(y + l, m + 1 - l, y + m + 1, r - m, d_c);
	sign = !sign;
	int len = equal(a_b, d_c);
	char* e = new char[N];
	int le = multi(a_b, d_c, 0, len - 1, e);	

	char* f = new char[N];
	int lf = add(ac, bd, f);
	char *g = new char[N];
	int lg = sign ? add(e, f, g) : mminus(f, lf, e, le, g);

	if (!(g[1] == '\0' && g[0] == '0')) left(g, m + 1 - l);
	if (!(ac[1] == '\0' && ac[0] == '0')) left(ac, 2 * (m + 1 - l));
	char* h = new char[N];
	int lh = add(g, bd, h);
	int lz = add(ac, h, z);
	return lz;
}

int main()
{
	// freopen("in.txt", "r", stdin);
	scanf("%s%s", x, y);
	int lx = strlen(x);
	int ly = strlen(y);
	reverse(x, x + lx);
	reverse(y, y + ly);
	int len = equal(x, y);
	int lz = multi(x, y, 0, len - 1, z);
	reverse(z, z + lz);
	puts(z);
	return 0;
}

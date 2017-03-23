#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e6 + 10;

int a[N];

int Partition(int a[], int p, int r, int x)
{
	for (int i = p; i <= r; i++)
		if (a[i] == x)
		{
			swap(a[p], a[i]);
			break;
		}
	int i = p, j = r + 1;
	while (true)
	{
		while (a[++i] < x && i < r);
		while (a[--j] > x);
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}

int Select3rd(int a[], int p, int r)
{
	int t1 = p;
	for (int i = p + 1; i <= r; i++)
		if (a[i] < a[t1]) t1 = i;
	int t2 = t1 == p ? p + 1 : p;
	for (int i = p; i <= r; i++)
		if (i != t1 && a[i] < a[t2]) t2 = i;
	int t3 = -1;
	for (int i = p; i <= r; i++)
		if (i != t1 && i != t2 && (t3 == -1 || a[i] < a[t3])) t3 = i;
	return t3;
}

int Select(int a[], int p, int r, int k)
{
	if (r - p < 75)
	{
		sort(a + p, a + r + 1);
		return a[p + k - 1];
	}
	for (int i = 0; i <= (r - p - 4) / 5; i++)
	{
		int pos = Select3rd(a, p + 5 * i, p + 5 * i + 4);
		swap(a[p + i], a[pos]);
	}	
	int len = (r - p + 1) / 5;
	int x = Select(a, p, p + (r - p - 4) / 5, len / 2 + (len & 1));
	int i = Partition(a, p, r, x), j = i - p + 1;
	if (k <= j) return Select(a, p, i, k);
	else return Select(a, i + 1, r, k - j);
}

int main()
{
	int n = 1, x;
	while (scanf("%d,%d", &x, &a[n]) != EOF) n++;
	n--;
	int k = n / 2 + (n & 1);
	int ans = Select(a, 1, n, k);
	printf("%d\n", ans);
	return 0;
}

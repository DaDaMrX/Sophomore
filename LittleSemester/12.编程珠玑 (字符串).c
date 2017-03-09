/*
12.编程珠玑 (字符串)
*/
#include <stdio.h>
#include <string.h>
typedef long long ll;
const int INF = 0x7f7f7f7f;
#define N 710

int n;
char s[N];

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	scanf("%d%s", &n, s);

	int i = n - 1;
	while (i >= 0 && s[i] == 'w') i--;
	if (i < 0)
	{
		printf("%d\n", n);
		return 0;
	}
	char color = s[i];
	int j = 0, sum = n;
	while (j < i && (s[j] == color || s[j] == 'w')) s[sum++] = s[j++];
	if (j == i)
	{
		printf("%d\n", n);
		return 0;
	}
	n = sum;

	int right = 0;
	int last = 0, now = 0, ans = 0;
	while (s[right] == 'w') right++;
	while (right < n)
	{
		char color = s[right];
		int left = right - 1;
		while (left >= 0 && s[left] == 'w') left--;
		left++;

		int d = right - left;

		while (right < n && (s[right] == color || s[right] == 'w')) right++;

		now = right - left;
		ans = max(ans, last + now - d);
		last = now;
	}
	printf("%d\n", ans);
	return 0;
}
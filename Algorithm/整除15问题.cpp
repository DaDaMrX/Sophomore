#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

char s[N];
int cnt[10];

void print()
{
	int i;
	for (i = 9; i >= 0; i--) if (cnt[i]) break;
	if (i == 0) { printf("0\n"); return; }

	bool f = false;
	if (cnt[0] == 0) cnt[5]--, f = true;

	for (; i >= 0; i--) 
		while (cnt[i]--) printf("%d", i); 
	if (f) printf("5");
	printf("\n");
}

int main()
{
	while (~scanf("%s", s))
	{
		int len = strlen(s);
		memset(cnt, 0, sizeof(cnt));
		int sum = 0;
		for (int i = 0; i < len; i++) cnt[s[i] - '0']++, sum += s[i] - '0';
		if (cnt[0] == 0 && cnt[5] == 0) { printf("impossible\n"); continue; }

		if (sum % 3 == 0) { print(); continue; }

		int f = false;
		int t1[4] = { 0, 1, 4, 7 }, t2[4] = { 0, 2, 5, 8 };

		int *t = sum % 3 == 1 ? t1 : t2;
		for (int i = 1; i <= 3 && !f; i++)
			if (cnt[t[i]])
			{
				if (t[i] == 5 && cnt[0] == 0 && cnt[5] == 1) continue;
				cnt[t[i]]--;
				f = true;
				break;
			}
		if (f) { print(); continue; }

		t = sum % 3 == 1 ? t2 : t1;
		for (int i = 1; i <= 3 && !f; i++)
		{
			for (int j = 1; j < i && !f; j++)
				if (cnt[t[i]] && cnt[t[j]])
				{
					if ((t[i] == 5 || t[j] == 5) && cnt[0] == 0 && cnt[5] == 1) continue;
					cnt[t[i]]--; cnt[t[j]]--;
					f = true;
					break;
				}
			if (cnt[t[i]] >= 2)
			{
				if (t[i] == 5 && cnt[0] == 0 && cnt[5] == 2) continue;
				cnt[t[i]] -= 2;
				f = true;
				break;
			}
		}
		if (f) { print(); continue; }

		printf("impossible\n");
	}
	return 0;
}

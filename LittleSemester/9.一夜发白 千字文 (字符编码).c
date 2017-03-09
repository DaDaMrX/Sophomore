/*
9.Ò»Ò¹·¢°× Ç§×ÖÎÄ (×Ö·û±àÂë)
*/
#include <stdio.h>
#include <string.h>
#define N 70000

struct
{
	int cnt;
	unsigned char s[5];
} unicode[N];

int main()
{
	for (int i = 0; i < N; i++) unicode[i].cnt = 0;
	char c;
	while (~(c = getchar()))
	{
		if (((c & 0xf0) >> 4) < 8) continue;

		if (((c & 0xf0) >> 4) == 0xc || ((c & 0xf0) >> 4) == 0xd)
		{
			char c2 = getchar();
			int t = ((c & 0x1f) << 6) + (c2 & 0x3f);
			unicode[t].cnt++;
			unicode[t].s[0] = c;
			unicode[t].s[1] = c2;
			unicode[t].s[2] = '\0';
			continue;
		}

		if (((c & 0xf0) >> 4) == 0xe)
		{
			char c2 = getchar();
			char c3 = getchar();
			int t = ((c & 0xf) << 12) + ((c2 & 0x3f) << 6) + (c3 & 0x3f);
			unicode[t].cnt++;
			unicode[t].s[0] = c;
			unicode[t].s[1] = c2;
			unicode[t].s[2] = c3;
			unicode[t].s[3] = '\0';
			continue;
		}

		if (((c & 0xf0) >> 4) == 0xf)
		{
			char c2 = getchar();
			char c3 = getchar();
			char c4 = getchar();
			int t = ((c & 0x7) << 18) + ((c2 & 0x3f) << 12) + ((c3 & 0x3f) << 6) + (c4 & 0x3f);
			unicode[t].cnt++;
			unicode[t].s[0] = c;
			unicode[t].s[1] = c2;
			unicode[t].s[2] = c3;
			unicode[t].s[3] = c4;
			unicode[t].s[4] = '\0';
			continue;
		}
	}
	int flag = 0;
	for (int i = 100; i < N; i++)
		if (unicode[i].cnt > 1)
		{
			printf("%s 0x%04x %d\n", unicode[i].s, i, unicode[i].cnt);
			flag = 1;
		}
	if (!flag) printf("No repeat!\n");
	return 0;
}
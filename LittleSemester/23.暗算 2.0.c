/*
23. 暗算2.0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;
#define INF 0x7f7f7f7f
#define N 400

char s[N][N];
char key[N];
char change[N];

int check(char s[], char key[])
{
	int sign = 0;
	if (strlen(s) != strlen(key)) return 0;
	int len = strlen(key);
	for (int i = 0;i < len;i++)
	{
		if (s[i] == ' '&&key[i] == ' ') continue;
		if (s[i] != ' '&&key[i] != ' ')
		{
			if (change[s[i] - 'a'] == 0)
			{
				change[s[i] - 'a'] = key[i];
				sign = 1;
			}
			else if (change[s[i] - 'a'] != key[i])
			{
				return 0;
			}
		}
		else return 0;
	}
	return sign;
}

int main()
{
	int T;
	scanf("%d%*c", &T);
	gets(key);
	getchar();
	while (T--)
	{
		memset(change, 0, sizeof(change));
		int n = 0;
		while (gets(s[++n]) != EOF && s[n][0] != '\0');
		n--;

		int i;
		for (i = 1;i <= n;i++)
			if (check(s[i], key)) break;

		if (i > n)
		{
			printf("No solution.\n");
			continue;
		}

		for (int i = 1;i <= n;i++)
		{
			for (int j = 0;j < strlen(s[i]);j++)
			{
				if (s[i][j] == ' ') printf(" ");
				else printf("%c", change[s[i][j] - 'a']);
			}
			printf("\n");
		}

		if (T) printf("\n");
	}
	return 0;
}

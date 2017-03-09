/*
26.完美序列 (贪心)
题目对右括号有限制，而左括号没有限制，故可以先让左括号尽可能得多，右括号放在最后
即：若一个右括号可以放在某一个#的位置，则此#之后的#都可以放
*/
#include <stdio.h>
#include <string.h>
#define N 100010

char s[N];
int sta[N], top;

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	int left = 0;
	top = 0;

	int i;
	for (i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			left++;
			continue;
		}
		if (s[i] == ')')
		{
			left--;
			if (left < 0) break;
			continue;
		}
		if (s[i] == '#')
		{
			if (left == 0) break;
			sta[++top] = 1;
			left--;
		}
	}

	if (i < len)
	{
		printf("-1\n");
		return 0;
	}

	if (left)
	{
		int right = 0;
		for (i = len - 1; s[i] != '#'; i--)
		{
			if (s[i] == ')')
			{
				right++;
				continue;
			}
			if (s[i] == '(')
			{
				right--;
				if (right < 0) break;
				continue;
			}
		}

		if (s[i] != '#')
		{
			printf("-1\n");
			return 0;
		}

		sta[top] += left;
	}

	for (int i = 1; i <= top; i++) printf("%d\n", sta[i]);
	return 0;
}

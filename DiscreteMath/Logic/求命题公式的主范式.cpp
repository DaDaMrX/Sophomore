/*
实现功能：输入命题公式的合式公式，求出公式的真值表，并输出该公式的主合取范式和主析取范式。
输入：命题公式的合式公式
输出：公式的主析取范式和主析取范式，输出形式为：“ mi ∨ mj ; Mi ∧ Mj” ，极小项和 ∨ 符号之间有一个空格，极大项和 ∧ 符号之间有一个空格；主析取范式和主合取范式之间用“ ; ”隔开，“ ; ”前后各有一个空格。 永真式的主合取范式为 1 ，永假式的主析取范式为 0 。
输入公式的符号说明：
! 非，相当于书面符号中的 “ ¬ ”
& 与，相当于书面符号中的 “ ∧ ”
| 或，相当于书面符号中的 “ ∨ ”
- 蕴含联结词，相当于书面符号中的 “ → ”
+ 等价联结词，相当于书面符号中的 “ ↔ ”
( 前括号
) 后括号
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#define N 1000
#define MAX 10000000
char s[N];
bool table[30];
int explain[30];
int value[MAX];
int sum = 0;
int priority(char c)
{
	switch (c)
	{
		case '#': return -1;
		case '!': return 5;
		case '&': return 4;
		case '|': return 3;
		case '-': return 2;
		case '+': return 1;
		case '(': return 0;
		default: return 0;
	}
}
void postfix()
{
	char post[N] = { '\0' };
	int pp = -1;
	char stack[N] = { '#' };
	int ps = 0;

	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			post[++pp] = s[i];
			continue;
		}
		if (s[i] == '!' || s[i] == '&' || s[i] == '|' || s[i] == '-' || s[i] == '+')
		{
			while (priority(s[i]) <= priority(stack[ps]))
				post[++pp] = stack[ps--];
			stack[++ps] = s[i];
			continue;
		}
		if (s[i] == '(')
		{
			stack[++ps] = s[i];
			continue;
		}
		if (s[i] == ')')
		{
			while (stack[ps] != '(') post[++pp] = stack[ps--];
			ps--;
			continue;
		}
	}
	while (ps) post[++pp] = stack[ps--];
	strcpy(s, post);
	int l = strlen(s);
}
void settable()
{
	memset(table, 0, sizeof(table));
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= 'a' && s[i] < 'z')
			table[s[i] - 'a'] = true;
	}
	for (int i = 0; i < 26; i++)
		if (table[i]) sum++;
	sum = pow(2, sum);
}
int btoi()
{
	int sum = 0, weight = 1;
	for (int i = 25; i >= 0; i--)
		if (table[i])
		{
			if (explain[i]) sum += weight;
			weight *= 2;
		}
	return sum;
}
int calc(int a, int b, char c)
{
	switch (c)
	{
		case '&': return a * b;
		case '|': if (a + b) return 1; else return 0;
		case '-': if (a == 1 && b == 0) return 0; else return 1;
		case '+': return !((a + b) & 1);
	}
}
int work()
{
	int stack[N], ps = -1;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			stack[++ps] = explain[s[i] - 'a'];
			continue;
		}
		if (s[i] == '!')
		{
			stack[ps] = (stack[ps] + 1) & 1;
			continue;
		}
		int ans = calc(stack[ps - 1], stack[ps], s[i]);
		stack[--ps] = ans;
	}
	return stack[0];
}
void assign()
{
	int x = btoi();
	int ans = work();
	value[x] = ans;
}
void generate(char c)
{
	while (c <= 'z' && table[c - 'a'] == false) c++;
	if (c > 'z')
	{
		assign();
		return;
	}
	explain[c - 'a'] = 0;
	generate(c + 1);
	explain[c - 'a'] = 1;
	generate(c + 1);
}
void output1()
{
	int i = 0;
	while (i < sum && !value[i]) i++;
	if (i >= sum)
	{
		printf("0 ; ");
		return;
	}
	printf("m%d", i);
	for (i++; i < sum; i++)
		if (value[i]) printf(" ∨ m%d", i);
	printf(" ; ");
}
void output2()
{
	int i = 0;
	while (i < sum && value[i]) i++;
	if (i >= sum)
	{
		printf("1\n");
		return;
	}
	printf("M%d", i);
	for (i++; i < sum; i++)
		if (!value[i]) printf(" ∧ M%d", i);
	printf("\n");
}
int main()
{
	scanf("%s", s);
	postfix();
	settable();
	memset(value, 0, sizeof(value));
	memset(explain, 0, sizeof(explain));
	generate('a');
	output1();
	output2();
	return 0;
}
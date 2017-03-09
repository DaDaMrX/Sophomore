#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

bool check(char s[])
{
	int len = strlen(s);
	stack<char> sta;
	map<char, char> match;
	match[')'] = '(';
	match[']'] = '[';
	match['}'] = '{';

	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			sta.push(s[i]);
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (sta.empty() || sta.top() != match[s[i]]) return false;
			else sta.pop();
		}
	}
	return true;
}

int main()
{
	char s[N];
	scanf("%s", s);
	if (check(s)) printf("Match succeed!\n");
	else printf("Match false!\n");
	return 0;
}

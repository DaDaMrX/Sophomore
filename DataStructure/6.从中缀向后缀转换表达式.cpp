#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

template<class T>
class Stack
{
private:
	T *base, *t;
	int len;

public:
	Stack() : len(10000)
	{
		t = base = (T *)malloc(sizeof(T) * len);
	}

	void push(T x)
	{
		if (t - base + 1 == len)
		{
			len *= 2;
			base = (T *)realloc(base, sizeof(T) * len);
			t = base + len / 2 - 1;
		}
		*++t = x;
	}

	void pop()
	{
		t--;
	}

	int top()
	{
		return *t;
	}

	int size()
	{
		return t - base;
	}

	bool empty()
	{
		return t == base;
	}
};

int precedence(char c)
{
	switch (c)
	{
	case '^': return 3;
	case '*':
	case '/': return 2;
	case '+':
	case '-': return 1;
	case '(': return 0;
	default: return -1;
	}
}

int associativity(char c)
{
	switch (c)
	{
	case '^': return 1;
	case '*':
	case '/':
	case '%':
	case '+':
	case '-': return 0;
	default: return -1;
	}
}

void back_to(char end, string& str, Stack<char>& op)
{
	while (op.top() != end) str += op.top(), op.pop();
	op.pop();
}

void process(char o, string& str, Stack<char>& op)
{
	while (precedence(op.top()) > precedence(o)) str += op.top(), op.pop();
	if (!associativity(o))
		while (precedence(op.top()) == precedence(o)) str += op.top(), op.pop();
}

string calculate(char s[])
{
	string ans = "";
	Stack<char> op; op.push('#');
	int len = strlen(s);
	int i = 0;
	while (i < len)
	{
		if (isalpha(s[i]))
		{
			ans += s[i];
			i++;
		}
		else if (s[i] == '(')
		{
			op.push(s[i]);
			i++;
		}
		else if (s[i] == ')')
		{
			back_to('(', ans, op);
			i++;
		}
		else
		{
			process(s[i], ans, op);
			op.push(s[i]);
			i++;
		}
	}
	back_to('#', ans, op);
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s[N];
		scanf("%s", s);
		cout << calculate(s) << endl;
	}
	return 0;
}

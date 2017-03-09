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

class Error
{
private:
	string str;
public:
	Error(string str) : str(str) {};
	string getinfo()
	{
		return str;
	}
};

int precedence(char c)
{
	switch (c)
	{
	case '^': return 3;
	case '*':
	case '/':
	case '%': return 2;
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

int calc(int a, char c, int b)
{
	switch (c)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': 
		if (b == 0) throw Error("Divide 0.");
		return a / b;
	case '%': 
		if (b == 0) throw Error("Divide 0.");
		return a % b;
	case '^': 
		if (b < 0) throw Error("error.");
		return pow(a, b);
	}
}

int get_number(char s[], int& i)
{
	int ans = 0;
	while (isdigit(s[i])) ans = ans * 10 + s[i++] - '0';
	return ans;
}

void back(Stack<int>& num, Stack<char>& op)
{
	int b = num.top(); num.pop();
	int a = num.top(); num.pop();
	char o = op.top(); op.pop();
	num.push(calc(a, o, b));
}

void back_to(char end, Stack<int>& num, Stack<char>& op, char errorc)
{
	while (op.top() != end)
	{
		if (op.top() == errorc) throw Error("error.");
		back(num, op);
	}
}

void process(char o, Stack<int>& num, Stack<char>& op)
{
	while (precedence(op.top()) > precedence(o)) back(num, op);
	if (!associativity(o))
		while (precedence(op.top()) == precedence(o)) back(num, op);
}

int calculate(char s[])
{
	Stack<int> num;
	Stack<char> op; op.push('#');
	int len = strlen(s);
	if (!isdigit(s[len - 1]) && s[len - 1] != ')') throw Error("error.");
	int sign = 1;
	int i = 0;
	while (i < len)
	{
		if (isdigit(s[i]))
		{
			if (i > 0 && s[i - 1] == ')') throw Error("error.");
			num.push(sign * get_number(s, i));
			sign = 1;
		}
		else if (s[i] == '(')
		{
			if (i > 0 && isdigit(s[i - 1])) throw Error("error.");
			if (i > 0 && s[i - 1] == ')') throw Error("error.");
			op.push(s[i]);
			i++;
		}
		else if (s[i] == ')')
		{
			if (i == 0 || !isdigit(s[i - 1]) && s[i - 1] != ')') throw Error("error.");
			back_to('(', num, op, '#');
			op.pop();
			i++;
		}
		else if (s[i] == '-' && (i == 0 || !isdigit(s[i - 1]) && s[i - 1] != ')'))
		{
			sign = -1;
			i++;
		}
		else
		{
			if (i == 0 || s[i - 1] == '(') throw Error("error.");
			process(s[i], num, op);
			op.push(s[i]);
			i++;
		}
	}
	back_to('#', num, op, '(');
	return num.top();
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s[N];
		scanf("%s", s);
		try
		{
			printf("%d\n", calculate(s));
		}
		catch (Error error)
		{
			cout << error.getinfo() << endl;
		}
	}
	return 0;
}

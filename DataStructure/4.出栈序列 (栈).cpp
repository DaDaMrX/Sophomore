#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

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

int main()
{
	int n, m, cas = 0;
	while (scanf("%d%d", &n, &m), n)
	{
		cas++;
		if (cas > 1) printf("\n");
		while (m--)
		{
			Stack<int> s;
			int i = 1;
			bool flag = true;
			for (int j = 1; j <= n; j++)
			{
				int x;
				scanf("%d", &x);
				if (!flag) continue;
				for (; i <= x; i++) s.push(i);
				if (s.top() != x)
				{
					flag = false;
					continue;
				}
				s.pop();
			}
			if (flag) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}

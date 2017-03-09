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

	void push(const T& x)
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
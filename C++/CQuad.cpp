#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

class CQuad
{
private:
	double a, b, c;
	double x1, x2;
	bool solved;
	int time, num;
public:
	CQuad(double a, double b, double c);
	CQuad(const CQuad& e);
	void solve();
	CQuad& Merge(CQuad e);
	void print();
	~CQuad();
};

CQuad::CQuad(double a = 0.0, double b = 0.0, double c = 0.0) :
   	a(a), b(b), c(c), solved(false)
{
	cout << "Constructed!" << endl;
}

CQuad::CQuad(const CQuad& e)
{
	a = e.a; b = e.b; c = e.c;
	x1 = e.x1; x2 = e.x2;
	solved = e.solved;
	time = e.time; num = e.num;
	cout << "Copyed!" << endl;
}

void CQuad::solve()
{
	if (solved) return;
	if (a == 0) 
	{
		if (b == 0)
		{
			time = 0;
			if (c = 0) num = -1;
			else num = 0;
		}
		else
		{
			time = 1;
			num = 1;
			x1 = -c / b;
		}
	}
	else
	{
		time = 2;
		double delta = b * b - 4 * a * c;
		if (delta < 0) 
		{
			num = 0;
		}
		else if (delta == 0) 
		{
			num = 1;
			x1 = x2 = -b / 2 / a;
		}
		else 
		{
			num = 2;
			double q = sqrt(delta);
			x1 = (-b + q) / 2 / a;
			x2 = (-b - q) / 2 / a;
		}
	}
	solved = true;
}

CQuad& CQuad::Merge(CQuad e)
{
	a += e.a;
	b += e.b;
	c += e.c;
	solved = false;
	return *this;
}

void CQuad::print()
{
	if (!solved) solve();
	if (time == 0)
	{
		if (num = 0) cout << "Infinite Solution!" << endl;
		else cout << "No Solution!" << endl;
	}
	else if (time == 1)
	{
		cout << "x = " << x1 << endl;
	}
	else
	{
		if (num == 0) cout << "No Real Root!" << endl;
		else if (num == 1) cout << "x1 = x2 = " << x1 << endl;
		else cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
	}
}

CQuad::~CQuad()
{
	cout << "Distructed!" << endl;
}

int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	CQuad e1(a, b, c);
	cin >> a >> b >> c;
	CQuad e2(a, b, c);
	e1.Merge(e2).print();
	while (cin >> a >> b >> c)
	{
		CQuad eq(a, b, c);
		eq.print();
	}
	return 0;
}

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

class CAngle
{
private:
	double m_dAlpha;
public:
	void initilize(double a)
	{
		m_dAlpha = a;
	}
	double Sin()
	{
		return sin(m_dAlpha);
	}
	double Cos()
	{
		return cos(m_dAlpha);
	}
};

int main()
{
	CAngle a;
	a.initilize(3.14 / 6);
	cout << a.Sin() << endl;
	cout << a.Cos() << endl;
	return 0;
}

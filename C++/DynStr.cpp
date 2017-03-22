#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

class DynStr
{
private:
	vector<char> m_varray;

public:
	DynStr& Append(char c);
	DynStr& Append(const char *pStr);
	int ElementNum();
	void print();
};

DynStr& DynStr::Append(char c)
{
	m_varray.push_back(c);
	return *this;
}

DynStr& DynStr::Append(const char *pStr)
{
	while (*pStr) m_varray.push_back(*pStr++);
	return *this;
}

int DynStr::ElementNum()
{
	return m_varray.size();
}

void DynStr::print()
{
	for (int i = 0; i < m_varray.size(); i++) 
		printf("%c", m_varray[i]);
	printf("\n");
}

int main()
{
	DynStr ds;
	ds.Append('a');
	ds.Append("12345");
	cout << ds.ElementNum() << endl;
	ds.print();
	return 0;
}

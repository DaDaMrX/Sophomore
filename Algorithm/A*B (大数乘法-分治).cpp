#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e4 + 20;

inline void simplify(string &S)
{
	while (S.length() > 1 && S[0] == '0') S.erase(0, 1);
}

inline int equal(string &A, string &B)
{
	simplify(A); simplify(B);
	int la = A.length(), lb = B.length();
	int len = max(la, lb);
	int t = abs(la - lb);
	if (la < len) A = string(t, '0') + A;
	if (lb < len) B = string(t, '0') + B;
	return len;
}

bool large(string A, string B)
{
	simplify(A); simplify(B);
	if (A.length() > B.length()) return true;
	if (A.length() < B.length()) return false;
	for (int i = 0; i < A.length(); i++)
	{
		if (A[i] > B[i]) return true;
		if (A[i] < B[i]) return false;
	}
	return true;
}

string mins(string A, string B)
{
	int len = equal(A, B);
	string C = string(len, '0');
	for (int i = len - 1; i >= 0; i--)
	{
		if (A[i] < B[i]) A[i - 1]--, A[i] += 10;
		C[i] = A[i] - B[i] + '0';
	}
	while (C.length() > 1 && C[0] == '0') C.erase(0, 1);
	return C;
}

void add(string &S, string A)
{
	int len = equal(S, A);
	int c = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		int s = S[i] - '0' + A[i] - '0' + c;
		if (s > 9) c = 1, s -= 10;
		else c = 0;
		S[i] = s + '0';
	}
	if (c) S = '1' + S;
}

string itos(ll x)
{
	if (x == 0) return string(1, '0');
	string str = "";
	while (x)
	{
		str += x % 10 + '0';
		x /= 10;
	}
	reverse(str.begin(), str.end());
	return str;
}

ll stoi(string &str)
{
	ll x = 0;
	for (int i = 0; i < str.length(); i++) x = 10 * x + str[i] - '0';
	return x;
}

string operator*(string X, string Y)
{
	int len = X.length();
	int mid = len / 2;

	if (len <= 5) return itos(stoi(X) * stoi(Y));

	string A = X.substr(0, mid);
	string B = X.substr(mid, len);
	string C = Y.substr(0, mid);
	string D = Y.substr(mid, len);
	string AC = A * C;
	string BD = B * D;

	bool sA_B = large(A, B);
	string A_B = sA_B ? mins(A, B) : mins(B, A);
	bool sD_C = large(D, C);
	string D_C = sD_C ? mins(D, C) : mins(C, D);
	bool sign = !(sA_B ^ sD_C);
	equal(A_B, D_C);
	string S = A_B * D_C;

	string ans = AC;
	add(ans, BD);
	if (sign) add(ans, S);
	else ans = mins(ans, S);

	int m = len - mid;
	ans = ans + string(m, '0');
	AC = AC + string(2 * m, '0');
	add(ans, BD);
	add(ans, AC);

	return ans;
}

int main()
{
	string X, Y;
	cin >> X >> Y;
	equal(X, Y);
	cout << X * Y << endl;
	return 0;
}

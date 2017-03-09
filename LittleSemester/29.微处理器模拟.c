/*
29.Î¢´¦ÀíÆ÷Ä£Äâ
*/
#include <stdio.h>
#include <string.h>
typedef long long ll;
#define INF 0x7f7f7f7f
#define N 260

char m[N];
int a, b;
int i;

int HtoD(char H)
{
	if (H <= '9') return H - '0';
	return H - 'A' + 10;
}

char DtoHB(int D)
{
	return D / 16 + '0';
}

char DtoHA(int D)
{
	D %= 16;
	if (D <= 9) return D + '0';
	return D - 10 + 'A';
}

char DtoH(int D)
{
	if (D <= 9) return D + '0';
	return D - 10 + 'A';
}

int get_address(int i)
{
	int address = HtoD(m[i]) * 16 + HtoD(m[i + 1]);
	return address;
}

void LD()
{
	i++;
	int address = get_address(i);
	i++;
	a = HtoD(m[address]);
}

void ST()
{
	i++;
	int address = get_address(i);
	i++;
	m[address] = DtoH(a);
}

void SWP()
{
	int t = a; a = b; b = t;
}

void ADD()
{
	int sum = a + b;
	b = sum / 16;
	a = sum % 16;
}

void INC()
{
	a = (a + 1) % 16;
}

void DEC()
{
	if (a > 0) a--;
	else a = 15;
}

void BR()
{
	i++;
	i = get_address(i++) - 1;
}

void BZ()
{
	if (a == 0) BR();
	else i += 2;
}

int main()
{
	while (gets(m), m[0] != '8')
	{
		i = 0;
		while (m[i] != '8')
		{
			switch (m[i])
			{
			case '0': LD(); break;
			case '1': ST(); break;
			case '2': SWP(); break;
			case '3': ADD(); break;
			case '4': INC(); break;
			case '5': DEC(); break;
			case '6': BZ(); break;
			case '7': BR(); break;
			}
			i++;
		}
		puts(m);
	}
	return 0;
}

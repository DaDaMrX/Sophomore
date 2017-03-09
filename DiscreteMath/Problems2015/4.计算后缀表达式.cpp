/************************************************************
4.计算后缀表达式
************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int calc(int a, char o, int b)
{
    if ((o == '/' || o == '%') && b == 0)
    {
        printf("DIV0!\n");
        exit(0);
    }
    switch (o)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
    }
}

stack<int> s;
int calculate(char str[])
{
    int len = strlen(str);
    while (!s.empty()) s.pop();
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            s.push(str[i] - '0');
        }
        else
        {
            if (s.size() < 2)
            {
                printf("ERROR!\n");
                exit(0);
            }
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(calc(a, str[i], b));
        }
    }
    if (s.size() > 1)
    {
        printf("ERROR!\n");
        exit(0);
    }
    return s.top();
}

char str[N];
int main()
{
    scanf("%s", str);
    printf("%d\n", calculate(str));
    return 0;
}

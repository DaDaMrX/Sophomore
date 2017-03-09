#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;
const int M = 5e3 + 10;

struct Node
{
    int i, j, v;
} a[M], b[M];

int n, m, k;
int num[N], cpot[N];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    memset(num, 0, sizeof(num));
    memset(cpot, 0, sizeof(cpot));
    for (int i = 1; i <= k; i++) 
    {
        scanf("%d%d%d", &a[i].i, &a[i].j, &a[i].v);
        num[a[i].j]++;
    }
    cpot[1] = 1;
    for (int j = 2; j <= m; j++) cpot[j] = cpot[j - 1] + num[j - 1];

    printf("num:");
    for (int j = 1; j <= m; j++) printf("%d,", num[j]);
    printf("\n");
    printf("cpot:");
    for (int j = 1; j <= m; j++) printf("%d,", cpot[j]);
    printf("\n");

    for (int i = 1; i <= k; i++)
    {
        int pos = cpot[a[i].j]++;
        b[pos].i = a[i].j; b[pos].j = a[i].i; b[pos].v = a[i].v;
    }

    for (int i = 1; i <= k; i++)
        printf("%d,%d,%d\n", b[i].i, b[i].j, b[i].v);
    return 0;
}

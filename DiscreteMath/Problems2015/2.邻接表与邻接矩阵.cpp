/********************************************************************************
2.邻接表与邻接矩阵

邻接表转邻接矩阵并不难，本题关键在于如何把节点的字符编号转化位数字。
字符的范围是除空格外所有的ASCII可见字符，不一定按顺序给出。
标记把出现的所有字符，按其ASCII编码顺序编号。
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 300;

char list[N][N];
int adj[N][N];
bool flag[N];
int id[N];

int main()
{
    int line = 0;
    while (fgets(list[line++], N, stdin));
    memset(flag, false, sizeof(flag));
    for (int i = 0; i < line; i++)
    {
        int len = strlen(list[i]) - 1;
        for (int j = 0; j < len; j += 2) flag[(int)list[i][j]] = true;
    }
    flag[0] = false;
    memset(id, -1, sizeof(id));
    int s = 0;
    for (int i = 0; i < N; i++)
        if (flag[i]) id[i] = s++;
    
    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < line; i++)
    {
        int len = strlen(list[i]) - 1;
        for (int j = 2; j < len; j += 2) adj[id[(int)list[i][0]]][id[(int)list[i][j]]]++;
    }
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j <= s - 2; j++) printf("%d ", adj[i][j]);
        printf("%d\n", adj[i][s - 1]);
    }
    return 0;
}

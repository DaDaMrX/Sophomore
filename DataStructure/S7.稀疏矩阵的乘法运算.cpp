/*
S7.稀疏矩阵的乘法运算
使用三元组Triple进行矩阵压缩
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e2 + 10;

struct Triple
{
    int i, j, v;
    Triple() {};
    Triple(int i, int j, int v): i(i), j(j), v(v) {}
};

class Matrix
{
private:
    int row, col, sum;
    Triple data[N];
    int rnum[N], rpos[N];

    friend Matrix operator*(const Matrix& A, const Matrix& B);

public:
    Matrix() {}
    Matrix(int row, int col, int sum): row(row), col(col), sum(sum)
    {
        memset(rnum, 0, sizeof(rnum));
        for (int i = 1; i <= sum; i++)
        {
            scanf("%d%d%d", &data[i].i, &data[i].j, &data[i].v);
            rnum[data[i].i]++;
        }
        rpos[1] = 1;
        for (int i = 2; i <= row; i++) rpos[i] = rpos[i - 1] + rnum[i - 1];
        rpos[row + 1] = sum + 1;
    }

    void print()
    {
        printf("%d\n%d\n%d\n", row, col, sum);
        for (int i = 1; i <= sum; i++)
            printf("%d,%d,%d\n", data[i].i, data[i].j, data[i].v);
    }
};

Matrix operator*(const Matrix& A, const Matrix& B)
{
    Matrix C(A.row, B.col, 0);
    for (int Arow = 1; Arow <= A.row; Arow++)
    {
        int tmp[N];
        memset(tmp, 0, sizeof(tmp));
        C.rpos[Arow] = C.sum + 1;
        for (int i = A.rpos[Arow]; i < A.rpos[Arow + 1]; i++)
        {
            int Brow = A.data[i].j;
            for (int j = B.rpos[Brow]; j < B.rpos[Brow + 1]; j++)
            {
                tmp[B.data[j].j] += A.data[i].v * B.data[j].v;
            }
        }
        for (int Bcol = 1; Bcol <= B.col; Bcol++)
            if (tmp[Bcol])
            {
                C.data[++C.sum] = Triple(Arow, Bcol, tmp[Bcol]);
            }
    }
    return C;
}

int main()
{
    int m, n, s;
    scanf("%d%d%d", &m, &n, &s);
    Matrix A(m, n, s);
    scanf("%d%d%d", &m, &n, &s);
    Matrix B(m, n, s);

    Matrix C = A * B;
    
    C.print();
    return 0;
}

/*
INPUT
3
4
4
1 1 3
1 4 5
2 2 -1
3 1 2
4
2
4
1 2 2
2 1 1
3 1 -2
3 2 4

OUTPUT
3
2
3
1,2,6
2,1,-1
3,2,4

*/

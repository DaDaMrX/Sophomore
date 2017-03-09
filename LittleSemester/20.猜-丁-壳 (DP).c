/*
20.²Â-¶¡-¿Ç (DP)
*/
#include <stdio.h>
const double eps = 1e-10;
#define N 110

double dp[N][N][N][3];

void init(int r, int s, int p)
{
	for (int i = 0; i <= r; i++)
		for (int j = 0; j <= s; j++)
			for (int k = 0; k <= p; k++)
				for (int l = 0; l <= 2; l++)
					dp[i][j][k][l] = -1.0;
}

void get(int i, int j, int k)
{
	if (dp[i][j][k][0] > -eps) return;
	if (i == 0)
	{
		dp[i][j][k][0] = 0.0;
		dp[i][j][k][1] = 1.0;
		dp[i][j][k][2] = 0.0;
		return;
	}
	if (j == 0)
	{
		dp[i][j][k][0] = 0.0;
		dp[i][j][k][1] = 0.0;
		dp[i][j][k][2] = 1.0;
		return;
	}
	if (k == 0)
	{
		dp[i][j][k][0] = 1.0;
		dp[i][j][k][1] = 0.0;
		dp[i][j][k][2] = 0.0;
		return;
	}

	double sum = i * j + j * k + k * i;
	double s1 = i * j / sum;
	double s2 = j * k / sum;
	double s3 = k * i / sum;

	get(i, j - 1, k);
	get(i - 1, j, k);
	get(i, j, k - 1);

	for (int l = 0; l <= 2; l++)
	{
		dp[i][j][k][l] = s1 * dp[i][j - 1][k][l];
		dp[i][j][k][l] += s2 * dp[i][j][k - 1][l];
		dp[i][j][k][l] += s3 * dp[i - 1][j][k][l];
	}
}

int main()
{
	int r, s, p;
	scanf("%d%d%d", &r, &s, &p);

	init(r, s, p);
	get(r, s, p);

	printf("%.6f %.6f %.6f\n", dp[r][s][p][0], dp[r][s][p][1], dp[r][s][p][2]);
	return 0;
}
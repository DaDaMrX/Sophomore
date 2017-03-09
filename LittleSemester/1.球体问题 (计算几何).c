/*
1.球体问题 (计算几何)
题意：计算两个球缺的组合体的体积和表面积
球缺表面积公式 S = 2*PI*R*h + PI * r * r
球缺体积公式 V = PI*h*h*(R - h/3) 或 PI*h*(3*r*r + h*h)/6
列方程组解出d1，d2，r
d1+d2=d
d1*d1 + r*r = R1*R1
d2*d2 + r*r = R2*R2
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;
const double PI = 3.1415926535;
double volume(double R, double h)
{
	return PI * h * h * (R - h / 3);
}
double area(double R, double h, double r)
{
	return 2 * PI * R * h;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		double R1, R2, d, w, s;
		scanf("%lf%lf%lf%lf%lf", &R1, &R2, &d, &w, &s);
		double d1 = (d + (R1 * R1 - R2 * R2) / d) / 2;
		double d2 = (d - (R1 * R1 - R2 * R2) / d) / 2;
		double r = sqrt(R1 * R1 - d1 * d1);
		double h1 = R1 + d1, h2 = R2 + d2;
		double V = volume(R1, h1) + volume(R2, h2);
		double S = area(R1, h1, r) + area(R2, h2, r);
		printf("%.4lf %.4lf\n", V, S);
		if (w / V > s) printf("The Paired-Sphere Sinks.\n");
		else printf("The Paired-Sphere Floats.\n");
	}
	return 0;
}
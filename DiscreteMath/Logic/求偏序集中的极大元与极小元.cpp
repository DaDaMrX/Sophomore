/*
输入
输入偏序集<A, £>，A中的元素数不超过20个，分别用单个小写的英文字母表示。
输入的第一行给出A中的各个元素，两个相邻的元素之间用逗号隔开。
输入的第二行给出偏序关系£，用有序对的形式给出，如<a,b>,<c,a>等等，两个相邻的有序对之间用逗号隔开。
输出
输出A的极小元与极大元。
输出的第一行给出各个极小元，两个相邻元素之间用逗号隔开，输出的元素要求按照英文字母的自然顺序排列输出。
输出的第二行给出各个极大元，两个相邻元素之间用逗号隔开，输出的元素要求按照英文字母的自然顺序排列输出。
*/

#include <cstdio>
#include <cstring>
#define N 30
bool dic[N], min[N], max[N];
int main()
{
	memset(dic, false, sizeof(dic));
	memset(min, true, sizeof(min));
	memset(max, true, sizeof(max));
	char c;
	while ((c = getchar()) != '\n')
	{
		if (c >= 'a' && c <= 'z') dic[c - 'a'] = true;
	}
	c = getchar();
	while (c != '\n')
	{
		while (c < 'a' || c > 'z') c = getchar();
		max[c - 'a'] = false;
		c = getchar();
		while (c < 'a' || c > 'z') c = getchar();
		min[c - 'a'] = false;
		c = getchar();
		while (c != '\n' && (c < 'a' || c > 'z')) c = getchar();
	}
	int i = 0;
	while (!dic[i] || !min[i]) i++;
	printf("%c", i + 'a');
	for (i++; i < 26; i++)
		if (dic[i] && min[i]) printf(",%c", i + 'a');
	printf("\n");
	i = 0;
	while (!dic[i] || !max[i]) i++;
	printf("%c", i + 'a');
	for (i++; i < 26; i++)
		if (dic[i] && max[i]) printf(",%c", i + 'a');
	printf("\n");
	return 0;
}
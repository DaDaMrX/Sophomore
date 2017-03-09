/*
14.比赛计分问题 (排序)
*/
#include <stdio.h>
#include <string.h>
typedef long long ll;
#define N 110

struct Team
{
	int id, solved, penalty;
	int rank;
	int wrong[1010];
	int ac[1010];
} team[N];

int cmp(const void* t1, const void* t2)
{
	struct Team* p1 = (struct Team*)t1;
	struct Team* p2 = (struct Team*)t2;
	if (p1->solved != p2->solved) return p2->solved - p1->solved;
	if (p1->penalty != p2->penalty) return p1->penalty - p2->penalty;
	return p1->id - p2->id;
}

int main()
{
	int cas = 0, n;
	while (scanf("%d", &n), n)
	{
		for (int i = 1; i <= n; i++)
		{
			team[i].id = i;
			team[i].solved = team[i].penalty = 0;
			memset(team[i].wrong, 0, sizeof(team[i].wrong));
			memset(team[i].ac, 0, sizeof(team[i].ac));
		}

		int time, id, problem;
		char result[5];
		while (scanf("%d", &time), time)
		{
			scanf("%d%d%s", &id, &problem, result);
			if (team[id].ac[problem]) continue;
			if (result[0] == 'n')
			{
				team[id].wrong[problem]++;
			}
			else
			{
				team[id].ac[problem] = 1;
				team[id].solved++;
				team[id].penalty += time + team[id].wrong[problem] * 20;
			}
		}

		qsort(team + 1, n, sizeof(team[1]), cmp);

		team[1].rank = 1;
		for (int i = 2; i <= n; i++)
		{
			if (team[i].solved == team[i - 1].solved && team[i].penalty == team[i - 1].penalty)
				team[i].rank = team[i - 1].rank;
			else team[i].rank = i;
			if (team[i].rank > 3) break;
		}

		printf("case %d:\n", ++cas);
		for (int i = 1; i <= n; i++)
		{
			if (team[i].rank > 3) break;
			printf("%d %d %d %d\n", team[i].id, team[i].solved, team[i].penalty, team[i].rank);

		}
	}
	return 0;
}

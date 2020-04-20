#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
bool step[27];
int way[15], match[27][27];
int minn, n, sum,i,j;
int find_same(char *p1, char *p2)
{
	int count = 0,k,h;
	int len1 = strlen(p1), len2 = strlen(p2);
	for (k = 0; k < len1; k++)
		for (h = 0; h < len2; h++)
			count += (p1[k] == p2[h]);
	return count;
}
void
 find_min(int x)
{
	int k;
	if (x > n)
	{
		if (sum < minn) minn = sum;
		return;
	}
	for (k = 1; k <= n; k++)
	{
		if (!step[k])
		{
			way[x] = k;
			step[k] = true;
			sum += match[way[x - 1]][k];
			find_min(x + 1);
			sum -= match[way[x - 1]][k];
			step[k] = false;
		}
	}
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		getchar();
		char r[15][27] = { 0 };
		memset(match, 0, sizeof(match));
		memset(step, 0, sizeof(step));
		memset(way, 0, sizeof(way));
		for (i = 1; i <= n; i++)
			scanf("%s", r[i]);
		for (i = 1; i<=n; i++)
			for (j = 1; j <= n; j++)
			{
				if (j != i)
					match[i][j] = match[j][i] = find_same(r[i], r[j]);
			}
		minn = 10000;
		sum = 0;
		find_min(1);
		printf("%d\n", minn);
	}
	return 0;
}

/*
5
ABC
ABEF
DEF
ABCDE
FGH
6
BDE
FGH
DEF
ABC
BDE
ABEF
4
XYZ
XYZ
ABYZ
Z
*/
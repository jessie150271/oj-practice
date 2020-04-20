#include<stdio.h>
#include<string.h>

#define M pm/m
#define N pn/n
int main()
{
	int m, n, k;
	while (scanf("%d%d%d", &m, &n, &k) != EOF)
	{
		double token, pm, pn;
		int i, flag;
		double num[10001] = { 0 };
		pm = pn = 0;
		flag = -1;
		for (i = 0; i < k; i++)
		{
			scanf("%lf", &num[i]);
			pm += num[i];
			pn += num[i];
			if (i >= m)
				pm -= num[i - m];
			if(i>=n)
				pn -= num[i - n];
			if (i >= n-1)
			{
				if (M > N && flag != 1)
				{
					printf("BUY ON DAY %d\n", i + 1);
					flag = 1;
				}
				if (M < N && flag != 0)
				{
					printf("SELL ON DAY %d\n", i + 1);
					flag = 0;
				}
			}
		}
	}
	return 0;
}
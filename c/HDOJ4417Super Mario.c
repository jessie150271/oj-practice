#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Point {
	int x, p;
}point[100005];
int cmp(const void *a, const void *b)
{
	return  ((struct Point*)a)->x > ((struct Point*)b)->x ? 1 : -1;
}
int main()
{
	int T,num=1;
	scanf("%d", &T);
	while (T--)
	{
		printf("Case %d:\n",num++);
		int n, m,i,L,R,H,count;
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &point[i].x);
			point[i].p = i;
		}
		qsort(point, n, sizeof(point[0]), cmp);
		while(m--)
		{
			scanf("%d%d%d", &L, &R, &H);
			count = 0,i=0;
			while(i<n)
			{
				if (H >= point[i].x&&point[i].p <= R&&point[i].p >= L) count++;
				else if (H < point[i].x)
					break;
				i++;
			}
			printf("%d\n", count);
		}
		memset(point, NULL, sizeof(point));
	}
    return 0;
}
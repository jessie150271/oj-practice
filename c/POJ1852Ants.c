#include<stdio.h>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int len, n,minN =0, maxN = 0,ant;
		scanf("%d%d", &len, &n);
		while (n--)
		{
			scanf("%d", &ant);
			minN = max(minN, min(ant, len - ant));
			maxN = max(maxN, max(ant, len - ant));
		}
		printf("%d %d\n", minN, maxN);
	}
    return 0;
}
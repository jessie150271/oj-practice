#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int son, ex;
	while (scanf("%d",&son)!=EOF)
	{
		int num[105] = { 0 }, i,ans=0;
		getchar();
		scanf("%d", &ex);
		getchar();
		for (i = 0; i < son; i++)
			scanf("%d", &num[i]);
		while (son--)
		{
			if (pow(num[son], ex)>0)
				ans += pow(num[son], ex);
		}
		printf("%d\n", ans);
	}
    return 0;
}
/*******************************
 *NTHUOJ-11105-D. Knight Number*
 *
 *
 *
 *******************************/

#include<stdio.h>

int check(n)
{
	int i;
	for (i = 0; n>0; i++)
	{
		if (n % 10 != 4 && n % 10 != 7)
			return 0;
		n /= 10;
	}
	return 1;
}
int main()
{
	int T,N,count=0;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d", &N);
		if (N % 7 == 0 || N % 4 == 0)
		{
			printf("Case #%d: T\n", ++count);
			continue;
		}
		else if (check(N))
		{
			printf("Case #%d: T\n", ++count);
			continue;
		}
		else
			printf("Case #%d: F\n", ++count);

	}
    return 0;
}
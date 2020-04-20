#include<stdio.h>
int main()
{
	int N,i, a[10];
	a[0] = 1;
	for (i = 1; i < 10; i++)
		a[i] = i*a[i - 1];
	while (scanf("%d", &N)&&N>-1)
	{
		if (N == 0)
			goto N;
		for (i = 9;N&&i>=0; i--)
		{
			if (a[i] <= N)
				N -= a[i];
		}
		if (!N)
			printf("YES\n");
		else
		{
		N:
			printf("NO\n");
		}
	}
    return 0;
}
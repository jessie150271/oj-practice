#include<stdio.h>


int main()
{
	int n;
	while (scanf("%d", &n) && n)
	{
		int t, sum = 0, temp=0,token=n;
		while (n--)
		{
			scanf("%d", &t);
			if (t - temp >= 0) 
				sum += (t - temp) * 6;
			else
				sum += (temp - t) * 4;
			temp = t;
		}
		printf("%d\n", sum + token * 5);
	}
    return 0;
}
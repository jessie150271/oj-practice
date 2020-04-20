#include<stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		(n % 2 == 0) ? printf("Bad\n") : printf("Balanced\n");
	}
    return 0;
}

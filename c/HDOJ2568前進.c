#include<stdio.h>

int func(int n)
{
	if (n == 1) return 1;
	if (n % 2==0) return func(n / 2);
	if (n % 2 != 0) return 1 + func((n - 1)/2);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		n=func(n);
		printf("%d\n", n);
	}
    return 0;
}
#include<stdio.h>

long long sol(long long  R, long long L)
{
	if (R <= 1) return 0;
	if (R == 2) return 1;
	if (R - L <= 1) return 2;
	if (L <= 1) L = 1;
	return (R - L) / 2 + 1;
}
int main()
{
	long long L, R;
	while (scanf("%lld %lld",&L,&R) != EOF)
	{
		printf("%lld\n", sol(R, L));
	}
    return 0;
}
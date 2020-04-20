#include<stdio.h>


int sum(int n,int x)
{
	int sum=0;
	while (n > 0)
	{
		sum += n%x;
		n /= x;
	}
	return sum;
}
int main()
{
	long num = 2992;
	while (num < 10000)
	{
		int temp = num;
		int De, He, Du;
		De = sum(num, 10), He = sum(num, 16), Du = sum(num, 12);
		if (De == He&&De == Du)
			printf("%d\n", num);
		num++;
	}
    return 0;
}
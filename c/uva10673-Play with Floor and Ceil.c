/* * * * * * * * * * * * * * * * * * * *
*  UVa 10673 Play with Floor and Ceil  *
*標頭檔 <math.h>	      			   *
*floor() = > 無條件捨去ex.└1/3┘= 0   *
* ceil() = > 無條件進位ex.┌1/3┐= 1   *
/* * * * * * * * * * * * * * * * * * * *
P.S round() = > 四捨五入至整數並轉成double*/

#include<stdio.h>
#include<math.h>
#include<stdbool.h>

long long sol(long long x,long long  k, double (*func)(double))
{
	return (long long)func((double)x / (double)k);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T!=0)
	{
		long long x, k, p, q,temp;
		bool test;
		scanf("%lld%lld", &x, &k);
		test = 0;
		for (p = 0; !test; p++)
		{
			for (q = 0; !test; q++)
			{
				temp = p*sol(x, k, floor) + q*sol(x, k, ceil);
				if (temp == x)
					test = 1;
				else if (temp > x)
					break;
			}
		}
		printf("%lld %lld\n", --p, --q);
		T--;
	}
    return 0;
}
#include<stdio.h>
#include<math.h>

int main()
{
	double ka, acid;
	int m, n;
	while (scanf("%lf %lf %d %d", &ka, &acid, &m, &n) && (ka || acid || m || n))
	{
		printf("%.3f\n", -log10((sqrt(ka*ka + 4*m*n*ka*acid)- ka) / (2 * n)));
		
	}
	return 0;
}
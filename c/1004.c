#include "stdio.h"


int main()
{
	double r, volume, i = 3.14159265358979323846;
	while (scanf("%lf",&r)!=EOF)
	{
		volume = (double)(4.0/3.0)*i*r*r*r;

		printf("%.6lf\n", volume);
	}
    return 0;
}
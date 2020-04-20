/*uva10589-Area*/
/*以有多少比例的點位於斜線區域，來推算斜線區域的面積是多少*/
#include<stdio.h>

#define T (double)(a*a)

struct Point/*定義結構*/
{
	double x;
	double y;
};
typedef struct Point point;/*用typedef就不用每次都寫struct關鍵字*/

double dis(point p1, point p2)/*距離公式：(x1-x2)^2 + (y1-y2)^2 開根號，因(a*a)^1/2也須開根號，因此可同時平方比較*/
{
	return ((p1.x - p2.x)*(p1.x - p2.x)) + ((p1.y - p2.y)*(p1.y - p2.y));
}
int main()
{
	int N, M, a, i;
	point p, A, B, C, D;
	while (scanf("%d%d", &N, &a) != EOF&&N)
	{
		M = 0;
		A.x = 0, A.y = 0;
		B.x = a, B.y = 0;
		C.x = a, C.y = a;
		D.x = 0, D.y = a;
		for (i = 0; i < N; i++)
		{
			scanf("%lf%lf", &p.x, &p.y);
			if (dis(p, A) <= T&&
				dis(p, B) <= T&&
				dis(p, C) <= T&&
				dis(p, D) <= T
				)
				M++;
		}
		printf("%.5lf\n", ((double)M / (double)N)*(double)a*(double)a);
	}
	return 0;
}
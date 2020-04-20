/********************************
 *uva10209-Is This Integration ?*
 *         算三條式子           *
 *(1)正方形-1/4圓               *
 *(2)1/6圓-正三角形             *
 *(3)1/4圓-1/6圓-(2) ===>解出z  *
 *(1)=y+2z ===>解出y            *
 *正方形=x+4y+4z ===>解出x      *
 ********************************/
#include<stdio.h>
#include<math.h>

#define PI acos(-1)
#define w (a*a*PI/6.0-a*a*sqrt(3)/4.0) /*w=1/6圓-正三角形*/
#define A a*a
int main()
{
	double a;
	while (scanf("%lf", &a) != EOF)
	{
		double x, y, z;/*x=斜線 y=點點 z=方格 */
		z = A-A*PI / 4.0 - (A*PI/4.0-A*PI/6.0-w);
		y = A - A*PI / 4.0 - z * 2.0;
		x = A - 4.0*y - 4.0*z;
		printf("%.3lf %.3lf %.3lf\n", x, 4 * y, 4 * z);
		
	}
    return 0;
}

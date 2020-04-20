#include "stdio.h"
#include "math.h"
#include "string.h"

int main()
{
	double input; int m, n,len,time; char chr,string[1000]; long token;
	while (scanf("%lf %d %d %c",&input,&m,&n,&chr)!=EOF)
	{
		token = (double)input *pow(10,n);
		input = token;
		input /= pow(10, n);
		//printf("ipnut=%.*lf\n",n, input);//
		sprintf(string, "%.*lf", n, input);
		len = strlen(string);
		//printf("string=%s\n", string);//
		//printf("len=%d\n", len);//
		if (m - len > 0)
		{
			time = m - len;
			do
			{
				printf("%c", chr);
				time -= 1;
			} while (time>0);
		}
		printf("%.*lf\n", n, input);
	}

    return 0;
}
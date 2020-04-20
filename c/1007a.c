#include <stdio.h>
#include <math.h>
#include <string.h>


int main()
{
	double input;
	int m, n;
	char chr;

	while (scanf("%lf %d %d %c", &input, &m, &n, &chr) != EOF)
	{
		long intInput = input * pow(10, n);
		input = intInput;
		input /= pow(10, n);

		char ans[999];

		sprintf(ans, "%.*lf", n, input);

		int len = strlen(ans);

		int count = m - len;

		for (int i = 0; i < count; i++)
		{
			printf("%c", chr);
		}
		printf("%.*lf\n", n, input);

	}
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
void do_cos(int num,int n,int test)
{
	long double cos=0;
	if (num > 180)
	{
		num -= 180;
		test = -1;
	}
	else if (num < -180)
	{
		num += 360;
	}
	else if (num < 0)
	{
		num += 180;
		test = -1;
	}
	long double x = num*(3.14 / 180);
	for (int i = 0; i <= n; i++)
	{
		long long int factor = 1;
		for (int j = 1; j <= 2*i; j++)
		{
			factor *= j;
		}
		cos =cos+ (pow(-1, i)*pow(x, 2*i)) / factor;
	}
	if (test == -1)
	{
		printf("%llf\n", -cos);
	}
	else
	{
		printf("%llf\n", cos);
	}
}
void do_sin(num,n,test)
{
	long double sin=0;
	if (num > 180)
	{
		num -= 180;
		test = -1;
	}
	else if (num < -180)
	{
		num +=360;
	}
	else if (num < 0)
	{
		num +=180;
		test = -1;
	}
	long double x = num*(3.14 / 180);
	for (int i = 0; i <= n; i++)
	{
		long long int factor = 1;
		for (int j = 1; j <= 2*i+1; j++)
		{
			factor *= j;
		}
		sin =sin+ (pow(-1, i)*pow(x, 2 * i + 1)) / factor;
	}
	if (test == -1)
	{
		printf("%llf\n", -sin);
	}
	else
	{
		printf("%llf\n", sin);
	}
}
int test_char(char n[])
{
	if (n[0] == 'c'&&n[1] == 'o'&&n[2] == 's'&&n[3] == '\0')
	{
		return 1;
	}
	else if (n[0] == 's'&&n[1] == 'i'&&n[2] == 'n'&&n[3] == '\0')
	{
		return 2;
	}
	else
	{
		printf("Input Error.\n");
		return 0;
	}

}
int main(void)
{
	char input[] = { 0 };
	int num, n;
	while (scanf("%s", &input) != EOF)
	{
		int test = 0;
		double x = 0;
		for (int i = 0; i < strlen(input); i++)
		{
			input[i] = tolower(input[i]);
		}
		int test_sc = test_char(input);
		if (test_sc == 1 || test_sc == 2)
			scanf("%d %d", &num, &n);
		else
		{
			continue;
		}
		num %= 360;
		printf("num=%d\n", num);
		if (test_sc == 1)
		{
			do_cos(num,n,test);
		}
		else if (test_sc == 2)
		{
			do_sin(num,n,test);
		}
	}
	return 0;
}
#include<stdio.h>
#include<string.h>

int main()
{
	char input[1005] = { 0 };
	while (gets(input) != NULL)
	{
		int i;
		for (i = 0;input[i]; i++)
		{
			if (input[i] == 'y'&&input[i + 1] == 'o'&&input[i + 2] == 'u'&&i<strlen(input)-2)
			{
				printf("we");
				i += 2;
			}
			else
				putchar(input[i]);
		}
		puts("");
		memset(input, 0, sizeof(input));
	}
    return 0;
}
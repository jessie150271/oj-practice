#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char input[500];
	while (gets(input) != NULL)
	{
		int len = strlen(input);
		int count = 0, end = len-1;
		int sta;
		for (int i = len - 2; i >= 0; i--)
		{
			sta = i+1;
			if(input[i]==' ')
			{
				for (int j = sta; j < end; j++)
				{
					printf("%c", input[j]);
				}
				end = i;
				printf(" ");
			}
			else if (i == 0)
			{
				for (int j = 0; j < end; j++)
				{
					printf("%c", input[j]);
				}
			}
		}
		printf("%c\n", input[len - 1]);
	}
	return 0;
}
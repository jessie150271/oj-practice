#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void first(char k)
{
	switch (k)
	{
	case '0':case '2':case '3':case '5':case '6':case '7':case '8':case '9':
		printf(" _ ");
		break;
	case '1':case '4':
		printf("   ");
		break;
	default:
		break;
	}
}
void second(char k)
{
	switch (k)
	{
	case '1':case '7':
		printf("  |");
		break;
	case '2':case '3':
		printf(" _|");
		break;
	case '4':case '8':case '9':
		printf("|_|");
		break;
	case '5':case '6':
		printf("|_ ");
		break;
	case '0':
		printf("| |");
		break;
	default:
		break;
	}
}
void third(char k)
{
	switch (k)
	{
	case '1':case '4':case '7':case '9':
		printf("  |");
		break;
	case '2':
		printf("|_ ");
		break;
	case '3':case '5':
		printf(" _|");
		break;
	case '6':case '8':case '0':
		printf("|_|");
		break;
	default:
		break;
	}
}
int test(char k)
{
	switch (k)
	{
	case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
		return 1;
		break;
	default:
		return 0;
		break;
	}
}
int main(void)
{
	char input[120];
	while (scanf("%s",&input)!=EOF)
	{
		
		char K[100] = {0};
		for (int i = 0,j=0; i < strlen(input); i++)
		{
			if (test(input[i]))
			{
				K[j++] = input[i];
			}
		}
		for (int i = 0; i < strlen(K); i++)
		{
			first(K[i]);
			if (i == strlen(K) - 1)
			{
				printf("\n");
			}
		}
		for (int i = 0; i < strlen(K); i++)
		{
			second(K[i]);
			if (i == strlen(K) - 1)
			{
				printf("\n");
			}
		}
		for (int i = 0; i < strlen(K); i++)
		{
			third(K[i]);
			if (i == strlen(K) - 1)
			{
				printf("\n");
			}
		}
		
	}
return 0;
}
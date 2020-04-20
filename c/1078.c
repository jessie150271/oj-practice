#include <stdio.h>
#include <string.h>

int main()
{
	char input[1001];
	int i, j, check = 0;
	while (gets(input) != NULL)
	{
		for (i = 0; i < strlen(input); i++)
		{
			if (input[i] == '\\')
			{
				if (input[i + 1] != '*' && check == 1)
					goto PUT;
				if (input[i + 1] == '\\')
				{
					putchar('\\');
					i++;
				}
				else if (input[i + 1] == 's')
				{
					i = i + 2;
					while (input[i] >= '0' && input[i] <= '9')
						i++;
					if (input[i] == '.')
					{
						i++;
						while (input[i] >= '0' && input[i] <= '9')
							i++;
					}
					i--;
				}
				else if (input[i + 1] == '*')
				{
					i++;
					if (check == 1)
					{
						check = 0;
						continue;
					}
					check = 1;
					for (j = i + 1; input[j]; j++)
					{
						if (input[j] == '\\' && input[j + 1] == '*')
						{
							check = 0;
							break;
						}
						putchar(input[j]);
					}
					i = j + 1;
				}
				else if (input[i + 1] == 'b' || input[i + 1] == 'i')
					i++;
			}
			else
			{
			PUT:
				putchar(input[i]);
			}
		}
		puts("");
	}
	return 0;
}
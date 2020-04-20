#include<stdio.h>
#include<string.h>

#define K rec[i]
typedef struct St{

	char firstName[25];

	char lastName[30];

	char phone[15];

} StRec;
int SD(char a[], char b[], char c[], char h[], char j[], char k[])
{
	if (strcmp(a, h) == 0 && strcmp(b, j) == 0 && strcmp(c, k) == 0)
		return 1;
	return 0;
}
int main()
{
	StRec rec[10] = { NULL };
	char func[7];
	int count = 0;
	while (scanf("%s",&func)!=EOF)
	{
		if (strcmp(func, "print") == 0)
		{
			int p=1;
			for (int i = 0; i < 10; i++) 
			{
				if (K.firstName[0] != 0)
				{
					printf("%s %s %s\n", K.firstName, K.lastName, K.phone);
					p = 0;
				}
				else if(i==9&&p)
				{
					printf("Print Error\n");
					break;
				}
			}
		}
		else if (strcmp(func, "insert") == 0)
		{
			if (count > 10)
				printf("Insert Error\n");
			for (int i = 0; i < 10; i++)
			{
				if (K.firstName[0] == 0)
				{
					scanf("%s %s %s", &K.firstName, &K.lastName, &K.phone);
					count++;
					break;
				}
			}
		}
		else if (strcmp(func, "search") == 0|| strcmp(func, "delete") == 0)
		{
			char a[25], b[30], c[15];
			scanf("%s %s %s", a, b, c);
			for (int i = 0; i < 10; i++)
			{
				if (SD(a, b, c, K.firstName, K.lastName, K.phone))
				{
					if (strcmp(func, "search") == 0) 
						printf("%d\n", i);
					else
					{
						count--;
						*K.firstName= NULL;
						*K.lastName = NULL;
						*K.phone = NULL;
						for (int j = i+1; j < 10; j++)
						{
							if (rec[j].firstName[0] != 0)
							{
								rec[j-1]=rec[j];
								*rec[j].firstName = NULL;
								*rec[j].lastName = NULL;
								*rec[j].phone = NULL;
							}
						}
					}
					break;
				}
				else if (i == 9)
				{
					if (strcmp(func, "search") == 0)
						printf("Search Error\n");
					else
						printf("Delete Error\n");
				}
			}
		}
	}
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void * p1, const void * p2)
{
	return strcmp((char*)p1, (char*)p2);
}

int main()
{
	char i[100][21] = { NULL };
	while (scanf("%s", i[0]) != EOF)
	{
		int len = strlen(i[0]),count=1;
		for (;len!=4;count++)
		{
			scanf("%s", i[count]);
			len = strlen(i[count]);
		}
		qsort(i, sizeof(i) / sizeof(i[0]), sizeof(*i), cmp);
		printf("%s %s\n", i[100-count],i[99]);
		for (int j = 0; j < 100; j++)
		{
			for (int k = 0; k < 21; k++)
			{
				i[j][k]=0;
			}
		}
	}
    return 0;
}
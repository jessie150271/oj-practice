#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_C 201

int cmp(const void *p1, const void *p2)
{
	return strcmp((char*)p1, (char*)p2);
}
int main()
{
	int N;
	while (scanf("%d",&N)!=EOF)
	{
		getchar();
		while (N--)
		{
			int num,maxlen=0;
			char **k;
			char ary[MAX_C][MAX_C] = { 0 };
			for (int i = 0;; i++)
			{
				gets(ary[i]);
				if (ary[i][0] == '-')
				{
					ary[i][0]= 0;
					num = i;
					break;
				}
				if (maxlen < strlen(ary[i]))
					maxlen = strlen(ary[i]);
			}
			qsort(ary, sizeof(ary) / sizeof(ary[0]), sizeof(*ary), cmp);
			k = malloc(num*sizeof(char*));
			for (int i = 0; i < num; i++)
			{
				k[i] = malloc(maxlen*sizeof(char*));
				k[i] = &ary[201-num+i];
			}
			for (int i = 0; i < num; i++)
				printf("%s\n", k[i]);
		}
	}
    return 0;
}
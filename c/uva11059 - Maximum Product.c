/*uva11059-Maximum Product*/
/*InputS陣列有N個數字
求出陣列中連續的數字的乘積最大值*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N,count=1;
	while (scanf("%d", &N) != EOF)
	{
		int *s,i,j,k;//給陣列和運算用的
		s = (int*)malloc(sizeof(int)*N);
		long long max = 0, token;
		/*因題目可給定18個10，最大位數為10的18次方，需用long long*/
		for (i = 0; i < N; i++)
			scanf("%d", &s[i]);
		/*陣列中連續的數字，使用3個for求出每種可能*/
		/*
		第一個for 從第一個數字開始，重複N次
		第二個for 結束於第j個數字
		第三個for 從第i個數字開始，乘到j結束，並判斷max
		*/
		for (i = 0; i < N; i++)
		{
			for (j = N-1; j >=i; j--)
			{
				token = 1;
				for(k=i;k<=j;k++)
					token *= s[k];
				if (token > max)
					max = token;
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", count++,max);
	}
	return 0;
}
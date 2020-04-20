/*UVa591 - Box of Bricks*/
/*把磚塊排成平的*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N;
	int count = 0;
	while (scanf("%d", &N) != EOF)
	{
		if (N == 0)/*讀到0結束程式*/
			return 0;
		else
		{
			int token = 0;
			int *k;
			k = (int*)malloc(sizeof(int)*N);
			int i;
			for (i = 0; i < N; i++)
			{
				scanf("%d", &k[i]);
				token += k[i];
			}
			if (token%N != 0)/*無法排成平的(不是N的倍數)*/
				printf("Error\n");
			else
			{
				int a = 0;
				count++;
				for (i = 0; i < N; i++)
				{
					a += abs(k[i] - token / N);/*每列磚塊都要變成總數/N列-->差值總和/2-->搬下一個磚另一列就會搬上一個磚*/
				}
				printf("Set #%d\nThe minimum number of moves is %d.\n\n", count, a / 2);
			}
			free(k);
		}
	}
	return 0;
}
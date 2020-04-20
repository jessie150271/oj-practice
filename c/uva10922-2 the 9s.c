#include<stdio.h>
#include<string.h>

int f(ans)
{
	int ans1 = 0;
	for (;ans > 0; ans /= 10)
	{
		ans1 += ans % 10;
	}
	return ans1;
}

int main()
{
	char i[1005] = { NULL };
	while (scanf("%s", i) != EOF)
	{
		if (i[0] == 48&& strlen(i)==1)
			return 0;
		else
		{
			printf("%s", i);
			int ans = 0, count = 1,j;
			for (j = 0; j < strlen(i); j++)
				ans += i[j] - 48;
			if (ans % 9 != 0)/*判斷input是不是9的倍數*/
				printf(" is not a multiple of 9.\n");
			else
			{
				while (ans != 9)/*相加=9結束迴圈*/
				{
					ans = f(ans);
					count++;/*紀錄迴圈進行次數*/
				}
				printf(" is a multiple of 9 and has 9-degree %d.\n", count);
			}
			for (j = 0; j < 1005; j++)
			{
				i[j] = 0;
			}
		}
	}
	return 0;
}
/*Jolly Jumper*/
/*輸入的數列前後之差值
必須涵蓋1~N-1
且總共會有N-1個差值*/

#include<stdio.h>
#define T abs(n[k]-n[k-1])
int main(void)
{
	int N;
	while (scanf("%d", &N) != EOF)
	{
		int n[3001] = {0},check[3001] = {0};
		int k, pri = 0;
		for (k = 0; k < N; k++)
		{
			scanf("%d", &n[k]);
			if (k > 0)
				check[T] = 1;//紀錄差值出現過的數字
		}
		for (k = 1; k < N; k++)
		{
			if (check[k] != 1)
			{
				pri++;//只要1~N-1之間有一個數字不是此陣列有的差值-->Not jolly
				break;
			}
		}
		(pri == 0) ? printf("Jolly\n") : printf("Not jolly\n");
	}
	return 0;
}
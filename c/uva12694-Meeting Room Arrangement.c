#include<stdio.h>

int main()
{
	int n, i;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			int tc[21][3] = { 0 };
			int k, j = 0, count = 0,maxnum=0;
			int time[10] = { 0 };
			for (;;j++)
			{
				scanf("%d %d", &tc[j][0], &tc[j][1]);
				if (tc[j][0] == 0 && tc[j][1] == 0)
					break;
				tc[j][2] = tc[j][1] - tc[j][0];
				if (tc[j][2] > maxnum)
					maxnum = tc[j][2];
				if (tc[j][2] == 1&& time[tc[j][0]] ==0)//貪婪演算法-極端值先做，再依序確認其他數值是否可置入
				{
					time[tc[j][0]]++;
					count++;
				}//先算time=1有幾個，再依序check其他差值(tc[][2])是否可置入
			}
			for (k=2; k <= maxnum; k++)//只需check到最大差值
			{
				int test = 0,p,m;
				for (m = 0; m < j; m++)
				{
					if (tc[m][2] == k)
					{
						for (p = 0; p < k; p++)
						{
							if (time[tc[m][0]+p] != 0)
							{
								test = 1;//if時間已被使用,continue
								break;
							}
						}
						if (test == 1)
							continue;
						else//若可置入case,更新時間陣列使用狀態
						{
							for (p = 0; p < k; p++)
							{
								time[tc[m][0]+p]++;
							}
							count++;
						}
					}
				}
			}
			printf("%d\n", count);
		}
	}
	return 0;
}
/*******************************
 *uva10141-Request for Proposal*
 *       沒有什麼技巧          *
 *        善用struct           *
 *   輸入的服務項目可忽略      *
 *******************************/
/*中文題目：https://zerojudge.tw/ShowProblem?problemid=a535 */
#include<stdio.h>
#include<stdlib.h>

struct Factory
{
	char name[80];/*提案名稱(print Best的名稱)*/
	float f;/*報價*/
	int r;/*可提供服務個數*/
};
typedef struct Factory fac;

int main()
{
	fac best, input;
	int n, p, i, j;
	int RFP = 0;
	char chr[80];
	while (scanf("%d%d", &n, &p) != EOF&&n)
	{
		getchar();/* delete the enter key */
		if (RFP)printf("\n");
		for (i = 0; i < n; i++)
			gets(chr);/*不重要 設一個字元陣列讀取掉*/
		best.r = 0;/*初始化fac best.r*/
		for (i = 0; i < p; i++)
		{
			gets(input.name);
			scanf("%f%d", &input.f, &input.r);
			getchar();/* delete the enter key */
			for (j = 0; j < input.r; j++)
				gets(chr);/*不重要 設一個字元陣列讀取掉*/
			if (best.r < input.r)/*比較可提供服務個數*/
				best = input;
			else if (best.r == input.r&&best.f > input.f)/*若可提供服務個數相等 比較報價*/
				best = input;
		}
		printf("RFP #%d\n%s\n", ++RFP, best.name);
	}
	return 0;
}
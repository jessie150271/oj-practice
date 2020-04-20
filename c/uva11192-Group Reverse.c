/*uva11192-Group Reverse*/
/*有G組反向輸出字串
input之字串必為G的倍數
當G==0時結束程式*/
#include<stdio.h>
#include<string.h>

#define T strlen(n)/G
int main(void)
{
	int G;
	while (scanf("%d",&G)!=EOF)
	{
		if (G == 0)
			return 0;
		char n[101],*g;
		int i,j,k;
		scanf("%s", &n);
		g = (char*)malloc(sizeof(char)*T);//浮動陣列g[T=字串長度/有G組(=每組有幾個字元)]
		for (i = 0, j =T-1; i < T*G; i++, j--)
		{
			g[j] = n[i];//g的最後一項=n的第一項
			if (j == 0)
			{
				j = T;
				for (k = 0; k < T; k++)
				{
					printf("%c",g[k]);//輸出每組字串
				}
			}
		}
		printf("\n");
	}
	return 0;
}
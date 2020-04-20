/******************************
 *11067-Little Red Riding Hood*
 *設兩個二維陣列			  *
 *一個存大野狼的位置		  *
 *一個存小紅帽目前走的位置次數*
 *用兩個for判斷往上/往右是否  *
 *會碰到大野狼 if not		  *
 *下一個位置+上一個位置的次數 *
 *最後path[w][h]等於總共的次數*
 ******************************/
#include<stdio.h>

int main()
{
	int w, h, n, x, y;
	int i, j;
	while (scanf("%d%d",&w,&h)!=EOF&&(w||h))
	{
		int grid[102][102] = { 0 }, path[102][102] = { 0 };
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d%d", &x, &y);
			grid[x][y] = 1;
		}
		path[0][0] = 1;
		for (i = 0; i <= w; i++)
		{
			for (j = 0; j <= h; j++)
			{
				if (!grid[i + 1][j])
					path[i + 1][j] += path[i][j];
				if (!grid[i][j + 1])
					path[i][j + 1] += path[i][j];
			}
		}
		switch (path[w][h])
		{
		case 1:
			printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
			break;
		case 0:
			printf("There is no path.\n");
			break;
		default:
			printf("There are %d paths from Little Red Riding Hood's house to her grandmother's house.\n",path[w][h]);
			break;
		}
	}
    return 0;
}
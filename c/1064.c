#include<stdio.h>
#include<stdlib.h>

typedef struct Tag
{
	int x, y;
}Point;
char move[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int MoveTest()
{

}
int main()
{
	int N, minmove;
	char **map;
	while (scanf("%d", &N) != EOF)
	{
		Point point[1000], cur;
		map = malloc(N * sizeof(char*));
		for (int i = 0; i < N; i++)
			map[i] = malloc(N * sizeof(char*));
		int x, y,sX,sY,count=0;
		for(x=0;x<N;x++)
			for (y = 0; y < N; y++)
			{
				if (y == 0) getchar();
				scanf("%c",&map[x][y]);
				if (map[x][y] == 'S') { sX = x; sY = y; }
			}
		
		for (int i = 0; i < N; i++)
			free(map[i]);
		free(map);
	}
	return 0;
}
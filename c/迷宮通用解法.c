/*
Creator : WSR
Date    : 2016 . 10 . 13
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define PRINT_AND_BREAK(msg) { printf(msg); break; }

typedef struct PointTag
{
	int x, y;
	char chr;
} Point;

char moveMatrix[8][2] = { { 1 , 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 },{ 1, 1 },{ -1, -1 },{ 1, -1 },{ -1, 1 } };

char Move(Point *point, char map[][MAX_N + 2])
{
	for (int i = 0; i < 8; ++i)
	{
		if (point->chr == '/' && i == 4) // / �ר��ਫ moveMatrix[6] ~ moveMatrix[7] �����V
			i += 2;
		else if (point->chr == '\\' && i >= 6) // \ �ר��u�ਫ moveMatrix[4] ~ moveMatrix[5] �����V
			break;
		char ch = map[point->x + moveMatrix[i][0]][point->y + moveMatrix[i][1]];
		if (point->chr != '/' && point->chr != '\\' && i >= 4 &&
			(i < 6 && ch != '\\' || i >= 6 && ch != '/')) //�P�_�ר��W�h
			continue;
		if (ch == '-' || ch == '\\' || ch == '/' || ch == 'T')
		{
			point->x += moveMatrix[i][0];
			point->y += moveMatrix[i][1];
			point->chr = map[point->x][point->y];
			map[point->x][point->y] = '*';
			return 1;
		}
	}
	return 0;
}

int main()
{
	char map[MAX_N + 2][MAX_N + 2] = { 0 };
	Point point[MAX_N], curPoint;

	int n, sizeOfStack = 0;
	while (scanf("%d", &n) != EOF)
	{
		sizeOfStack = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				scanf(" %c", &(map[i][j]));
				map[i + 1][j] = map[i][j + 1] = '\0';
				if (map[i][j] == 'S')
				{
					curPoint.x = i; curPoint.y = j;
				}
			}

		curPoint.chr = map[curPoint.x][curPoint.y] = '*';
		while (1)
		{
			if (curPoint.chr == 'T')
				PRINT_AND_BREAK("Yes\n");
			point[sizeOfStack] = curPoint;
			if (Move(&curPoint, map) == 0) //Failed
			{
				if (sizeOfStack == 0)
					PRINT_AND_BREAK("No\n");
				curPoint = point[--sizeOfStack];
			}
			else
				++sizeOfStack;
		}
	}
}
#include<stdio.h>
#include<string.h>
typedef enum Bool
{
	false = 0,
	true = 1
}bool;
int main()
{
	bool grid[101][101] = { false };
	int N,x,y,L,i,j,count;
	char ch[6];
	scanf("%d", &N);
	while (N--)
	{
		getchar();
		scanf("%s %d %d %d", ch, &x, &y, &L);
		if (!strcmp(ch, "WHITE"))
		{
			for (i = x; i < x + L; i++)
				for (j = y; j < y + L; j++)
					grid[i][j] = false;
		}
		else if (!strcmp(ch,"BLACK"))
		{
			for (i = x; i < x + L; i++)
				for (j = y; j < y + L; j++)
					grid[i][j] = true;
		}
		else if (!strcmp(ch, "TEST"))
		{
			count = 0;
			for (i = x; i < x + L; i++)
				for (j = y; j < y + L; j++)
					if (grid[i][j] == true)
						count++;
			printf("%d\n", count);
		}
	}
    return 0;
}
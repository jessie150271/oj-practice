#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int R, n;
	while (scanf("%d%d", &R, &n) != EOF)
	{
		int k, j, i, count, temp, range, center, troop[1005] = { 0 };
		if (R == -1)
			return 0;
		for (k = 0; k < n; k++)
			scanf("%d", &troop[k]);
		for (k = 0; k<n; k++)
			for (j = k + 1; j < n; j++)
			{
				if (troop[k] > troop[j])
				{
					temp = troop[k];
					troop[k] = troop[j];
					troop[j] = temp;
				}
			}
		i = 0, count = 0;
		while (i < n)
		{
			range = troop[i++];
			while (i < n&&troop[i] <= range + R)
				i++;
			center = troop[--i];
			while (i < n&&troop[i] <= center + R)
				i++;
			count++;
		}
		printf("%d\n", count);
		memset(troop, 0, sizeof(troop));
	}
	return 0;
}
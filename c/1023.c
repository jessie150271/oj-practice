#include "stdio.h"
#include<string.h>
#include<ctype.h>

int main()
{
	char c[999];
	while (scanf("%s", &c) != EOF)
	{
		int len = strlen(c);
		int ans=0;
		for (int i = 0; i < len; i++)
		{
			c[i] = tolower(c[i]);
			if (c[i]=='a'|| c[i] == 'e'|| c[i] == 'i'|| c[i] == 'l'|| c[i] == 'n'|| c[i] == 'o'|| c[i] == 'r'|| c[i] == 's'|| c[i] == 't'|| c[i] == 'u')
			{ans += 1;}
			else if (c[i] == 'd' || c[i] == 'g'){ans += 2;}
			else if (c[i] == 'b' || c[i] == 'c' || c[i] == 'm' || c[i] == 'p') { ans += 3; }
			else if (c[i] == 'f'|| c[i] == 'h'|| c[i] == 'v'|| c[i] == 'w'|| c[i] == 'y'){ans += 4;}
			else if (c[i] == 'k') { ans += 5; }
			else if (c[i] == 'j' || c[i] == 'x') { ans += 8; }
			else if (c[i] == 'q' || c[i] == 'z') { ans += 10; }
			else{continue;}
		}
		printf("Scrabble Value: %d\n", ans);
	}
    return 0;
}
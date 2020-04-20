#include<stdio.h>
#include<string.h>

int main()
{
	char input[]="";
	while (gets(input)!=EOF)
	{
		int time = 0,test=0;
		float ans = 0;
		int len = strlen(input);
		for (int i=0;i<len; i++)
		{
			if (input[i]==' '&&ans==0.0){continue;}
			else if (input[i] == ' '&&test!=1) { time += 1;test=1; continue; }
			else if(input[i]!=' '){ ans += 1; test = 0; }
		}
		time += 1;
		ans = ans/time*10;
		test = ans;
		ans = test;
		printf("Average word length: %.1f\n", ans/10);
	}
    return 0;
}
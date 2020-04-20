/*uva10924-Prime Words*/
/*
Prime numbers質數
a=1....z=26
A=27...Z=52
字串的總和是Prime numbers
這個字串就是Prime words
*/
#include<stdio.h>
#include<math.h>

int main()
{
	char L[21];
	while (scanf("%s", L) != EOF)
	{
		int sum=0,i;
		for (i = 0; L[i]; i++)/*計算字串相應數字總和得到sum*/
		{
			if (L[i] <= 'z'&&L[i] >= 'a')
				sum += L[i] - 'a'+1;
			else
				sum += L[i] - 'A' + 27;
		}
		int test = 0;
		for (i = 2; i <=sqrt(sum) ; i++)/*判斷是不是質數*/
		{
			if (sum%i == 0)
			{	
				test=1;
				break;
			}
		}
		(test == 0) ? printf("It is a prime word.\n") : printf("It is not a prime word.\n");
	}
    return 0;
}
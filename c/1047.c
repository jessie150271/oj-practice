#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
const char ans_table[10][4] = { "","","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY" };

void print_ans(int num[], int k)
{
	int *ptr;
	ptr = (int*)malloc(sizeof(int)*k);//用來控制列印到第m行的陣列
	int count = 0;
	for (int i = 0; i < k; i++)
	{
		ptr[i] = 0;//初始化陣列
	}
	for (int m = 0; m < pow(3, k); m++)//總共會列印m=3^k行(依數學原理) P.S.< 行 是 直 der 不 是 橫 der >
	{
		for (int a = 0; a<k; a++)
		{
			printf("%c", ans_table[num[a]][ptr[a]]);//利用定義的ans_table列印
			//ans_table[輸入的數字][輸入的數字對應這次執行所的行(ptr)]
			//例如輸入23，會先列印AD=> ans_table[2~3][對應的行(ptr)不用動]
			if (a == k - 1)
			{
				ptr[k - 1]++;// 當列印完一列的時候，ptr要++ 換行~是直的換!是直的換!是直的換!
			}
		}
		printf("\n");//列印完一行要\n BJ4
		for (int j = k - 1; j >= 0; j--)//重點來啦~
		{
			if (ptr[j] == 3)//如果ptr已經是3了，代表那一排已經跑完了(如果是2，代表ABC都已經列印過了)
				//這時候要<進位>!
			{
				ptr[j] = 0;//讓已經都列印過的那一列歸零，讓下一次迴圈回到最左邊開始列印
				if (j - 1 >= 0)
				{
					ptr[j - 1]++;//讓前一個數字的ptr++，它就會開始跑第2行的字母
					//這個觀念和3進位制是一樣Der~
				}
				else
					break;
			}
			else
			{
				continue;
			}
		}
	}
}
int main()
{
	char input[150];
	while (scanf("%s", &input) != EOF)
	{
		int num[150] = { 0 };

		int test = 0, k = 0;
		for (int i = 0; i < strlen(input); i++)
		{
			if (test == 0)
			{
				switch (input[i])
				{
				case '0':case '1':
					test = -1;
					break;
				case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':
					num[k] = input[i] - 48;//儲存有效數字到num[]
					k++;
					if (k == 7)
					{
						test = 1;
					}
					break;
				default:
					break;
				}
			}
			else
				break;
		}
		if (test == -1)
		{
			printf("Can't print a word!\n");
		}
		else if (k == 0)
		{
			printf("None.\n");
		}
		else
		{
			print_ans(num, k);//傳送num[],k(幾個有效數字)到函式
		}
	}
	return 0;
}
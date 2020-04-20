#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(void)
{
	char input[99] = {NULL};
	while (gets(input) != NULL)
	{
		int rs[5][3] = { NULL };
		int count = 0, token=0;
		int *ptr;
		char k;
		for (int j = 0; j < 5; j++)//將input放入rs[5][3]，給定對應順序的數字，並控制*ptr值使非法字元必定>判斷值
		{
			for (int i = 0; i < 3; i++)
			{
				ptr = &rs[j][i];
				k = tolower(input[count]);
				if (i == 0)
				{
					switch (k)
					{
					case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':
						*ptr = k - 48;
						break;
					case't'://10
						*ptr = k - 106;
						break;
					case'j'://11
						*ptr = k - 95;
						break;
					case'q'://12
						*ptr = k - 101;
						break;
					case'k'://13
						*ptr = k - 94;
						break;
					case'a'://14
						*ptr = k - 83;
						break;
					default://使非法值必>14
						*ptr = k + 1000;
						break;
					}
				}
				else if (i == 1)
				{
					switch (k)
					{
					case'c'://1
						*ptr = k - 98;
						break;
					case'd'://2
						*ptr = k - 98;
						break;
					case'h'://3
						*ptr = k - 101;
						break;
					case's'://4
						*ptr = k - 111;
						break;
					default://使非法值必>4
						*ptr = k + 1000;
						break;
					}
				}
				count++;
			}
		}
		for (int i = 0; i < 5; i++)//排序rs[~][0]
		{
			for (int j = 0; j < 4; j++)
			{
				if (rs[j][0] > rs[j + 1][0])
				{
					token = rs[j][0];
					rs[j][0] = rs[j + 1][0];
					rs[j + 1][0] = token;
					token = rs[j][1];
					rs[j][1] = rs[j + 1][1];
					rs[j + 1][1] = token;

				}
			}
		}
		for (int i = 0; i < 5; i++)//如果rs[~][0]相等，排序rs[~][1]
		{
			for (int j = 0; j < 4; j++)
			{
				if (rs[j][0] == rs[j + 1][0])
				{
					if (rs[j][1] > rs[j + 1][1])
					{
						token = rs[j][1];
						rs[j][1] = rs[j + 1][1];
						rs[j + 1][1] = token;
					}
				}
			}
		}
		int illegal = 0, duplicate = 0;//判斷非法卡片
		for (int i = 0; i < 5; i++)
		{
			if (rs[i][0] > 14 || rs[i][1] > 4)//非法字元判斷
			{
				illegal = 1;
			}
			if (rs[i][0] == rs[i + 1][0] && rs[i][1] == rs[i + 1][1]&&i<4)//重複卡片判斷
			{
				duplicate = 1;
			}
		}/*非法的卡片重複的話算Illegal and Duplicate cards
		 EX:[ yt yt 8s 8h 8i ]=Illegal and Duplicate cards*/
		if (illegal == 1 && duplicate == 1)
		{
			printf("Illegal and Duplicate cards\n");
			continue;
		}
		else if (illegal == 1)
		{
			printf("Illegal card\n");
			continue;
		}
		else if (duplicate == 1)
		{
			printf("Duplicate card\n");
			continue;
		}
		int Straight = 0, Flush = 0, Four = 0, Three = 0, Two = 0;//判斷合法卡片類型
		for (int i = 0; i < 4; i++)//判斷同花/順子/同花順
		{
			if (rs[i][1] == rs[i + 1][1])
				Flush++;//flush=4是順子
			if (rs[i][0] - rs[i + 1][0] == -1)
				Straight++;//straight=4是同花
			if (rs[i][0] == rs[i + 1][0] && rs[i + 1][0] == rs[i + 2][0] && rs[i + 2][0] == rs[i + 3][0] && i + 3 < 5)
			{
				Four++;//4張卡片相同 鐵支
				break;
			}
			else if (rs[i][0] == rs[i + 1][0] && rs[i + 1][0] == rs[i + 2][0] && i + 2 < 5)
			{
				Three++;//三條或葫蘆
				if (Two != 0)
					break;
				else
					i++;
			}
			else if (rs[i][0] == rs[i + 1][0])
				Two++;/*Two的係數會影響葫蘆/三條/兔胚/對子*/
		}
		/*↓依規則階層高低判斷類型並列印↓*/
		if (Straight == 4 && Flush == 4)
			printf("Straight Flush");
		else if (Four == 1)
			printf("Four-Of-A-Kind");
		else if (Three == 1 && Two == 1)
			printf("Full House");
		else if (Flush == 4)
			printf("Flush");
		else if (Straight == 4)
			printf("Straight");
		else if (Three == 1)
			printf("Three-Of-A-Kind");
		else if (Two == 2)
			printf("Two Pairs");
		else if (Two == 1)
			printf("Pair");
		else
			printf("High Card");
		/*↓列印rs陣列內容↓*/
		for (int i = 0; i < 5; i++)
		{
			switch (rs[i][0])
			{
			case 10:
				printf(" t");
				break;
			case 11:
				printf(" j");
				break;
			case 12:
				printf(" q");
				break;
			case 13:
				printf(" k");
				break;
			case 14:
				printf(" a");
				break;
			default:
				printf(" %d", rs[i][0]);
				break;
			}
			switch (rs[i][1])
			{
			case 1:
				printf("c");
				break;
			case 2:
				printf("d");
				break;
			case 3:
				printf("h");
				break;
			case 4:
				printf("s");
				break;
			}
		}
		printf("\n");
	}
	return 0;
}
#include<stdio.h>
#include<string.h>

int main()
{
	char key[15], ch[45];
	while(scanf("%s%s", key, ch)!=EOF)
	{
		int i, count=0,t;
		for (i = 0; key[i]; i++)
		{
			for (count; ch[count]; count++)
			{
				if (ch[count] == key[i])//找到key
				{
					if (i == strlen(key) - 1)//如果i=最後一個key字母，另count=i
					{
						count = i;
						break;
					}
					count++;
					break;
				}
				else//key!=當前ch
				{
					for (t = i + 1; key[t]; t++)//判斷剩下的key有沒有==ch
						if (key[t] == ch[count])
						{
							printf("FAIL\n");
							i += 1000;//跳出外面2個迴圈
							count += 1000;
							break;
						}
				}
			}
			if (i == count&&i == strlen(key) - 1)//如果i是最後一個key且count=i PASS
				printf("PASS\n");
			else if (i == strlen(key)-1)//如果i是最後一個key且i!=count FAIL
				printf("FAIL\n");
		}
		memset(key, 0, sizeof(key));//reset
		memset(key, 0, sizeof(ch));
	}
    return 0;
}
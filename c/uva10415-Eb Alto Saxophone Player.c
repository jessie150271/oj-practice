/*uva10415-Eb Alto Saxophone Player*/
/*
題目輸入一個數字t和t個字串
統計每一個位置的按鈕總共被按了幾次
每首歌最多有200個音符
可以有空的歌(沒有音符輸入，所以要用gets)
用gets需解決第一次換行問題
*/
#include<stdio.h>
#include<stdlib.h>
char table[14][11] = {
	"12",/*0a 34*/
	"1",/*1b 2*/
	"1236789",/*2c 23478910*/
	"123678",/*3d 234789*/
	"12367",/*4e 23478*/
	"1236",/*5f 2347*/
	"123",/*6g 234*/
	"012",/*7A 123*/
	"01",/*8B 12*/
	"2",/*9C 3*/
	"0123678",/*10D 1234789*/
	"012367",/*11E 123478*/
	"01236",/*12F 12347*/
	"0123",/*13G 1234*/};
int num(char k)
{
	switch (k)
	{
	case 'a':case'b' : case'c' : case'd' : case'e' : case'f' : case'g' :
		return k - 'a';
		break;
	case 'A':case'B' : case'C' : case'D' :case 'E' :case 'F' : case'G' :
		return k - 'A'+7;/*大寫從table[7]開始*/
		break;
	}
}
int main()
{
	int t,end=0;
	scanf("%d", &t);
	while (end < t)
	{
		char mus[201] = { 0 };
		if (end == 0)
			getchar();/*用gets要解決先輸入t之後的換行問題*/
		gets(mus);/*用gets才會輸出空的song=0 0 0 ...*/
		int i,c;/*c用來當每次for的第一個變數*/
		int ans[10] = { 0 }, now_ary[10] = { 0 };/*ans=紀錄按幾次 now_ary紀錄當前(上個音符)按的位置*/
		for (i = 0; mus[i]; i++)
		{
			int new_ary[10] = {0};/*每個line的第i個字元所代表press的位置*/
			int code = num(mus[i]);/*把字元轉成應對table的數字*/
			for (c = 0; table[code][c]; c++)/*有按的位置=1*/
				new_ary[table[code][c]-'0']=1;
			for (c = 0; c < 10; c++)
			{/*原本沒按變成要按，按的次數ans++*/
				if (now_ary[c] == 0 && new_ary[c] == 1)
					ans[c]++;
				now_ary[c] = new_ary[c];/*更新now按的位置*/
			}
		}
		printf("%d", ans[0]);
		for (c = 1; c < 10; c++)
			printf(" %d", ans[c]);
		printf("\n");
		end++;
	}
    return 0;
}
// Name: B10401058 黃詩棋
// Date: April 6, 2017 
// Last Update: April 7, 2017
// Problem statement: CH09_02_Array to integer
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Atoi 
{
private:
	string beTrans;
	char sign;

public:
	Atoi();
	Atoi(string s);
	void SetString(string s);
	const string GetString();
	int Length();
	bool IsDigital();
	int StringToInteger();
};

Atoi::Atoi()
{
	beTrans = '0';
	sign = 0;
}

Atoi::Atoi(string s)
{
	if (s[0] == '-')
	{
		sign = '-';
		s.erase(s.begin());
	}
	else
		sign = 0;
	beTrans = s;
}

void Atoi::SetString(string s)
{
	if (s[0] == '-')
	{
		sign = '-';
		s.erase(s.begin());
	}
	beTrans = s;
}

const string Atoi::GetString()
{
	return sign + beTrans;
}

//check if beTrans is a digital
bool Atoi::IsDigital()
{
	for (int i = 0; i < beTrans.size(); i++)
	{
		if ((beTrans[i] > '9' || beTrans[i] < '0') && beTrans[i] != '-')
			return 0;
	}
	return 1;
}

//return beTrans's length
int Atoi::Length()
{
	return beTrans.size();
}

int Atoi::StringToInteger()
{
	int integerNum = 0;
	int count=0;
	for (int i = beTrans.size() - 1; i >= 0; i--)//從beTrans最後面開始轉換
	{
		integerNum += (beTrans[i] - '0')*pow(10, count++);
		//字元-'0'=數字 乘上位數加到integerNum中
	}

	return (sign == '-') ? -integerNum : integerNum;
}

//test main
int main(void) {
	string beTrans;
	while (cin >> beTrans) {
		Atoi atoi(beTrans + "20");
		if (atoi.IsDigital()) {
			cout << atoi.Length() << endl;
			cout << atoi.StringToInteger() << endl;
			cout << sizeof(atoi.StringToInteger()) << endl;
		}
		atoi.SetString(beTrans);
		if (atoi.IsDigital()) {
			cout << atoi.Length() << endl;
			cout << atoi.StringToInteger() << endl;
			cout << sizeof(atoi.StringToInteger()) << endl;
		}
	}
	return 0;
}
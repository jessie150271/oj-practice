#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct Ans
{
	int S;
	int x1;
	string b1;
	int x2;
	string b2;
};
int Check(string S)
{
	return equal(S.begin(), S.begin() + S.length() / 2, S.rbegin());
}
Ans ChangeNum(int S)
{
	Ans token;
	token.x1 = token.x2 = 0;
	string Str;
	stringstream ss;
	for (int i = 2; i <= 10; i++)
	{
		string Str;
		for (int num = S; num > 0; num /= i)
		{
			char StrToken;
			ss << num%i;
			ss >> StrToken;
			Str+=StrToken;
		}
		if (Check(Str)&&token.x1==0)
		{
			token.S = S;
			token.x1 = i;
			token.b1 = Str;
		}
		else if(Check(Str))
		{
			token.x2 = i;
			token.b2 = Str;
			return token;
		}
	}
	return token;
}
int main()
{
	int X;
	while (cin >> X)
	{
		stringstream ss;
		Ans token;
		for (X; X <= 1000000; X++)
		{
			int S = X;
			token = ChangeNum(S);
			if (token.x2 != 0)
			{
				cout << token.S << endl;
				cout<< token.x1 << " " << token.b1 << endl;
				cout<< token.x2 << " " << token.b2 << endl;
				break;
			}
			else if (X == 1000000)
				cout << "No answer." << endl;
		}
	}
    return 0;
}
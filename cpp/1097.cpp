#include<iostream>
#include<string>
using namespace std;

struct BigInt
{
	string Num;
};
BigInt Add(const BigInt &lhs, const BigInt &rhs)
{
	BigInt ans,token;
	int lenL = lhs.Num.length(), lenR = rhs.Num.length();
	if (lenR > lenL)
		ans = rhs, token = lhs;
	else
		ans = lhs, token = rhs;
	for (int i = token.Num.length() - 1, j = ans.Num.length()-1;j >= 0; i--, j--){
		if (i >= 0)
			ans.Num[j] += token.Num[i]-'0';
		if (ans.Num[j] > '9'){
			if (j == 0)
				cout << "1";
			else
				ans.Num[j - 1] += 1;
			ans.Num[j] -= 10;
		}
	}

	return ans;
}
int CheckInput(string input,int test)
{
	if (test)
		return 1;
	int len = input.length();
	for (int i = len - 1; i >= 0; i--)
		if (input[i]<'0' || input[i]>'9')
			return 1;
	return 0;
}
int main()
{
	int N;
	while (cin>>N)
	{
		while (N > 0)
		{
			BigInt a, b;
			cin >> a.Num >> b.Num;
			int lenA = a.Num.length(), lenB = b.Num.length();
			int test=0;
			test=CheckInput(a.Num,test);
			test=CheckInput(b.Num,test);
			if (test) {
				cout << "Not a valid number, please try again." << endl;
				N--;
				continue;
			}
			BigInt result = Add(a, b);
			cout << result.Num<<endl;

			N--;
		}
	}
    return 0;
}
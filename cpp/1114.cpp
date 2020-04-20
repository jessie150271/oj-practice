// Name: B10401058 黃詩棋
// Date: April 6, 2017 
// Last Update: April 6, 2017
// Problem statement:1114: 105物件導向程式設計實驗課04/06 Question1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Number
{
	string bigNum;
	bool sign;
};

class BigInt
{
public:
	BigInt();
	BigInt(string);
	string add(Number,Number);
	string sub(Number,Number);
	Number getNumber();

private:
	Number num;
};

BigInt::BigInt()
{
	num.bigNum = "0";
	num.sign = false;
}

BigInt::BigInt(string a)
{
	if (a[0] == '-')
	{
		num.sign = true;//-
		a.erase(a.begin());
	}
	else
		num.sign = false;//+
	num.bigNum = a;
}

Number BigInt::getNumber()
{
	return num;
}

string BigInt::add(Number A,Number B)
{
	Number ans, temp;
	int size1 = A.bigNum.size(), size2 = B.bigNum.size();
	if (A.sign && !B.sign)
	{
		A.sign = false;//-A→+A
		ans.bigNum = sub(B, A);
		return ans.bigNum;
	}
	else if (!A.sign && B.sign)
	{
		B.sign = false;//-B→+B
		ans.bigNum = sub(A, B);
		return ans.bigNum;
	}
	else
	{
		if (size1 >= size2)
		{
			ans = A;
			temp = B;
		}
		else
		{
			ans = B;
			temp = A;
		}
	}
	size1 = ans.bigNum.size();
	size2 = temp.bigNum.size();
	int i = size1-1, j = size2-1;
	for (i; i >= 0; i--,j--)
	{
		if (j >= 0)
			ans.bigNum[i] += temp.bigNum[j] - '0';
		if (ans.bigNum[i] > '9')
		{
			ans.bigNum[i] -= 10;
			if (i > 0)
				ans.bigNum[i - 1] += 1;
			else if (i == 0)
				ans.bigNum.insert(ans.bigNum.begin(), '1');
		}
	}
	if (ans.sign)
		return "-"+ ans.bigNum;
	else if (!ans.sign)
		return ans.bigNum;
}

string BigInt::sub(Number A,Number B)
{
	Number ans, temp;
	int token = 0;//紀錄位數相同時從頭算起第一個不同的數字
	int size1 = A.bigNum.size(), size2 = B.bigNum.size();
	if (A.sign&&!B.sign)//-A - B = -A + -B
	{
		B.sign = true;
		ans.bigNum = add(A, B);
		return ans.bigNum;
	}
	else if (!A.sign&&B.sign)//A - -B = A + B
	{
		B.sign = false;
		ans.bigNum = add(A, B);
		return ans.bigNum;
	}
	else if (A.sign&&B.sign)//-A - -B= -A + B = B-A
	{
		A.sign = B.sign = false;
		ans.bigNum = sub(B, A);
		return ans.bigNum;
	}
	else if (!A.sign && !B.sign)//A - B
	{
		if (size1 > size2)
		{
			ans = A;
			temp = B;
		}
		else if (size1 < size2)
		{
			ans = B;
			ans.sign = true;
			temp = A;
			size1 = ans.bigNum.size();
			size2 = temp.bigNum.size();
		}
		else if (size1 == size2)
		{
			for (int i = 0; i < size1; i++)
			{
				if (A.bigNum[i] > B.bigNum[i])
				{
					ans = A;
					temp = B;
					break;
				}
				else if (A.bigNum[i] < B.bigNum[i])
				{
					ans = B;
					temp = A;
					size1 = ans.bigNum.size();
					size2 = temp.bigNum.size();
					ans.sign = true;
					break;
				}
				else if (i == size1 - 1)
					return "0";
				token = i;
			}
		}
	}
	int i = size1 - 1, j = size2 - 1;
	for (i; i >= 0; i--, j--)
	{
		if (j >= 0)
			ans.bigNum[i] -= temp.bigNum[j] - '0';
		if (ans.bigNum[i] < '0')
		{
			ans.bigNum[i] += 10;
			if (i > 0)
				ans.bigNum[i - 1] -= 1;
		}
	}

	for (; ans.bigNum.size() > 1;)
	{
		if (ans.bigNum[0] == '0')
			ans.bigNum.erase(ans.bigNum.begin());
		else
			break;
	}
	if (ans.sign)
		return "-" + ans.bigNum;
	else if (!ans.sign)
		return ans.bigNum;
}

int main()
{
	string operation;
	while (cin >> operation)
	{
		if (operation == "Exit")
			return 0;
		else if (operation == "ADD")
		{
			string num1, num2;
			cin >> num1 >> num2;
			BigInt number1(num1), number2(num2);
			cout << number1.add(number1.getNumber(), number2.getNumber()) << endl;
		}
		else if (operation == "SUB")
		{
			string num1, num2;
			cin >> num1 >> num2;
			BigInt number1(num1), number2(num2);
			cout << number1.sub(number1.getNumber(), number2.getNumber()) << endl;
		}
	}

    return 0;
}
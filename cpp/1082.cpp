#include<iostream>
#include<string>
using namespace std;

struct COW
{
	string Num1;
	string Num2;
	string Ans;
};
string QuaNum(const string &num)
{
	string quaNumber;
	for (int i = 0; i < num.length(); i++)
	{
		switch (num[i])
		{
		case'V':
			quaNumber.push_back('0');
			break;
		case'U':
			quaNumber.push_back('1');
			break;
		case'C':
			quaNumber.push_back('2');
			break;
		case'D':
			quaNumber.push_back('3');
			break;
		}
	}
	return quaNumber;
}
void OA(COW &cow)
{
	COW QuaCow;
	bool carry = false;
	QuaCow.Num1 = QuaNum(cow.Num1);
	QuaCow.Num2 = QuaNum(cow.Num2);
	for (int i = QuaCow.Num1.length() - 1, j = QuaCow.Num2.length() - 1; j >= 0; i--, j--)
	{
		if (carry)
		{
			QuaCow.Num2[j] += 1;
			carry = false;
		}
		if(i>=0)
			QuaCow.Num2[j]+=QuaCow.Num1[i]- '0';
		if (QuaCow.Num2[j] >= '4')
		{
			QuaCow.Num2[j] -= 4;
			carry = true;
		}
	}
	if (carry)
		QuaCow.Num2.insert(0, "1");
	string ans;
	for (int i = 0; i < QuaCow.Num2.length(); i++)
	{
		switch (QuaCow.Num2[i])
		{
		case'0':
			ans.push_back('V');
			break;
		case'1':
			ans.push_back('U');
			break;
		case'2':
			ans.push_back('C');
			break;
		case'3':
			ans.push_back('D');
			break;
		}
	}
	cow.Ans = cow.Num2 = ans;
}
void OR(COW &cow)
{
	cow.Num2.pop_back();
	cow.Num2.insert(0, "V");
	cow.Ans = cow.Num2;
}
void OL(COW &cow)
{
	cow.Num2.push_back('V');
	cow.Ans = cow.Num2;
}
void Check(COW &cow)
{
	if (cow.Ans.length() < 8) {
		do {
			cow.Ans.insert(0, "V");
		} while (cow.Ans.length() < 8);
	}
}
int main()
{
	int N;
	cin >> N;
	cout << "COWCULATIONS OUTPUT" << endl;
	while (N--)
	{
		COW input;
		char Operat[3];
		cin >> input.Num1 >> input.Num2 >> Operat[0] >> Operat[1] >> Operat[2] >> input.Ans;
		COW output=input;
		for (int i = 0; i < 3; i++)
		{
			switch (Operat[i])
			{
			case'A':
				OA(output);
				break;
			case'R':
				OR(output);
				break;
			case'L':
				OL(output);
				break;
			case'N':
				break;
			}
		}
		Check(output);
		if (output.Ans == input.Ans)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	cout << "END OF OUTPUT" << endl;
    return 0;
}
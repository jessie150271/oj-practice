#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N;
	while (cin >> N)
	{
		vector<string>name,num1, num2;
		string ch,number1,number2;
		int token1 = 0, token2 = 0, token3 = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> ch >> number1 >> number2;
			name.push_back(ch);
			num1.push_back(number1);
			num2.push_back(number2);

			if (name[i].length()>token1)
				token1 = name[i].length();
			if (num1[i].length() > token2)
				token2 = num1[i].length();
			if (num2[i].length() > token3)
				token3 = num2[i].length();
		}
		for (int i = 0; i < N; i++)
		{
			cout << setw(token1) << name[i] << "|  " << setw(token2) << num1[i] << "|  " << setw(token3) << num2[i] << endl;
		}
	}
	return 0;
}
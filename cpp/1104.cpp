#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Input
{
public:
	void input();
	void split();
	int comput(int);
private:
	string str;
	vector<int> list;
};

int Input::comput(int ans)
{
	for (int i = 0; i < list.size(); i++)
		ans += list[i];
	return ans;
}

void Input::split()
{
	bool negative=false;
	string token;
	int nowNum , tempNum;//now乘除用 temp轉換用
	char lastOperator = '+';
	stringstream ss;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ') continue;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			token += str[i];
			if (i == str.size() - 1)
			{
				ss << token;
				ss >> tempNum;
				switch (lastOperator)
				{
				case '+':
					negative ? list.push_back(-tempNum) : list.push_back(tempNum);
					break;
				case '*':
					nowNum *= tempNum;
					negative ? list.push_back(-nowNum) : list.push_back(nowNum);
					break;
				case '/':
					nowNum /= tempNum;
					negative ? list.push_back(-nowNum) : list.push_back(nowNum);
					break;
				}
				break;
			}
			else continue;
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-' && !token.size())
			{
				negative = !negative;
				continue;
			}
			ss << token;
			ss >> tempNum;
			switch (lastOperator)
			{
			case '*':
				nowNum *= tempNum;
				negative ? list.push_back(-nowNum) : list.push_back(nowNum);
				break;
			case '/':
				nowNum /= tempNum;
				negative ? list.push_back(-nowNum) : list.push_back(nowNum);
				break;
			case '+':
				negative ? list.push_back(-tempNum) : list.push_back(tempNum);
				break;
			}
			negative = (str[i] == '-') ? true : false;
			lastOperator = '+';
			token.clear();
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			ss << token;
			ss >> tempNum;
			switch (lastOperator)
			{
			case '+':
				nowNum = tempNum;
				break;
			case '*':
				nowNum *= tempNum;
				break;
			case '/':
				nowNum /= tempNum;
				break;
			}
			lastOperator = str[i];
			token.clear();
		}
		ss.str("");
		ss.clear();
	}
}

void Input::input()
{
	getline(cin, str);
}

int main()
{
	int n;
	while (cin >> n)
	{
		cin.ignore();
		while (n--)
		{
			Input toComputAns;
			toComputAns.input();
			toComputAns.split();

			int ans = 0;
			ans = toComputAns.comput(ans);
			cout << ans << endl;
		}
	}
    return 0;
}
// Name: B10401058 黃詩棋
// Date: April 12, 2017 
// Last Update: April 12, 2017
// Problem statement: 1033 任意數學運算式由右至左輸出
//判別與轉換負號、利用堆疊將中序式轉成後序式、自訂負號優先順序與運算判斷
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
const int priority[] = { 3,2,1,0 };
//優先順序 括號-1(直到遇反括號才輸出) > 負號2 > 乘、除1 > 加、減0
//使用迴圈，取出中序式的字元，遇運算元直接輸出；堆疊運算子與左括號
//堆疊中運算子優先順序若大於等於讀入的運算子優先順序的話，直接輸出堆疊中的運算子，再將讀入的運算子置入堆疊；
//遇右括號輸出堆疊中的運算子至左括號。

class Math {
public:
	void setInput(const string&);
	void computInput();//運算
	void printAns();//輸出答案

private:
	string input;//存輸入字串(無空格，'!'代表負號)
	double ans;//存運算結果
	double strToDouble(const string&);//字串轉成double
};

void Math::setInput(const string& line) {
	istringstream ss(line);
	string in, temp;
	while (ss >> in)//消除空格
		temp += in;

	for (int i = 0; i < temp.size(); i++) {//將負號轉成'!'、忽略正號
		if (i != temp.size() - 1) {
			if ((!i && temp[i] == '-') || (temp[i] < '0' && temp[i] != ')' && temp[i + 1] == '-')) {
				if (i && temp[i] != '-' || (temp[i] < '0' && temp[i] != ')' && temp[i + 1] == '-'))
					input += temp[i++];
				input += '!';
				continue;
			}
		}
		input += temp[i];
	}
}

void Math::computInput() {
	vector<string> _operator, postfix;//堆疊
	vector<int> operatorPriority;
	int nowPriority;//存當前運算子優先順序
	for (int i = input.size() - 1; i >= 0; i--) {
		if (input[i] >= '0' || input[i] == '.') {//遇運算元直接輸出至 Postfix(後序式)
			string temp;
			int j = i;
			while (j >= 0 && (input[j] >= '0' || input[j] == '.')) {
				temp.insert(0, 1, input[j]);//數字由逆序轉成正序
				j--;
			}
			postfix.push_back(temp);
			i = j + 1;
		}
		else if (input[i] == '(') {//遇'('輸出stack中的operator至')'
			while (!_operator.empty()) {
				int top = _operator.size() - 1;
				if (_operator[top] == ")") {
					_operator.pop_back();
					operatorPriority.pop_back();
					break;
				}
				postfix.push_back(_operator[top]);
				_operator.pop_back();
				operatorPriority.pop_back();
			}
		}
		else {
			switch (input[i])
			{
			case ')':
				nowPriority = priority[0];//3
				break;
			case '!':
				nowPriority = priority[1];//2
				break;
			case '*':
				nowPriority = priority[2];//1
				break;
			case '/':
				nowPriority = priority[2];
				break;
			case '+':
				nowPriority = priority[3];//0
				break;
			case '-':
				nowPriority = priority[3];
				break;
			}
			//stack最上方運算子 >= 輸入運算子 輸出至postfix
			if (!operatorPriority.empty())
				while (operatorPriority[operatorPriority.size() - 1] != 3 && operatorPriority[operatorPriority.size() - 1] >= nowPriority) {
					postfix.push_back(_operator[_operator.size() - 1]);
					_operator.pop_back();
					operatorPriority.pop_back();
					if (operatorPriority.empty())
						break;
				}
			string operat;//堆疊operator
			operat = input[i];//char 轉存 string
			_operator.push_back(operat);
			operatorPriority.push_back(nowPriority);
		}
	}
	while (!(_operator.empty())) {
		postfix.push_back(_operator[_operator.size() - 1]);
		_operator.pop_back();
		operatorPriority.pop_back();
	}

	//運算後序式
	vector<double> stack;//堆疊
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i][0] < '0' && !stack.empty()) {

			if (postfix[i][0] == '!') {
				if (stack[stack.size() - 1] != 0)
					stack[stack.size() - 1] = -stack[stack.size() - 1];
			}
			else if (stack.size() >= 2) {
				switch (postfix[i][0])
				{
				case '+':
					stack[stack.size() - 2] += stack[stack.size() - 1];
					stack.pop_back();
					break;
				case '-':
					stack[stack.size() - 2] -= stack[stack.size() - 1];
					stack.pop_back();
					break;
				case '*':
					stack[stack.size() - 2] *= stack[stack.size() - 1];
					stack.pop_back();
					break;
				case '/':
					stack[stack.size() - 2] /= stack[stack.size() - 1];
					stack.pop_back();
					break;
				default:
					break;
				}
			}
		}
		else
			stack.push_back(strToDouble(postfix[i]));

		if (i == postfix.size() - 1)
			ans = stack[0];
	}
	//小數四捨五入至第三位
	long long temp = abs(10000 * ans);
	if (temp % 10 > 4)
		temp += 10;
	temp /= 10;
	if (ans < 0)
		ans = -(double)temp / 1000;
	else
		ans = (double)temp / 1000;
}

double Math::strToDouble(const string &str) {
	istringstream ss(str);
	double num;
	ss >> num;
	return num;
}

void Math::printAns() {
	cout << ans << endl;
}

int main() {
	string line;
	while (getline(cin, line)) {
		Math math;
		math.setInput(line);
		math.computInput();
		math.printAns();
	}
	return 0;
}
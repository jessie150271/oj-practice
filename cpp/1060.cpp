// Name: B10401058 黃詩棋
// Date: April 8, 2017 
// Last Update: April 8, 2017
// Problem statement: 1060 萬用陣列實作
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

class Array {
public:
	Array(int);
	void _char(int);
	void _short(int);
	void _int(int);
	void _longlong(int);
	void _double(int);
	string getAry(int);

private:
	vector<string> Ary;
};

Array::Array(int N) {
	vector<string> setAry(N, "0");
	Ary = setAry;
}

void Array::_char(int index) {
	string str(8,'0');
	int in;
	cin >> in;
	for (int i = 0; i < 8; i++) {
		if ((in >> i) & 1)
			str[7-i] = '1';
	}
	Ary[index] = str;
}

void Array::_short(int index) {
	string str(16, '0');
	short in;
	cin >> in;
	for (int i = 0; i < 16; i++) {
		if ((in >> i) & 1)
			str[15 - i] = '1';
	}
	Ary[index] = str;
}

void Array::_int(int index) {
	string str(32, '0');
	int in;
	cin >> in;
	for (int i = 0; i < 32; i++) {
		if ((in >> i) & 1)
			str[31 - i] = '1';
	}
	Ary[index] = str;
}

void Array::_longlong(int index) {
	string str(64, '0');
	long long in;
	cin >> in;
	for (int i = 0; i < 64; i++) {
		if ((in >> i) & 1)
			str[63 - i] = '1';
	}
	Ary[index] = str;
}

void Array::_double(int index) {
	string str(64, '0');
	double in;
	cin >> in;
	long long temp = *(long long*)∈
	for (int i = 0; i < 64; i++) {
		if ((temp >> i) & 1)
			str[63 - i] = '1';
	}
	Ary[index] = str;
}

string Array::getAry(int index) {
	return Ary[index];
}


int main(){
	int N, K, M, index;
	string _operator;
	while (cin>>N) {
		Array ary(N);
		cin >> K;
		while (K--) {
			cin >> index >> _operator;
			if (_operator == "char")
				ary._char(index);
			else if (_operator == "short")
				ary._short(index);
			else if (_operator == "int")
				ary._int(index);
			else if (_operator == "long") {
				cin >> _operator;
				ary._longlong(index);
			}
			else if (_operator == "double")
				ary._double(index);
		}
		cin >> M;
		while (M--) {
			cin >> index;
			cout << ary.getAry(index) << endl;
		}
	}
    return 0;
}
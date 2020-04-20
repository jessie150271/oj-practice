#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
#include<windows.h>
using namespace std;
class Data;

class Member {
	friend class Data;
private:
	string name;
	int att;
};

class Data {
private:
	vector<Member> member;
public:
	void input();
	void sort();
	void output();
};

void Data::input() {
	string in;
	bool flag;
	while (1) {
		flag = 1;
		cin >> in;
		if (in == "0")break;
		if (in[in.size() - 1] == ',') in.pop_back();
		for (int i = 0; i < member.size(); i++) {
			if (in == member[i].name) {
				member[i].att++;
				flag = 0;
				break;
			}
		}
		if (flag) {
			Member newMember;
			newMember.name = in;
			newMember.att = 1;
			member.push_back(newMember);
		}
	}
}

void Data::sort() {
	bool flag = 1;
	Member temp;
	for (int i = 0; i < member.size() && flag; i++) {
		flag = 0;
		for (int j = 0; j < member.size() - i - 1; j++) {
			if (member[j].att <= member[j + 1].att) {
				temp = member[j + 1];
				member[j + 1] = member[j];
				member[j] = temp;
				flag = 1;
			}
		}
	}
	flag = 1;
	for (int i = 0; i < member.size()&&flag; i++) {
		flag = 0;
		for (int j = 0; j < member.size() - i - 1; j++) {
			if (member[j].att > member[j + 1].att) {
				flag = 1;
				continue;
			}
			if (member[j].name.size() <= member[j + 1].name.size())	{
				temp = member[j + 1];
				member[j + 1] = member[j];
				member[j] = temp;
				flag = 1;
			}
		}
	}
}

void Data::output() {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int a = member[0].att;
	int count=0;

	SetConsoleTextAttribute(hConsole, 7);
	cout << "。---------------------。" << endl;
	for (int i = 0; i < member.size(); i++,count++) {
		if (a > member[i].att) {
			cout << "。---------------------。" << setw(3) << count << endl;
			a = member[i].att;
			count = 0;
		}

		cout << setw(2) << i + 1;
		SetConsoleTextAttribute(hConsole, 11);
		cout << setw(21) << member[i].name;
		SetConsoleTextAttribute(hConsole, 7);
		cout << " |";
		SetConsoleTextAttribute(hConsole, 14);
		cout << setw(3) << member[i].att << endl;
		SetConsoleTextAttribute(hConsole, 7);
	}
	cout << "。---------------------。" << setw(3) << count << endl;

	SetConsoleTextAttribute(hConsole, 7);
}

int main()
{
	while (1) {
		cout << "輸入資料,結束輸入時請輸入'0':" << endl;
		Data d;
		d.input();
		d.sort();
		d.output();
		string s;
		cout << "結束程式:1 輸入其他資料:2" << endl;
		cout << ":";
		cin >> s;
		if (s == "1")break;
		cout << endl;
	}
    return 0;
}
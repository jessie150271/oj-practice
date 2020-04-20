// Name: B10401058 黃詩棋
// Date: April 10, 2017 
// Last Update: April 10, 2017
// Problem statement: 1057
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;

class Memory {
public:
	void setSize(int);
	void typeChar(int);//1Byte
	void typeShort(int);//2Bytes
	void typeInt(int);//4Bytes
	void typeString(int);//輸入String時要自己補上null，輸出時如果找不到null結尾，請輸出至配置的記憶體最後一個位置
	void printMemoryValue(string, int);

private:
	vector<int> memoryArray;
};

void Memory::setSize(int N) {
	vector<int> set_size(N, 0);
	memoryArray = set_size;
}

void Memory::typeChar(int index) {
	int in;
	cin >> in;
	if (index > memoryArray.size() - 1) {
		cout << "Violation Access." << endl;
		return;
	}
	memoryArray[index] = (in & 255);
}

void Memory::typeShort(int index) {
	int in;
	cin >> in;
	if (index + 2 > memoryArray.size()) {
		cout << "Violation Access." << endl;
		return;
	}
	for (int i = 0; i < 2; i++) {
		memoryArray[index + i] = ((in >> 8 * i) & 255);
	}
}

void Memory::typeInt(int index) {
	int in;
	cin >> in;
	if (index + 4 > memoryArray.size()) {
		cout << "Violation Access." << endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		memoryArray[index + i] = ((in >> 8 * i) & 255);
	}
}

void Memory::typeString(int index) {
	string in;
	cin.ignore();//消除空白
	getline(cin, in);
	if (index + in.size() + 1 > memoryArray.size()) {
		cout << "Violation Access." << endl;
		return;
	}
	for (int i = index, j = 0; j < in.size(); i++, j++) {
		memoryArray[i] = (int)in[j];
	}
	memoryArray[index + in.size()] = 0;
}

void Memory::printMemoryValue(string type, int index) {
	//char
	if (type == "char") {
		if (index > memoryArray.size() - 1) {
			cout << "Violation Access." << endl;
			return;
		}
		int printChar = 0;
		if (memoryArray[index] > 127) {
			printChar -= 255 - memoryArray[index];
			printChar--;//2's補數+1還原
		}
		else
			printChar += memoryArray[index];
		cout << printChar << endl;
	}
	//short
	else if (type == "short") {
		if (index + 2 > memoryArray.size()) {
			cout << "Violation Access." << endl;
			return;
		}
		short printShort = 0;
		if (memoryArray[index + 1] > 127) {//負數
			printShort -= 255 - memoryArray[index];
			printShort -= (255 - memoryArray[index + 1]) * 256;
			printShort--;
		}
		else {
			printShort += memoryArray[index];
			printShort += memoryArray[index + 1] * 256;
		}
		cout << printShort << endl;
	}
	//int
	else if (type == "int") {
		if (index + 4 > memoryArray.size()) {
			cout << "Violation Access." << endl;
			return;
		}
		int printInt = 0;
		if (memoryArray[index + 3] > 127) {//負數
			for (int i = 0; i < 4; i++) {
				printInt -= (255 - memoryArray[index + i]) * pow(256, i);
			}
			printInt--;
		}
		else {
			for (int i = 0; i < 4; i++) {
				if (memoryArray[index + i] == '0')
					continue;
				printInt += memoryArray[index + i] * pow(256, i);
			}
		}
		cout << printInt << endl;
	}
	//String
	else if (type == "String") {
		if (index > memoryArray.size() - 1) {
			cout << "Violation Access." << endl;
			return;
		}
		for (int i = 0; index + i < memoryArray.size(); i++) {
			if (memoryArray[index + i] == 0) {
				cout << endl;
				return;
			}
			cout << (char)memoryArray[index + i];
		}
	}
}

int main() {
	int N, k;
	while (cin >> N >> k) {
		Memory memory;
		string line, operation, type;
		memory.setSize(N);
		int address;
		while (k--) {
			cin >> operation >> address >> type;
			if (operation == "Set") {
				if (type == "char")
					memory.typeChar(address);
				else if (type == "short")
					memory.typeShort(address);
				else if (type == "int")
					memory.typeInt(address);
				else if (type == "String")
					memory.typeString(address);
			}
			else if (operation == "Get") {
				memory.printMemoryValue(type, address);
			}
		}
	}
	return 0;
}
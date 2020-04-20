// Name: B10401058 黃詩棋
// Date: April 11, 2017 
// Last Update: April 11, 2017
// Problem statement: 1039
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
struct MemoryData {
	int index;
	int data[50];
};
int HEX[6] = { 10,11,12,13,14,15 };

int hexToDex(string str) {
	int num = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] <= '9')
			num += (str[i] - '0')*pow(16, str.size() - 1 - i);
		else
			num += (HEX[str[i] - 'A'])*pow(16, str.size() - 1 - i);
	}
	return num;
}

int main() {
	string memoryIndex, in;
	vector<MemoryData> memory;
	MemoryData input;
	bool flag = true;
	int N;
	while (cin >> memoryIndex) {
		if (memoryIndex == "EndMemDump")
			flag = false;
		else {
			N = 50;
			input.index = hexToDex(memoryIndex.assign(memoryIndex.begin() + 3, memoryIndex.end()));
			for (int i = 0; i < N && flag; i++) {
				cin >> in;
				in[0] = toupper(in[0]);
				in[1] = toupper(in[1]);
				input.data[i] = hexToDex(in);
			}
			memory.push_back(input);
		}
		if (!flag) {
			cin >> N;
			string indexStr, type;
			int index;
			while (N--) {
				cin >> indexStr >> type;
				if (type == "long")
					cin >> type;
				index = hexToDex(indexStr);
				for (int i = 0; i < memory.size(); i++) {
					if (memory[i].index <= index && index < memory[i].index + 50) {
						index -= memory[i].index;
						if (type == "int") {
							int output = 0;
							if (memory[i].data[index + 3] > 127) {
								for (int j = 0; j < 4; j++) {
									if (index + j >= 50) {
										i++;
										index = -j;
									}
									output -= (255 - memory[i].data[index + j]) * pow(256, j);
								}
								output--;
							}
							else {
								for (int j = 0; j < 4; j++) {
									if (index + j >= 50) {
										i++;
										index = -j;
									}
									output += memory[i].data[index + j] * pow(256, j);
								}
							}
							cout << output << endl;
						}
						else if (type == "long") {
							long long output = 0;
							if (memory[i].data[index + 7] > 127) {
								for (int j = 0; j < 8; j++) {
									if (index + j >= 50) {
										i++;
										index = -j;
									}
									output -= (255 - memory[i].data[index + j]) * pow(256, j);
								}
								output--;
							}
							else {
								for (int j = 0; j < 8; j++) {
										if (index + j >= 50) {
											i++;
											index = -j;
										}
										if (j < 4)
											output += memory[i].data[index + j] * pow(256, j);
										else
											output += (j - 4) * (long long)pow(256, j);
								}
							}
							cout << output << endl;
						}
						else if (type == "short") {
							short output = 0;
							if (memory[i].data[index + 1] > 127) {
								for (int j = 0; j < 2; j++) {
									if (index + j >= 50) {
										i++;
										index = -j;
									}
									output -= (255 - memory[i].data[index + j]) * pow(256, j);
								}
								output--;
							}
							else {
								for (int j = 0; j < 2; j++) {
									if (index + j >= 50) {
										i++;
										index = -j;
									}
									output += memory[i].data[index + j] * pow(256, j);
								}
							}
							cout << output << endl;
						}
						else if (type == "char") {
							cout << (char)memory[i].data[index] << endl;
						}
						else if (type == "String") {
							for (int j = 0;; j++) {
								if (index + j >= 50) {
									i++;
									index = -j;
								}
								if (memory[i].data[index + j] == 0)
									break;
								cout << (char)memory[i].data[index + j];
							}
							cout << endl;
						}
					}
				}
			}
			flag = true;
		}
	}
    return 0;
}
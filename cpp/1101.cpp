#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

struct Information
{
	char name[50];
	int score;
};
int main()
{
	vector<Information> inf;
	fstream fp;
	fp.open("scores.txt", ios::in);
	if (!fp.is_open()) {
		cout << "File fail to open";
		return 0;
	}
	int count = 0;
	do {
		Information buffer;
		stringstream ss;
		char StrScore[50];
		fp.getline(buffer.name, 50);
		fp.getline(StrScore, 50);
		ss << StrScore;
		ss >> buffer.score;
		inf.push_back(buffer);
		count++;
	} while (!fp.eof());
	fp.close();
	for (int i = 0; i < count; i++)
	{
		Information temp;
		for (int j = i; j < count; j++){
			if (inf[j].score > inf[i].score){
				temp = inf[i];
				inf[i] = inf[j];
				inf[j] = temp;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		cout << inf[i].name << endl;
		cout << inf[i].score << endl;
	}
	system("pause");
    return 0;
}
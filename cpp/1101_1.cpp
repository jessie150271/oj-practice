#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

void getHighScores(vector<string> &name, vector<int> &score)
{
	string tempN;
	int tempS;
	for (int i = 0; i < name.size(); i++)
		for (int j = i; j < name.size(); j++)
			if (score[j] > score[i]) {
				tempS = score[i];
				tempN = name[i];
				score[i] = score[j];
				name[i] = name[j];
				score[j] = tempS;
				name[j] = tempN;
			}
}
int main()
{
	vector<string> name;
	vector<int> score;
	fstream fp;

	fp.open("scores.txt", ios::in);
	if (!fp.is_open()) {
		cout << "File fail to open";
		return 0;
	}

	do {
		string NameBuffer, ScoreBuffer;
		stringstream ss;
		int Score;

		getline(fp, NameBuffer);
		name.push_back(NameBuffer);

		getline(fp, ScoreBuffer);
		ss << ScoreBuffer;
		ss >> Score;
		score.push_back(Score);
	} while (!fp.eof());

	getHighScores(name, score);

	for (int i = 0; i < 3; i++)
	{
		cout << name[i] << endl;
		cout << score[i] << endl;
	}
	fp.close();
	return 0;
}
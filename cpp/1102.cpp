#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<double> ary;
		double Average=0, SD = 0;
		for (int i = 0; i < n; i++)
		{
			double input;
			cin >> input;
			ary.push_back(input);
			Average += ary[i];
		}
		Average /= n;
		for (int i = 0; i < n; i++)
			SD += pow(ary[i] - Average, 2);
		SD = sqrt(SD / n);
		cout << "Average:" << Average << "\tStandard deviation:" << SD << endl;
	}
    return 0;
}
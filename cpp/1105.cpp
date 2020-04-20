#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	long double logB[33] = { 0 };
	for (int i = 1; i < 33; i++)
		logB[i] = log(2)*pow(2,i);
	int Y;
	while (cin >> Y)
	{
		Y = (Y - 1900) / 10 + 2;
		long long N = 3;
		long double logN = log(2)+log(1);
		do{
			logN += log(N++);
		} while (logN <= logB[Y]);
		cout << N - 2 << endl;
	}
    return 0;
}
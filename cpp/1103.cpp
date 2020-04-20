#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	
	cin >> n;
	bool t=false;
	while (n--)
	{
		if (t)
			cout << endl;

		vector<int> ansA,ansB;
		int X, count=0;
		cin >> X;
		int i, j;
		i=j= X * 2;
		for (j; j >= X + 1; j--)
		{
			for (i = X * 2; i <= X*(X + 1); i++)
			{
				if ((i + j)*X==i*j)
				{
					ansA.push_back(i);
					ansB.push_back(j);
					count++;
					break;
				}
				else
				{
					long long t1 = i*j;
					long long t2 = i*X;
					long long t3 = j*X;
					if(t1-t2>t3) break;
				}
			}
		}
		cout << count << endl;
		for (int i = 0; i < count; i++)
			cout << ansA[i] << " " << ansB[i] << endl;
		t = true;
	}
    return 0;
}
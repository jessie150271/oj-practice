#include <iostream>
using namespace std;

struct ret
{
	int sum, left, right;
};

ret findMax(const int* list, int len, bool pos)
{
	ret n;
	if (pos)
	{
		int self, sum;
		n.sum = -1;
		for (int i = 0; i < len; i++){
			self = sum = list[i];
			if (self > n.sum){
				n.sum = self;
				n.left = n.right = i;
			}
			for (int j = i + 1; j < len; j++){
				sum += list[j];
				if (sum > n.sum){
					n.sum = sum;
					n.left = i;
					n.right = j;
				}
			}
		}
	}
	else
	{
		int negMax = list[0];
		int index=0;

		for (int i = 0; i < len; i++)
			if (list[i] > negMax)
				index = i;

		n.left = n.right = index;
		n.sum = list[index];
	}
	return n;
}

int main()
{
	int input;
	while (cin >> input)
	{
		ret ans;
		int* list= new int[input];
		bool pos = false;
		int negMax;
		for (int i = 0; i < input; i++)
		{
			cin >> list[i];
			if (list[i]>0) pos = true;
		}

		ans = findMax(list, input, pos);

		cout << ans.left << ' ' << ans.right << ' ' << ans.sum << endl;
		delete(list);
	}
	return 0;
}
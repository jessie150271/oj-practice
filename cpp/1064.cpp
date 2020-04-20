// Name: B10401058 黃詩棋
// Date: April 7, 2017 
// Last Update: April 7, 2017
// Problem statement: 1064 迷宮
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
const int moveX[4] = { 0,0,1,-1 }, moveY[4] = { 1,-1,0,0 };

struct Record
{
	int x, y;
	vector<string> nowMap;
};

class Maze
{
public:
	void setMap(int);
	bool move();
	const int getMinMove();

private:
	int N;//mapSize
	int minMove;//initialize=0
	Record map;
};

void Maze::setMap(int size)
{
	N = size;
	bool findT = false;
	cin.ignore();//消除enter
	for (int i = 0; i < N; i++)
	{
		string line;
		getline(cin, line);
		map.nowMap.push_back(line);
		if (!findT)
		{
			for (int j = 0; j < N; j++)
			{
				if (line[j] == 'T')
				{
					map.x = i;
					map.y = j;
					findT = true;
					break;
				}
			}
		}
	}
	minMove = 0;//initialize
}

const int Maze::getMinMove()
{
	return minMove;
}

bool Maze::move()//x→col  y→row
{
	queue<int> queX, queY, queCount;
	queX.push(map.x), queY.push(map.y), queCount.push(0);
	bool flag = false;
	int newX, newY;
	while (!flag && !queX.empty())
	{
		for (int i = 0; i < 4; i++)
		{
			newX = queX.front() + moveX[i];
			newY = queY.front() + moveY[i];
			if (newX < 0 || newY < 0 || newX > N - 1 || newY > N - 1 || map.nowMap[newX][newY] == '*')//超界.碰到牆壁
				continue;
			queX.push(newX), queY.push(newY);//push新的可移動位置
			queCount.push(queCount.front() + 1);
			if (map.nowMap[newX][newY] == 'S')
			{
				minMove = queCount.back();//最先碰到S的que 其count必定最小
				flag = true;
				break;
			}
			map.nowMap[newX][newY] = '*';
		}
		queX.pop(), queY.pop(), queCount.pop();
	}

	if (minMove > 0) 
		return 1;
	return 0;
}

int main()
{
	int size;
	while (cin >> size)
	{
		Maze maze;
		maze.setMap(size);
		(maze.move()) ? cout << maze.getMinMove() << endl : cout << "No" << endl;
	}
	return 0;
}
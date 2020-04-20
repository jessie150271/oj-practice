//繪圖板
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define EXIT cout << "Out of range." << endl
#define widthlen width-1
struct Panel
{
	int x, y;
	bool **printer;
	bool check;
};
void DrawSquare(Panel &panel)
{
	int width,x,y;
	cin >> width >> x >> y;
	if (x + widthlen >= panel.x || y + widthlen >= panel.y) { EXIT; panel.check = false; return; }
	for (int i=x; i < x + width; i++)
		for (int j=y; j < y + width; j++)
			panel.printer[j][i] = true;
}
void DrawTriangle(Panel &panel)
{
	int x, y, width;
	string Direction;
	cin >> width >> x >> y >> Direction;
	if (x > panel.x || y > panel.y) { EXIT; panel.check = false; return; }
	if (Direction == "LU")//↗|
	{
		if (x < widthlen || y < widthlen) { EXIT; panel.check = false; return; }
		for (int w = width, j = y; w >0 ; w--, j--)
			for (int i = x-w+1; i <= x; i++)
				panel.printer[j][i] = true;
	}
	else if (Direction == "RU")//|↖
	{
		if (x + widthlen >= panel.x || y < widthlen) { EXIT; panel.check = false; return; }
		for (int w = width, j = y; w >0; w--, j--)
			for (int i = x + w - 1; i >= x; i--)
				panel.printer[j][i] = true;
	}
	else if (Direction == "LD")//↘|
	{
		if (x < widthlen || y + widthlen >= panel.y) { EXIT; panel.check = false; return; }
		for (int w = width, j = y; w >0; w--, j++)
			for (int i = x - w +1; i <= x; i++)
				panel.printer[j][i] = true;
	}
	else if (Direction == "RD")//|↙
	{
		if (x + widthlen >= panel.x || y + widthlen >= panel.y) { EXIT; panel.check = false; return; }
		for (int w = width, j = y; w >0; w--, j++)
			for (int i = x + w - 1; i >= x; i--)
				panel.printer[j][i] = true;
	}

}
void DrawLine(Panel &panel)
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if (x1 >= panel.x || x2 >= panel.x || y1 >= panel.y || y2 >= panel.y) { EXIT; panel.check = false; return; }
	if (x1 == x2) {
		if (y1 > y2)
		{
			int temp = y1;
			y1 = y2;
			y2 = temp;
		}
		for (int i = y1; i <= y2; i++)
			panel.printer[i][x1] = true;
	}
	else if (y1 == y2){
		if (x1 > x2)
		{
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		for (int i = x1; i <= x2; i++)
			panel.printer[y1][i] = true;
	}
	else
	{
		if (x1 < x2&&y1 < y2)     // ↘
		{
			for (int i = x1, j = y1; i <= x2, j <= y2; i++, j++)
				panel.printer[j][i] = true;
		}
		else if (x1 < x2&&y1 > y2)// ↗
		{
			for (int i = x1, j = y1; i <= x2, j >= y2; i++, j--)
				panel.printer[j][i] = true;
		}
		else if (x1 > x2&&y1 < y2)// ↙
		{
			for (int i = x1, j = y1; i >= x2, j <= y2; i--, j++)
				panel.printer[j][i] = true;
		}
		else if (x1 > x2&&y1 > y2)// ↖
		{
			for (int i = x1, j = y1; i >= x2, j >= y2; i--, j--)
				panel.printer[j][i] = true;
		}
	}
}
void Draw(Panel &panel)
{
	for (int i = 0; i < panel.y; i++) {
		for (int j = 0; j < panel.x; j++) {
			panel.printer[i][j] ? cout << "X" :
				cout << "*";
		}
		cout << endl;
	}
}
int main()
{
	Panel panel;
	cin >> panel.y >> panel.x;
	panel.printer = new bool*[panel.y];
	for (int i = 0; i < panel.y; i++)
	{
		panel.printer[i] = new bool[panel.x];
		for (int j = 0; j < panel.x; j++)
			panel.printer[i][j] = false;
	}
	string operat;
	bool t=false;
	while (cin>>operat)
	{
		if (operat == "EXIT")
			break;
		if (t)
			cout << endl;
		switch (operat[0])
		{
		case'S':
			DrawSquare(panel);
			break;
		case'T':
			DrawTriangle(panel);
			break;
		case'L':
			DrawLine(panel);
			break;
		}
		if (panel.check)
			Draw(panel);
		else if (!panel.check)
			panel.check = true;
		t = true;
	}
	for (int i = 0; i < panel.y; i++) delete panel.printer[i];
	delete panel.printer;
    return 0;
}
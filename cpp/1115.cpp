// Name: B10401058 黃詩棋
// Date: April 6, 2017 
// Last Update: April 6, 2017
// Problem statement:1115: 105物件導向程式設計實驗課04/06 Question2
#include<iostream>
#include<string>
#include<vector>
#include<sstream> //分割getline得到的字串
#include<algorithm> //sort
using namespace std;

struct PointArray
{
	string name;
	int **value;
	int size;
	int index;//存assign到一塊位於index的記憶體 -1=沒有指向任何多個Pointer共同指向的記憶體
};

struct MultiplePointArray
{
	int **value;
	int size;
	vector<string> name;//指向此記憶體的Pointer們
};

class Pointer
{
public:
	void create(string);
	void test(string);
	void destroy(string);
	void assign();
	void same();
	void at(string);
	void print(string);
	void who(string);

private:
	vector<PointArray> pointMember;
	vector<MultiplePointArray> multipleMember;
};

//set new pointer
void Pointer::create(string Name)
{
	PointArray newPointerMember;
	newPointerMember.name = Name;

	string inputStr;
	cin.ignore();
	getline(cin, inputStr);
	istringstream ss(inputStr);
	int V;
	vector<int> input;
	while (ss >> V)
	{
		input.push_back(V);
	}

	newPointerMember.size = input.size();
	newPointerMember.value = new int*[input.size()];
	for (int i = 0; i < input.size(); i++)
	{
		newPointerMember.value[i] = new int(input[i]);
	}
	newPointerMember.index = -1;
	pointMember.push_back(newPointerMember);
}

//test if Name is nullptr
void Pointer::test(string Name)
{
	for (int i = 0; i < pointMember.size(); i++)
	{
		if (pointMember[i].name == Name)
		{
			(*pointMember[i].value == nullptr) ? cout << 0 : cout << 1;
			cout << endl;
			return;
		}
	}
	cout << "Not Found" << endl;
}

//destroy the value of pointer
void Pointer::destroy(string Name)
{
	for (int i = 0; i < pointMember.size(); i++)
	{
		if (pointMember[i].name == Name)
		{
			if (*pointMember[i].value == nullptr)
				cout << "Null Pointer" << endl;
			else
			{
				//(沒有or只有一個)Pointer指向這塊記憶體
				if (pointMember[i].index == -1 || multipleMember[pointMember[i].index].name.size() == 1)
				{
					if (!multipleMember.empty()&&multipleMember[pointMember[i].index].name.size() == 1)
					{
						multipleMember[pointMember[i].index].name.clear();
						multipleMember[pointMember[i].index].size = 0;
					}
					cout << "Destroying Pointer(value=";
					cout << *pointMember[i].value[0];
					for (int j = 1; j < pointMember[i].size; j++)
					{
						cout << "," << *pointMember[i].value[j];
					}
					cout << ")" << endl;
					*pointMember[i].value = nullptr;
					pointMember[i].size = 0;
				}
				else if (pointMember[i].index >= 0)//有兩個或以上的Pointer指向這塊記憶體
				{
					for (int j = 0; j < multipleMember[pointMember[i].index].name.size(); j++)
					{
						if (multipleMember[pointMember[i].index].name[j]==pointMember[i].name)
						{
							multipleMember[pointMember[i].index].name.erase(multipleMember[pointMember[i].index].name.begin() + j);
							break;
						}
					}
					pointMember[i].index = -1;
					pointMember[i].size = 0;
					pointMember[i].value = nullptr;//不會銷毀原本只向的那塊記憶體
				}
			}
			return;
		}
	}
	cout << "Not Found" << endl;
}

//assign name1 to name2 (destroy name2 before assign)
void Pointer::assign()
{
	string name1, name2;
	cin >> name1 >> name2;
	if (name1 == "nullptr")
	{
		for (int i = 0; i < pointMember.size(); i++)
		{
			if (pointMember[i].name == name2)
			{
				destroy(name2);
				break;
			}
			else if (i == pointMember.size() - 1)
				cout << "Not Found" << endl;
		}
		return;
	}
	for (int i = 0; i < pointMember.size(); i++)
	{
		if (pointMember[i].name == name1)
		{
			for (int j = 0; j < pointMember.size(); j++)
			{
				if (pointMember[j].name == name2)
				{
					destroy(name2);
					if (pointMember[i].index == -1)//建立新的共同指標
					{
						MultiplePointArray newMultipelPoint;
						newMultipelPoint.value = pointMember[i].value;
						newMultipelPoint.size = pointMember[i].size;
						newMultipelPoint.name.push_back(pointMember[i].name);
						multipleMember.push_back(newMultipelPoint);
						pointMember[i].index = multipleMember.size()-1;//index=這塊記憶體在vector的位置
					}
					pointMember[j].index = pointMember[i].index;
					pointMember[j].size = pointMember[i].size;
					pointMember[j].value = pointMember[i].value;
					multipleMember[pointMember[i].index].name.push_back(pointMember[j].name);
					break;
				}
				else if (j == pointMember.size() - 1)
					cout << "Not Found" << endl;
			}
			break;
		}
		else if (i == pointMember.size() - 1)
			cout << "Not Found" << endl;
	}
}

//check if same between name1 and name2
void Pointer::same()
{
	string name1, name2;
	cin >> name1 >> name2;
	for (int i = 0; i < pointMember.size(); i++)
	{
		if (pointMember[i].name == name1)
		{
			for (int j = 0; j < pointMember.size(); j++)
			{
				if (pointMember[j].name == name2)
				{
					if (pointMember[j].value == pointMember[i].value)
						cout << 1 << endl;
					else
						cout << 0 << endl;
					break;
				}
				else if (j == pointMember.size() - 1)
					cout << "Not Found" << endl;
			}
			break;
		}
		else if (i == pointMember.size() - 1)
			cout << "Not Found" << endl;
	}
}

//set a newValue to Index of Name
void Pointer::at(string Name)
{
	int Index, NewValue;
	cin >> Index >> NewValue;
	for (int i = 0; i < pointMember.size(); i++)
	{
		if (pointMember[i].name == Name)
		{
			if (*pointMember[i].value == nullptr)
				cout << "Null Pointer" << endl;
			else if (Index < pointMember[i].size)
				*pointMember[i].value[Index] = NewValue;
			else
				cout << "Out Of Range" << endl;
			break;
		}
		else if (i == pointMember.size() - 1)
			cout << "Not Found" << endl;
	}
}

//print value of Name
void Pointer::print(string Name)
{
	for (int i = 0; i < pointMember.size(); i++)
	{
		if (pointMember[i].name == Name)
		{
			if (pointMember[i].size == 0)
				cout << "Null Pointer" << endl;
			else
			{
				cout << "(value=";
				cout << *pointMember[i].value[0];
				for (int j = 1; j < pointMember[i].size; j++)
				{
					cout << "," << *pointMember[i].value[j];
				}
				cout << ")" << endl;
			}
			break;
		}
		else if (i == pointMember.size() - 1)
			cout << "Not Found" << endl;
	}
}

//return who point the memory
void Pointer::who(string Name)
{
	for (int i = 0; i < pointMember.size(); i++)
	{
		if (pointMember[i].name == Name)
		{
			if (pointMember[i].index == -1)
				cout << pointMember[i].name << endl;
			else if (pointMember[i].index >= 0)
			{
				if(multipleMember[pointMember[i].index].name.size()==1)//只有一個Pointer指向此記憶體
					cout << pointMember[i].name << endl;
				else //有兩個或以上的Pointer指向此記憶體
				{
					sort(multipleMember[pointMember[i].index].name.begin(), multipleMember[pointMember[i].index].name.end());
					for (int j = multipleMember[pointMember[i].index].name.size() - 1; j >= 0; j--)
					{
						cout << multipleMember[pointMember[i].index].name[j] << endl;
					}
				}
			}
			break;
		}
		else if (i == pointMember.size() - 1)
			cout << "Not Found" << endl;
	}
}

int main()
{
	Pointer pointInt;
	string operation, Name;
	while (cin >> operation)
	{
		if (operation == "Exit")
		{
			return 0;
		}
		if (operation == "Create")
		{
			cin >> Name;
			pointInt.create(Name);
		}
		else if (operation == "Test")
		{
			cin >> Name;
			pointInt.test(Name);
		}
		else if (operation == "Destroy")
		{
			cin >> Name;
			pointInt.destroy(Name);
		}
		else if (operation == "Assign")
		{
			pointInt.assign();
		}
		else if (operation == "Same")
		{
			pointInt.same();
		}
		else if (operation == "At")
		{
			cin >> Name;
			pointInt.at(Name);
		}
		else if (operation == "Print")
		{
			cin >> Name;
			pointInt.print(Name);
		}
		else if (operation == "Who")
		{
			cin >> Name;
			pointInt.who(Name);
		}
	}
	return 0;
}
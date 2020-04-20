// Name: B10401058 黃詩棋
// Date: March 30, 2017 
// Last Update: March 30, 2017
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Pointer
{
public:
	void setName(string);
	void setValue();
	void destroy();
	string getName();
	int test();
	void print();
private:
	string name;
	int *value;
};

//set the poinert's name
void Pointer::setName(string Name)
{
	this->name = Name;
}

//set the pointer point value
void Pointer::setValue()
{
	int v;
	cin >> v;
	this->value = new int(v);
}

//get the pointer's name
string Pointer::getName()
{
	return this->name;
}

//destroy the value of pointer
void Pointer::destroy()
{
	if (value==nullptr)
		cout << "Null Pointer" << endl;
	else
	{
		cout << "Destroying Pointer(value=" << *this->value << ")" << endl;
		value = nullptr;
	}
}

int Pointer::test()
{
	if (value == nullptr)
		return 0;
	else
		return 1;
}

void Pointer::print()
{
	if (value == nullptr)
		cout << "Null Pointer" << endl;
	else
		cout << *this->value << endl;
}

int main()
{
	vector<Pointer> pointInt;
	string operation, Name;
	while (cin >> operation)
	{
		if (operation == "Exit")
		{
			return 0;
		}
		cin >> Name;
		if (operation == "Create")
		{
			Pointer inputPoint;
			inputPoint.setName(Name);
			inputPoint.setValue();
			pointInt.push_back(inputPoint);
		}
		else if (operation == "Destroy")
		{
			for (int i = 0; i < pointInt.size(); i++)
			{
				if (pointInt[i].getName() == Name)
				{
					pointInt[i].destroy();
					break;
				}
				else if (i == pointInt.size() - 1)
				{
					cout << "Not Found" << endl;
				}
			}
		}
		else if (operation == "Test")
		{
			for (int i = 0; i < pointInt.size(); i++)
			{
				if (pointInt[i].getName() == Name)
				{
					cout << pointInt[i].test() << endl;
					break;
				}
				else if (i == pointInt.size() - 1)
				{
					cout << "Not Found" << endl;
				}
			}
		}
		else if (operation == "Print")
		{
			for (int i = 0; i < pointInt.size(); i++)
			{
				if (pointInt[i].getName() == Name)
				{
					pointInt[i].print();
					break;
				}
				else if (i == pointInt.size() - 1)
				{
					cout << "Not Found" << endl;
				}
			}
		}
	}
	return 0;
}
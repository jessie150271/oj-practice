// Name: 1110: 105物件導向程式設計實驗課03/23 Question2
// Date: March 23, 2017 
// Last Update: March 23, 2017
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Student;

struct Course
{
	string courseName;
	int courseScore;
};

class StudentDataBuilder
{
public:
	static Student createStudentData(string name, string id);
};

class Student
{
public:
	Student(string name, string id) :studentName(name), studentID(id) {}
	string getStudentName();
	string getStudentID();
	void setCourse(string courseName, int courseScore);
	void removeCourse(string courseName);
	void modifyCourse(string courseName, int cousreScore);
	void print();
private:
	vector<Course> studentCourse;
	string studentName, studentID;
};

void Student::print()
{
	cout << studentName << endl << studentID << endl;
	for (int i = 0; i < studentCourse.size(); i++)
		cout << studentCourse[i].courseName << " " << studentCourse[i].courseScore << endl;
	cout << endl;
}

void Student::modifyCourse(string courseName, int cousreScore)
{
	if (studentCourse.size() == 0)
		cout << "Error" << endl;
	for (int i = 0; i < studentCourse.size(); i++)
	{
		if (studentCourse[i].courseName == courseName)
		{
			studentCourse[i].courseScore = cousreScore;
			break;
		}
		else if (i == studentCourse.size() - 1)
			cout << "Error" << endl;
	}
}

void Student::removeCourse(string courseName)
{
	if (studentCourse.size() == 0)
		cout << "Error" << endl;
	for (int i = 0; i < studentCourse.size(); i++)
	{
		if (studentCourse[i].courseName == courseName)
		{
			studentCourse.erase(studentCourse.begin() + i);
			break;
		}
		else if (i == studentCourse.size() - 1)
			cout << "Error" << endl;
	}
}

void Student::setCourse(string courseName, int courseScore)
{
	for (int i = 0; i < studentCourse.size(); i++)
	{
		if (studentCourse[i].courseName == courseName)
		{
			cout << "Error" << endl;
			return;
		}
	}
	Course newCourse;
	newCourse.courseName = courseName;
	newCourse.courseScore = courseScore;
	studentCourse.push_back(newCourse);
}

string Student::getStudentID()
{
	return studentID;
}

string Student::getStudentName()
{
	return studentName;
}

Student StudentDataBuilder::createStudentData(string name,string id)
{
	Student data(name, id);
	return data;
}

int main()
{
	string order;
	vector<Student> studentData;
	while (cin >> order)
	{
		if (order == "EXIT") break;
		else if (order == "AddStudent")
		{
			string line;
			string name, id;
			getline(cin, line);
			istringstream iss(line);
			while (iss>>name)
			{
				iss >> id;
				if (studentData.size() == 0)
					studentData.push_back(StudentDataBuilder::createStudentData(name, id));
				else
				{
					for (int i = 0; i < studentData.size(); i++)
					{
						if (studentData[i].getStudentName() == name || studentData[i].getStudentID() == id)
						{
							cout << "Error" << endl;
							break;
						}
						else if (i == studentData.size() - 1)
						{
							studentData.push_back(StudentDataBuilder::createStudentData(name, id));
							break;
						}
					}
				}
			}
		}
		else if (order == "AddCourse")
		{
			string line, str;
			cin >> str;
			getline(cin, line);
			string cName;
			int score;
			istringstream iss(line);
			while (iss >> cName)
			{
				iss >> score;
				if (studentData.size())
				{
					for (int i = 0; i < studentData.size(); i++)
					{
						if (studentData[i].getStudentName() == str || studentData[i].getStudentID() == str)
						{
							studentData[i].setCourse(cName, score);
							break;
						}
						else if (i == studentData.size() - 1)
							cout << "Error" << endl;
					}
				}
				else
					cout << "Error" << endl;
			}
		}
		else if (order == "RemoveStudent")
		{
			string line;
			getline(cin, line);
			istringstream iss(line);
			string str;
			while (iss >> str)
			{
				if (studentData.size())
				{
					for (int i = 0; i < studentData.size(); i++)
					{
						if (studentData[i].getStudentName() == str || studentData[i].getStudentID() == str)
						{
							studentData.erase(studentData.begin() + i);
							break;
						}
						else if (i == studentData.size() - 1)
							cout << "Error" << endl;
					}
				}
				else
					cout << "Error" << endl;
			}
		}
		else if (order == "RemoveCourse")
		{
			string line, str;
			cin >> str;
			getline(cin, line);
			string cName;
			istringstream iss(line);
			while (iss >> cName)
			{
				if (studentData.size())
				{
					for (int i = 0; i < studentData.size(); i++)
					{
						if (studentData[i].getStudentName() == str || studentData[i].getStudentID() == str)
						{
							studentData[i].removeCourse(cName);
							break;
						}
						else if (i == studentData.size() - 1)
							cout << "Error" << endl;
					}
				}
				else
					cout << "Error" << endl;
			}
		}
		else if (order == "ModifyCourse")
		{
			string line, str;
			cin >> str;
			getline(cin, line);
			string cName;
			int score;
			istringstream iss(line);
			while (iss>> cName)
			{
				iss >> score;
				if (studentData.size())
				{
					for (int i = 0; i < studentData.size(); i++)
					{
						if (studentData[i].getStudentName() == str || studentData[i].getStudentID() == str)
						{
							studentData[i].modifyCourse(cName, score);
							break;
						}
						else if (i == studentData.size() - 1)
							cout << "Error" << endl;
					}
				}
				else
					cout << "Error" << endl;
			}
		}
		else if (order == "Search")
		{
			string line;
			getline(cin, line);
			istringstream iss(line);
			string str;
			while (iss>>str)
			{
				if (studentData.size())
				{
					if (str == "All")
					{
						for (int i = 0; i < studentData.size(); i++)
							studentData[i].print();
					}
					else
					{
						if (studentData.size())
						{
							for (int i = 0; i < studentData.size(); i++)
							{
								if (studentData[i].getStudentName() == str || studentData[i].getStudentID() == str)
								{
									studentData[i].print();
									break;
								}
								else if (i == studentData.size() - 1)
									cout << "Error" << endl;
							}
						}
						else
							cout << "Error" << endl;
					}
				}
				else
					cout << "Error" << endl;
			}
		}
	}
	return 0;
}
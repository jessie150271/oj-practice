// Name: 1109: 黃詩棋
// Date: March 23, 2017 
// Last Update: March 23, 2017
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Course
{
	string courseName;
	int courseScore;
};

class Student
{
public:
	void setStudentName(string name, string ID);
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
	if (studentCourse.size()==0)
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

void Student::setStudentName(string name, string ID)
{
	studentName = name;
	studentID = ID;
}

int main()
{
	string order;
	Student student;
	while (cin >> order)
	{
		if (order == "EXIT") break;
		else if (order == "NewStudent")
		{
			string name, id;
			cin >> name >> id;
			student.setStudentName(name, id);
		}
		else if (order == "AddCourse")
		{
			string cName;
			int cScore;
			cin >> cName >> cScore;
			student.setCourse(cName, cScore);
		}
		else if (order == "RemoveCourse")
		{
			string rName;
			cin >> rName;
			student.removeCourse(rName);
		}
		else if (order == "ModifyCourse")
		{
			string mName;
			int mScore;
			cin >> mName >> mScore;
			student.modifyCourse(mName, mScore);
		}
		else if (order == "Print")
		{
			student.print();
		}
	}
    return 0;
}
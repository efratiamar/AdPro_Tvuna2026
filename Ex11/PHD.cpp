#include "PHD.h"
#include <iostream>
using namespace std;

PHD::PHD() :Student()
{
	resHours = 0;
}

PHD::PHD(const PHD& other) :Student(other)
{
	resHours = other.getResearchHours();
}

int PHD::getResearchHours() const
{ 
	return resHours;
}

void PHD::setResearchHours(int _num)
{ 
	resHours = _num;
}

bool PHD::milga() const
{ 
	return (Student::getNumberOfCourses() > 1 && resHours > 25);
}

void PHD::input(ifstream& fin)
{
	cout << "enter id, first name, last name, number of courses\n";
	//cin >> id >> fName >> lName >> countOfCourses;
	cout << "enter number of research hours:" << endl;
	//cin >> resHours;
	fin >> resHours;

}

void PHD::print() const
{
	cout << studType() << " student " << (milga() ? "*** Scholarship ***" : "") << endl;
	cout << "ID: " << id << "\n" << "Name: " << fName << " " << lName << endl;
	cout << "Number of research hours: " << resHours << endl;
}

string PHD::studType() const
{
	return "PhD";
}

bool PHD::operator<(const Student& other) const
{
	if (studType() != other.studType())
		throw "cannot compare students of different types";
	if (!milga() && other.milga())
		return true;
	if (milga() && !other.milga())
		return false;
	if (resHours < ((PHD*)&other)->getResearchHours())
		return true;
	return false;
}

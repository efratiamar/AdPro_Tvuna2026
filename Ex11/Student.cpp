#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(int _id, string _fName, string _lName, int _cnt)
{
	id = _id;
	fName = _fName;
	lName = _lName;
	countOfCourses = _cnt;
}

Student::Student(const Student& other)
{
	id = other.getId();
	fName = other.getFirstName();
	lName = other.getLastName();
	countOfCourses = other.getNumberOfCourses();
}

Student::~Student() {}

int Student::getId() const { return id; }

string Student::getFirstName() const { return fName; }

string Student::getLastName() const { return lName; }

int Student::getNumberOfCourses() const { return countOfCourses; }

void Student::setId(int _id) { id = _id; }

void Student::setFirstName(string _fn) { fName = _fn; }

void Student::setLastName(string _ln) { lName = _ln; }

void Student::setCountOfCourses(int num) { countOfCourses = num; }
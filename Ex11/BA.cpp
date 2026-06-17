#include "BA.h"
#include <iostream>
using namespace std;

BA::BA() :Student()
{
	grades = nullptr;
	size = 0;
}

BA::BA(const BA& other) :Student(other)
{
	size = other.getSize();
	grades = new int[size];
	for (int i = 0; i < size; i++)
		grades[i] = other.grades[i];
}

BA::~BA()
{
	if (grades)
		delete[] grades;
	grades = nullptr;
}


BA& BA::operator=(const BA& other)
{
	id = other.getId();
	fName = other.getFirstName();
	lName = other.getLastName();
	countOfCourses = other.getNumberOfCourses();
	size = other.getSize();
	grades = new int[size];
	for (int i = 0; i < size; i++)
		this->grades[i] = other.grades[i];
	return *this;
}

BA::BA(BA&& other)
{
	id = other.getId();
	fName = other.getFirstName();
	lName = other.getLastName();
	countOfCourses = other.getNumberOfCourses();
	size = other.getSize();
	grades = other.grades;
	other.grades = nullptr;
}

BA& BA::operator=(BA&& other)
{
	id = other.getId();
	fName = other.getFirstName();
	lName = other.getLastName();
	countOfCourses = other.getNumberOfCourses();
	size = other.getSize();
	grades = other.grades;
	other.grades = nullptr;
	return *this;
}


int* BA::getGrades() const
{
	int* pg = new int[size];
	if (!pg)
		exit(-1);
	for (int i = 0; i < size; i++)
		pg[i] = grades[i];
	return pg;
}

int BA::getSize() const { return size; }

void BA::setGrades(int* pg)
{
	if (Student::getNumberOfCourses() != 0)
		for (int i = 0; i < Student::getNumberOfCourses(); i++)
			grades[i] = pg[i];
}

void BA::setSize(int s)
{ 
	size = s;
}

bool BA::milga() const
{ 
	return Student::getNumberOfCourses() > 9 && average() > 95;
}

void BA::input(ifstream& fin)
{
	cout << "enter id, first name, last name, number of courses\n";
	//cin >> id >> fName >> lName >> countOfCourses;
	fin >> id >> fName >> lName >> countOfCourses;
	setSize(Student::getNumberOfCourses());
	grades = new int[size];
	if (!grades)
		exit(-1);
	cout << "and enter a list of student grades" << endl;
	for (int i = 0; i < size; i++)
		fin >> grades[i];
		//cin >> grades[i];
}

void BA::print() const
{
	//cout << studType() << " student " << (milga() ? "*** Scholarship ***" : "") << endl;
	//cout << "ID: " << id << "\n" << "Name: " << fName << " " << lName << endl;
	Student::print();
	cout << "Grades: ";
	for (int i = 0; i < size; i++)
		cout << grades[i] << " ";
	cout << endl;
	cout << "Average: " << average() << endl;
}

double BA::average() const
{
	double sum = 0;
	if (!size)
		return 0;
	for (int i = 0; i < size; i++)
		sum += grades[i];
	return sum / size;
}

string BA::studType() const
{
	return "BA";
}

bool BA::operator<(const Student& other) const
{
	if (studType() != other.studType())
		throw "cannot compare students of different types";
	if (!milga() && other.milga())
		return true;
	if (milga() && !other.milga())
		return false;
	if (average() < ((BA*)&other)->average())
		return true;
	return false;
}
#define _CRT_SECURE_NO_WARNINGS

#include "Student.h"
#include <iostream>
using namespace std;
#include <cstring>

void Student::setName(const char* n) //"David Cohen"
{
	strcpy(name, n);
}

char* Student::getName()
{
	return name;
}

void Student::setGrade(int g)
{
	if (g >= 1 && g <= 12)
		grade = g;
	else
		grade = -1;
}

int Student::getGrade()
{
	return grade;
}

void Student::inputMarks() //loop cin
{
	for (int i = 0; i < 10; i++)
	{
		cin >> marks[i];
		if (marks[i] < 0 || marks[i] > 100)
			marks[i] = 0;
	}
}

void Student::print() //name, grade, avg
{
	cout << "Name: " << name << " Grade: " << grade <<
		" Avg: " << computeAvg() << endl;
}

float  Student::computeAvg()
{
	float avg = 0;
	for (int  i = 0; i < 10; i++)
	{
		avg += marks[i];
	}

	return avg / 10;
}
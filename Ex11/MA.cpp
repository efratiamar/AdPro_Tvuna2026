#include "MA.h"
#include <iostream>
using namespace std;

MA::MA() :BA()
{
	isParticipant = false;
}

MA::MA(const MA& other) : BA(other)
{
	isParticipant = other.getIsParticipant();
}

bool MA::getIsParticipant() const
{ 
	return isParticipant;
}


void MA::setIsParticipant(bool isP)
{ 
	isParticipant = isP;
}

bool MA::milga() const
{ 
	return (Student::getNumberOfCourses() > 6 && average() > 90 && isParticipant);
}

void MA::input(ifstream& fin)
{
	BA::input(fin);
	cout << "enter 1 if the student does research and 0 if not" << endl;
	fin >> isParticipant;
	//cin >> isParticipant;
}

void MA::print() const
{
	BA::print();
	cout << "research: ";
	this->isParticipant ? cout << "YES" << endl : cout << "NO" << endl;
}

string MA::studType() const
{
	return "MA";
}

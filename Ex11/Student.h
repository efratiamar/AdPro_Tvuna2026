#pragma once
#include <string>
#include<fstream>
#include <iostream>
using namespace std;
//Ex 9 
class Student
{
protected:
	int id;
	string fName;
	string lName;
	int countOfCourses;
public:
	Student(int _id = 0, string _fName = "", string _lName = "", int _cnt = 0);
	Student(const Student& other);
	virtual ~Student();

	int getId() const;
	string getFirstName() const;
	string getLastName() const;
	int getNumberOfCourses() const;

	void setId(int _id);
	void setFirstName(string _fn);
	void setLastName(string _ln);
	void setCountOfCourses(int num);

	virtual void input(ifstream& fin) = 0;
	virtual void print() const = 0
	{
		//cout << studType() << " student " << (milga() ? "*** Scholarship ***" : "") << endl;
		cout << "ID: " << id << "\n" << "Name: " << fName << " " << lName << endl;
	};
	virtual bool milga() const = 0;
	virtual string studType() const = 0;
	virtual bool operator < (const Student& other) const = 0;
};

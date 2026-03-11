#pragma once

const int CNT = 4;

class Student
{
//private:
	char name[21];
	int grade;
	float marks[CNT];
	float computeAvg();
public:
	void setName(const char* n);
	char* getName();

	void setGrade(int g);
	int getGrade();

	void inputMarks(); //loop cin 

	void print();

};

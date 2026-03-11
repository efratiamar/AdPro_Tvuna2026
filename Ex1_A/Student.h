#pragma once

class Student
{
private:
	char name[21];
	int grade;
	float marks[10];
	float computeAvg();
public:
	void setName(const char* n);
	char* getName();
	void setGrade(int g);
	int getGrade();

	void inputMarks(); //loop cin

	void print(); //name, grade, avg

};
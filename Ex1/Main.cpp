#include "Student.h"
#include <iostream>
using namespace std;

const int SIZE = 3;

int main()
{
	//Student s1;
	//s1.setName("David Cohen");
	//cout << s1.getName() << endl;
	//s1.setGrade(4);
	//s1.inputMarks();

	//Student s2;
	//char na[12] = { 'M','o','s','h','e','\0'};
	//s2.setName(na);


	Student arr[SIZE];

	//input loop
	for (int i = 0; i < SIZE; i++)
	{
		int g;
		char n[21];
		cout << "Enter name and grade for student " << i + 1 << ":" << endl;
		cin >> n >> g;

		arr[i].setName(n);
		arr[i].setGrade(g);

		cout << "Enter 10 grades for student " << i + 1 << ":" << endl;
		arr[i].inputMarks();
	}

	//output loop
	for (int i = 0; i < SIZE; i++)
	{
		arr[i].print();
	}



}
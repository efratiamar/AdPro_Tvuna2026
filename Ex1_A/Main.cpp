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
		cout << "Enter name and grade for student " << i + 1 << ":" << endl;
		
		char n[21];
		cin.getline(n, 21);
		arr[i].setName(n);

		int g;
		cin >> g;
		arr[i].setGrade(g);

		arr[i].inputMarks();

		// This clears the newline character so the next getline works!
		cin.ignore(1000, '\n');
	}

	//output loop
	for (int i = 0; i < SIZE; i++)
	{
		arr[i].print();
	}



}
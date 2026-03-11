#include <iostream>
using namespace std;

#include "Student.h"

const int SIZE = 2;

int main()
{
	//Student s1;
	////char a[10] = { 'A', 'n', '\0' };
	////s1.setName(a);

	//s1.setName("David Cohen");
	//cout << s1.getName() << endl;
	
	//s1.setGrade(5);
	//cout << s1.getGrade() << endl;

	//s1.inputMarks();

	//s1.print();


	Student arr[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Enter name and grade for student " << i+1 << ":" << endl;

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

	for (int i = 0; i < SIZE; i++)
	{
		arr[i].print();
	}

}
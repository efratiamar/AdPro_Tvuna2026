#include "Vector.h"
#include <iostream>
#include <fstream> //Ex5
using namespace std;
#include <time.h>

int Ex5()
{
	string fileName;
	cout << "enter a file name";
	cin >> fileName; //numbers.txt

	ifstream fin(fileName);
	if (!fin) {
		cout << "cannot open the file";
		return -1;
	}
	
	int num;
	Vector v1;
	fin >> num;
	while (!fin.eof())
	{
		v1.addLast(num);
		fin >> num;
	}
	fin.close();
	
	v1.sort();

	ofstream fout(fileName); //numbers.txt
	if (!fout) {
		cout << "cannot open the file";
		return -1;
	}
	fout << v1;
	fout.close();

	return 0;
}

int main()
{
	//Ex3();
	Ex5();
}


void Ex3()
{
	srand(time(nullptr));
	
	Vector v1(7);

	for (int i = 0; i < 10; i++)
	{
		v1.addLast(rand() % 100);
	}
	
	v1.print();
	cout << v1.at(3) << endl;
	cout << v1.removeLast() << endl;
	cout << v1.lastValue() << endl;

	v1.print();

	v1.sort();

	v1.print();

	v1.clear();
	v1.print();

	cout << v1; 

	cin >> v1;
}

/*
Vector is full
Vector is full
Vector is full
35 64 93 61 24 10 1
61
1
10
35 64 93 61 24 10
10 24 35 61 64 93
*/
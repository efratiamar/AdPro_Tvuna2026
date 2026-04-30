#include <iostream>
#include <fstream>
using namespace std;

#include "Point.h"
#include "Circle.h"


int sample9()
{

	// option A
	ofstream fout;
	fout.open("points.txt");

	// option B
	//ofstream fout("points.txt");

	// option C
	//fstream fout;
	//fout.open("points.txt",ios::out);

	if (!fout)
	{
		cout << "failed opening file.\n";
		return -1;
	}

	for (int i = 0; i < 10; i++)
	{
		Point p(rand() % 100, rand() % 100);
		cout << p << endl; //to screen: (5,7)
		fout << p << endl; //to file: (5,7)
	}
	fout.close();
	return 0;
}

int sample10()
{
	ifstream fin;
	fin.open("points.txt");

	ofstream fout;
	fout.open("inCircle.txt");
	if (!fin || !fout)
	{
		cout << "failed opening file.\n";
		return -1;
	}

	Circle A;
	cout << "enter a circle (radius and center point )\n";
	cin >> A;
	Point p;
	for (int i = 0; i < 10; i++)
	{
		fin >> p;
		if (A.checkPointInOutOn(p) < 0)
			fout << p << endl;
	}
	fin.close();
	fout.close();

	return 0;
}


int main()
{
	//sample9();
	sample10();
}

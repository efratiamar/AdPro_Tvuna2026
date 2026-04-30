//1
#include <iostream>
#include <fstream>
using namespace std;

int main2()
{
	ofstream myFile;
	myFile.open("grades.txt");
	if (!myFile)
	{
		cout << "File could not be opened.\n";
		return -1;
	}

	int tz;
	float grade;
	for (int i = 0; i < 10; i++)
	{
		cout << "enter a tz and grade";
		cin >> tz >> grade;
		myFile << tz << '\t' << grade << endl;
	}
	myFile.close();
	return 0;
}

#include "Vector.h"
#include <iostream>
using namespace std;
#include <time.h>

int main()
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
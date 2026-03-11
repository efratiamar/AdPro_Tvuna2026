#include <iostream>
using namespace std;

#include "Rect.h"

//void printArea2(int leng, int wid)
//{
//	cout << "Area: " << leng * wid << endl;
//
//	Rect r;
//	r.length = 9;
//	//..
//}


int main()
{
	//printArea2(4,6);

	int length1 = 9;

	Rect r1;
	//r1.length = -4;
	r1.setLength(-4);
	//r1.width = 8;
	r1.setWidth(8);

	//cout << r1.length << endl;
	cout << r1.getLength() << endl;
	cout << r1.getWidth() << endl;

	r1.printArea(); // Area: 32

	Rect r2;
	//r2.length = 4;
	//r2.width = 3;
	//r2.printArea(); //Area: 12

	

	//Rect* pR2 = new Rect;

	//pR2->length;


}


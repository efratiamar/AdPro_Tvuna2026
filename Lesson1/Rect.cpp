#include <iostream>
using namespace std;

#include "Rect.h"

void Rect::printArea()
{
	cout << "Area: " << length * width << endl;
}

void Rect::setLength(int l)
{
	if (l >= 0)
		length = l;
	else
		length = 10;
}

int Rect::getLength() { return length; }

void Rect::setWidth(int w)
{
	if (w >= 0)
		length = w;
	else
		length = 10;
}

int Rect::getWidth() { return width; }
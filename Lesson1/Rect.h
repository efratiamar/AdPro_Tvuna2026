#pragma once

class Rect
{
private:
	int length;
	int width;
public:
	//A:
	//void printArea() { cout << "Area: " << length * width << endl; };

	//B:
	void printArea();
	void setLength(int l);
	int getLength();
	void setWidth(int w);
	int getWidth();
};

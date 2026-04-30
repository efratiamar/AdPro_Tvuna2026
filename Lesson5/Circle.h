#pragma once
#include "Point.h"

class Circle
{ 
	Point center; //x, y
	float radius;
public:
	//Circle();
	Circle(float r = 1);
	Circle(float r, const Point& other);
	Circle(float r, float x, float y);

	void setRadius(float r);
	void setCenter(const Point& other);

	int checkPointInOutOn(const Point& other) const;

	float area() const;
	float perimeter() const;

	friend ostream& operator<<(ostream& os, const Circle& c);
	friend istream& operator>>(istream& is, Circle& c);

};

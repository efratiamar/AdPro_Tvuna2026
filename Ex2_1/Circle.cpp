#include "Circle.h"

const float PI = 3.14;

//Circle::Circle()
//	: radius(1), center()
//{ }

Circle::Circle(float r) //r=1
	: radius(r), center()
{}

Circle::Circle(float r, const Point & other)
	:radius(r), center(other) //copy ctor of Point
{
}

Circle::Circle(float r, float x, float y)
	:radius(r)//, center(x,y) - NO, need another ctor of point!!
{
	center.setX(x); //center.x - NO!!!
	center.setY(y);
}

void Circle::setRadius(float r)
{
	radius = r;
}

void Circle::setCenter(const Point& other)
{
	center.setX(other.getX());
	center.setY(other.getY());
}

int Circle::checkPointInOutOn(const Point& other) const
{
	//distance between center and p1
	float d = center.distance(other);
	if (d == radius)
		return 0;
	if (d < radius)
		return -1;
	return 1;
}

float Circle::area() const
{
	return PI * radius * radius;
}

float Circle::perimeter() const
{
	return 2 * PI * radius;
}



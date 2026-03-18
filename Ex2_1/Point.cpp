#include "Point.h"
#include <cmath>

Point::Point() : x(0), y(0)
{
};

Point::Point(const Point& other)
	: x(other.x), y (other.y)
{
	//x = other.x;
	//y = other.y;
}

float Point::getX() const
{
	return x;
}

void Point::setX(float _x)
{
	x = _x;
}

float Point::getY() const
{
	return y;
}

void Point::setY(float _y)
{
	y = _y;
}

float Point::distance(const Point& other) const
{
	float dx = x - other.x;
	float dy = y - other.y;
	return sqrt(dx * dx + dy * dy);
}

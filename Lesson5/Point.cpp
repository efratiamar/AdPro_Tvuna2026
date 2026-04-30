#include "Point.h"
#include<cmath>

Point::Point(int _x, int _y) :x(_x), y(_y)
{
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

bool Point::operator!=(Point p)
{
	return x != p.x || y != p.y;
}

//Point p(5, 6);
//cout << p; //(5,6)
ostream& operator<<(ostream& os, const Point& p)
{
	os << '(' << p.x << ',' << p.y << ')';
	return os;
}

//cin >> p; //(4,5)
istream& operator>>(istream& is, Point& p)
{
	char ch;
	is >> ch >> p.x >> ch >> p.y >> ch;
	return is;
}

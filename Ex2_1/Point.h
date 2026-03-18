#pragma once

class Point
{
	float x = 0;
	float y = 0;
public:
	Point();
	Point(const Point& other);
	float getX() const;
	void setX(float _x);

	float getY() const;
	void setY(float _y);

	float distance(const Point& p1) const;


};


#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0);

	float getX() const;
	void setX(float _x);

	float getY() const;
	void setY(float _y);

	float distance(const Point& p1) const;


	bool operator!=(Point p);

	friend ostream& operator<<(ostream& os, const Point& p); //cout << p
	
	friend istream& operator>>(istream& is, Point& p );//cin >> p;


	friend class Circle;
};



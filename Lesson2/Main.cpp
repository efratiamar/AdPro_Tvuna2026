#pragma once
#include <iostream>
using namespace std;

void func() //NO! const
{
	cout << "Hi";

}

class Rational
{
private:
	int numerator = 1;
	int denominator = 1;
public:

	Rational(int n, int d)
		: numerator(n), denominator(d)
	{
		if (denominator == 0)
			denominator = 1;
	}

	void setNum(int n) 
	{
		numerator = n;
	}

	int getNum() const
	{
		int x = 6;
		x = 7;
		return numerator;
	}


	void print() const
	{
		//numerator = 5;
		int x;
		x = 8;
		cout << numerator << '/' << denominator << '\n';
	}
};


int main()
{
	Rational r(8,9);

}

 
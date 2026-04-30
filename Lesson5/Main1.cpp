#include <iostream>
using namespace std;

class Rational
{
	int mone;
	int mechane;
public:
	Rational(int mo=1, int me=1) : mone(mo), mechane(me) {};

	friend ostream& operator<<(ostream& os, const Rational& r);
	friend istream& operator>>(istream& is, Rational& r);

};

ostream& operator<<(ostream& os, const Rational& r)
{
	os << r.mone << '/' << r.mechane;
	return os;
}

istream& operator>>(istream& is, Rational& r)
{
	char slash;
	is >> r.mone >> slash >> r.mechane; //3/7
	return is;
}

int main1()
{
	int x = 9;
	cout << 4 << "sdfdf" << x;

	Rational r1(4, 5);

	cout << r1 << " " << 67; //4/5

	//cout << r1.getMone() << '/' << r1.getMechane();
	
	cin >> x;

	Rational r2;
	cin >> r2 >> x; //5/8

	return 0;



}
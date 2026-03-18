#include <iostream>
using namespace std;

//#include "Point.h"
#include "Circle.h"

int main()
{
    Point point;
    Circle A;
    Circle B(5);
    Circle C(3, point);
    Circle D(4, 2, 2);
    Circle E(D);


    Point p2;
    p2.setX(3);
    p2.setY(4);
    cout << "testing point" << endl;
    cout << "(" << p2.getX() << "," << p2.getY() << ")" << endl;

    A.setRadius(2);
    A.setCenter(p2);
    cout << A.area() << endl;
    cout << A.perimeter() << endl;

    int count = 0;


    char lParen, comma, rParen;	/*	( , )	*/
    float x, y;
    int inA = 0, outA = 0, onA = 0;
    cout << "enter points until(0, 0) :\n";
    Point p;
    cin >> lParen >> x >> comma >> y >> rParen;
    while (x || y)
    {
        p.setX(x);
        p.setY(y);
        if (A.checkPointInOutOn(p) < 0)
            inA++;
        if (A.checkPointInOutOn(p) > 0)
            outA++;
        if (A.checkPointInOutOn(p) == 0)
            onA++;
        cin >> lParen >> x >> comma >> y >> rParen;
    }
    cout << "num of points in circle :" << endl;
    cout << "A:" << inA << '\t';


    cout << count << endl;
    return 0;
}


//int main()
//{
	//Point p1;
	//p1.setX(5);
	//p1.setY(6);

	//Circle c1;

	//Circle c2(4);


	//Circle c3(5, p1);

	//Circle c4(6.7, 8.4, 9.9);

	//int ans = c4.checkPointInOutOn(p1);

	//cout << ans << endl;

//}
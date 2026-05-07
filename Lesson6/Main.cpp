#include <iostream>
#include <fstream>
using namespace std;


class Point
{
private:
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y (_y){};
	//bool operator!=(Point p);

	friend ostream& operator<<(ostream& os, const Point& p);
	friend istream& operator>>(istream& is, Point& p);
};


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

struct Worker
{
	long id;
	char name[15];
	float hours;
	float salary;
};

int readWriteBin()
{
	ofstream f1;
	f1.open("workers.bin"); //if (!f1) …
	Worker  worker1;
	for (int i = 0; i < 3; i++)
	{
		cout << "enter workers name ";
		cin >> worker1.name;
		cout << "enter " << worker1.name << "'s id ";
		cin >> worker1.id;
		cout << "enter number of hours ";
		cin >> worker1.hours;
		cout << "enter a salary per hour ";
		cin >> worker1.salary;

		f1.write((char*)&worker1, sizeof(Worker));
	}
	f1.close();

	ifstream f2("workers.bin"); //if (!f1) …
	f2.read((char*)&worker1, sizeof(Worker));

	while (!f2.eof())
	{
		cout << worker1.name << worker1.id << worker1.hours << worker1.salary << endl;
		f2.read((char*)&worker1, sizeof(Worker));

	}

	f2.close();
	return 0;
}

int BinaryFileSequential_3()
{
	ofstream f;
	f.open("points.bin");
	if (!f)
	{
		cout << "failed opening file.\n";
		return -1;
	}

	for (int i = 0; i < 10; i++)
	{
		Point p(rand() % 100, rand() % 100);
		cout << p << endl; //(5,6)
		f.write((char*)&p, sizeof(Point)); //01010101010101010...
	}
	f.close();
	return 0;
}

int main()
{
	//readWriteBin();
	BinaryFileSequential_3();
}

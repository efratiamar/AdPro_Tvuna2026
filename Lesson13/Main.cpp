#include <iostream>
#include <string>
using namespace std;

template <class T>

T isCondition(T arr[], int size, bool (*func) (T))
{ 
	for (int i = 0; i < size; i++)
	{
		if (func(arr[i])) //if ((*func)(arr[i]))
			return arr[i];
	}

	return arr[size - 1];
}

template <class T>
void update(T arr[], int size, T elem)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == elem)
			arr[i] = elem;
	}
}

class Student
{
	int ID;
	string name;
	int mark;
public:
	Student(int id, string name, int mark)
	{
		this->ID = id; this->name = name; this->mark = mark;
	}

	bool operator==(const Student& other) const
	{
		return name == other.name;
	}
};

template <class T> T* MyFunc(T* in)
{
	T* p = new T;
	*p = 100 - *in;
	return p;
}

class MyClass
{
	int n;
public:
	MyClass(int _n = 0) : n(_n) {};

	MyClass operator-(int _n);
	friend MyClass operator-(int _n, const MyClass& other);
};

MyClass MyClass::operator-(int _n)
{
	MyClass mc(n - _n);
	return mc;
}


MyClass operator-(int _n, const MyClass& other )
{
	MyClass mc(_n - other.n);
	return mc;
}

bool isEven(int x) { return x % 2 == 0; };

main()
{
	int a[3] = { 1,2,3 };
	int y = isCondition<int>(a, 3, isEven);
	y = isCondition<int>(a, 3, [](int x) { return x % 2 == 0; });

	Student S[] = { Student(1,"Uri",70),Student(2,"Mira",95),Student(3,"Rami",99) };
	Student X(8, "Mira", 95);
	update<Student>(S, 3, X); //update(S, 3, X);


	MyClass ptr1(500);
	MyClass* ptr2 = MyFunc<MyClass>(&ptr1);
	if (ptr2) delete ptr2;
}

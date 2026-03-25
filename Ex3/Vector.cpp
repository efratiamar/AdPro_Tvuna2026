#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector(int cap) //ctor
{
	capacity = cap;
	size = 0;
	vec = new int[capacity];
}

Vector::Vector(const Vector& v) //copy ctor
{
	capacity = v.capacity;
	size = v.size;
	vec = new int[capacity]; //deep
	for (int i = 0; i < size ; i++)
	{
		vec[i] = v.vec[i];
	}
}

Vector::Vector(Vector&& v) //move ctor
{
	capacity = v.capacity;
	size = v.size;
	vec = v.vec; //shallow
	v.vec = nullptr; //must! for the dtor

}

Vector::~Vector() //dtor
{
	if (vec) //must! for the move ctor
		delete[] vec;
	vec = nullptr; //optional
}

int Vector::getSize() const
{
	return size;
}

bool Vector::isEmpty() const
{
	return size == 0;
}

void Vector::addLast(int k)
{
	if (size == capacity)
		cout << "Vector is full\n";
	else
		vec[size++] = k;
}

int Vector::lastValue() const
{
	if (!isEmpty())
		return vec[size - 1];
	return -999;
}

int Vector::removeLast()
{
	if (!isEmpty())
		size--;
	return vec[size];
}

void Vector::clear()
{
	size = 0;
}

int Vector::at(int i) const
{
	return vec[i];
}

void  Vector::print() const
{
	for (int i = 0; i < size; i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

void Vector::sort()
{
	for (int i = 1; i < size; i++)
	{
		int key = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}
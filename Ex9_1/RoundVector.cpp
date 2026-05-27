#include "RoundVector.h"
#include<iostream>
using namespace std;

RoundVector::RoundVector(int _capacity)
{
	capacity = _capacity; 
	vec = new int[capacity + 1];//one extra place (to distinguish between the case of full vector and empty vector)
	head = 0;
	tail = 0;
	cout << "in constructor" << endl;
}

RoundVector::RoundVector(const RoundVector& v)
{
	capacity = v.capacity;
	vec = new int[capacity + 1];
	head = v.head;
	tail = v.tail;
	cout << "in copy constructor" << endl;
	
	for (int i = v.head; i != tail; i = (i+1) % (capacity + 1))
		vec[i] = v.vec[i];
}

RoundVector::RoundVector(RoundVector&& v)
{
	capacity = v.capacity;
	head = v.head;
	tail = v.tail; 
	vec = v.vec;
	v.vec = nullptr;
	cout << "in move constructor" << endl;
}

RoundVector::~RoundVector()
{
	if (vec)
		delete[] vec;
	cout << "in destructor" << endl;
}

void RoundVector::addNext(int val)
{
	int nextPlace = (tail + 1) % (capacity + 1);
	
	if (nextPlace == head)
		throw "Vector is full";
		//cout << "Vector is full" << endl;
	else
	{
		vec[tail] = val;
		tail = nextPlace;
	}
}

int RoundVector::removeFirst()
{
	//for future use
	if (isEmpty())
		throw "Vector is empty";

	int firstVal = vec[head];
	head = (head + 1) % (capacity + 1);
	return firstVal;
}

int RoundVector::firstValue() const
{
	//for future use
	if (isEmpty())
		throw "Vector is empty";

	return vec[head];
}

bool RoundVector::isEmpty() const
{
	return head == tail;
}

void RoundVector::clear()
{
	head = 0;
	tail = 0;
}

void RoundVector::print()
{
	for (int i = head; i != tail; i = (i + 1) % (capacity + 1))
		cout << vec[i] << ' ';
	cout << endl;
}
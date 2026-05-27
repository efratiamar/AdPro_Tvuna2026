#pragma once

class RoundVector
{
private:
	int* vec;
	int capacity;

	int head; //index of the first existing value, index of the next value that will be removed
	int tail; //index of next empty place, where the next value is inserted
public:
	RoundVector(int _capacity);
	RoundVector(const RoundVector& v);
	RoundVector(RoundVector&& v);
	~RoundVector();

	void addNext(int val); //add val to the next empty place, after the last entered val
	int removeFirst(); //remove the first value
	int firstValue() const; //return the first val (without removing it)

	bool isEmpty() const;
	void clear();

	void print(); //print all values ​​according to theeir order of entry and not according to the physical order
};
#pragma once
#include <iostream>
using namespace std;

class List
{
	//inner class
	class Link
	{
	public:
		int key;
		Link* next;
		Link(int k=0, Link* n=nullptr);
	};

	Link* head;

public:
	List();
	List(const List& other);
	~List();
	bool isEmpty() const;
	void add(int value);
	void removeFirst();
	int firstElement() const;
	bool search(const int& value) const;
	void clear();

	friend ostream& operator<<(ostream& os, const List& other);

};
//cout << ls;

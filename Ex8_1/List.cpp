#include <iostream>
using namespace std;
#include "List.h"

List::Link::Link(int k, Link* n)
	: key(k), next(n)
{}

List::List()
	: head(nullptr)
{}

List::List(const List& other)
{
	if (other.isEmpty())
	{
		head = nullptr;
		return;
	}
	Link* p = other.head;
	Link* prev = new Link(p->key, nullptr);
	head = prev;
	p = p->next;
	while (p)
	{
		Link* newL = new Link(p->key, nullptr);
		prev->next = newL;
		prev = newL;
		p = p->next;
	}
}

List::~List()
{
	clear();
}

bool List::isEmpty() const
{
	return head == nullptr;
}

void List::addFirst(int value)
{
	Link* newL = new Link(value, head);
	head = newL;
}

void List::removeFirst()
{
	if (isEmpty())
		throw "Error: cannot remove from empty list!";

	Link* temp = head->next;
	delete head;
	head = temp;
}

int List::firstElement() const
{
	if (isEmpty())
		throw "Error: empty list!";
	return head->key;
}

bool List::search(const int& value) const
{
	Link* p = head;
	while (p)
	{
		if (p->key == value)
			return true;
		p = p->next;
	}
	return false;
}

void List::clear()
{
	if (!isEmpty())
	{
		Link* p = head;
		while (p->next != nullptr)
		{
			Link* temp = p;
			p = p->next;
			delete temp;
			head = p;
		}
		delete p;
		head = nullptr;
	}
}

ostream& operator<<(ostream& os, const List& other)
{
	List::Link* p = other.head;
	while (p)
	{
		os << p->key << " ";
		p = p->next;
	}
	os << endl;
	return os;
}

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

	Link* pOther = other.head;

	Link* newL = new Link(pOther->key, nullptr);
	head = newL;

	while (pOther->next)
	{
		Link* prev = newL;
		newL = new Link(pOther->next->key, nullptr);
		prev->next = newL;
		pOther = pOther->next;
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
	head = new Link(value, head);
}

void List::removeFirst()
{
	if (isEmpty())
		throw "Error: cannot remove from empty list";
	Link* first = head;
	head = head->next;
	delete first;
}
int List::firstElement() const
{
	if (isEmpty())
		throw "Error: cannot return frist value of empty list";
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
	while (!isEmpty())
		removeFirst();

	//option 2
	//Link* p = head;

	//while (p)
	//{
	//	Link* next = p->next;
	//	delete p;
	//	p = next;
	//}
	//head = nullptr;
}


ostream& operator<<(ostream& os, const List& other)
{
	List::Link* p = other.head;

	while (p)
	{
		os << p->key << ' ';
		p = p->next;
	}
	os << endl;
	return os;
}

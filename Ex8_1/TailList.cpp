#include "TailList.h"

TailList::TailList() : List(), tail(nullptr)
{
}

TailList::~TailList()
{
}

void TailList::addFirst(int value)
{
	if (isEmpty())
	{
		List::addFirst(value);
		tail = head;
	}
	else
		List::addFirst(value);
}

void TailList::removeFirst()
{
	List::removeFirst();

	if (isEmpty())
		tail = nullptr;
}

void TailList::clear()
{
	List::clear();
	tail = nullptr;
}

void TailList::addLast(int value)
{
	if (isEmpty())
	{
		List:addFirst(value);
		tail = head;
		return;
	}

	Link* p = new Link(value, nullptr);
	tail->next = p;
	tail = p;
}

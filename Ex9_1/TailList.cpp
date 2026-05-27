#include "TailList.h"

TailList::TailList() : List(), tail(nullptr)
{

}

TailList::~TailList()
{
	tail = nullptr;
}

void TailList::addFirst(int value)
{
	if (isEmpty())
	{
		List::addFirst(value);
		tail = head;
		return;
	}

	List::addFirst(value);
}

void TailList::removeFirst()
{
	List::removeFirst();

	if (isEmpty())
		tail = nullptr;
}

void TailList::addLast(int value)
{
	Link* p = new Link(value, nullptr);
	if (isEmpty())
	{
		head = p;
		tail = p;
		return;
	}
	tail->next = p;
	tail = p;
}

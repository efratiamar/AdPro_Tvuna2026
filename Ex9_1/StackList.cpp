#include "StackList.h"

StackList::StackList() : data()
{
}


bool StackList::isEmpty() const
{
	return data.isEmpty();
}

void StackList::clear()
{
	data.clear();
}

int StackList::pop()
{
	int x = data.firstElement();
	data.removeFirst();
	return x;
}
void StackList::push(int value)
{
	data.addFirst(value);
}
int StackList::top()
{
	return data.firstElement();
}

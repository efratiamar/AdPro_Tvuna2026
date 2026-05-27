#include "StackList.h"

StackList::StackList() 
	: Stack(), data()
{

}

void StackList::clear()
{
	data.clear();
}

bool StackList::isEmpty() const
{
	return data.isEmpty();
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
int StackList::top() const
{
	return data.firstElement();
}
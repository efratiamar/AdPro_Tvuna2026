#include "StackVector.h"

StackVector::StackVector(int capacity) :
	Stack(), data(capacity)
{

}
void StackVector::clear()
{
	data.clear();
}

bool StackVector::isEmpty() const
{
	return data.isEmpty();
}
int StackVector::pop()
{
	return data.removeLast();
}
void StackVector::push(int value)
{
	data.addLast(value);
}
int StackVector::top() const
{
	return data.lastValue();
}
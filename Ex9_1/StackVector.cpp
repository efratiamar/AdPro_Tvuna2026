#include "StackVector.h"


StackVector::StackVector(int capacity) 
    : data(capacity)
{
}

bool StackVector::isEmpty() const
{
    return data.isEmpty();
    return false;
}

void StackVector::clear()
{
    data.clear();
}

int StackVector::pop()
{
    return data.removeLast();
}

void StackVector::push(int value)
{
    data.addLast(value);
}

int StackVector::top()
{
    return data.lastValue();
}

#include "QueueVector.h"
//== class QueueVector implementation==

QueueVector::QueueVector(int size) : data(size) {}

QueueVector::QueueVector(const QueueVector& Q) : data(Q.data) {}

void QueueVector::clear()
{
	data.clear();
}

int QueueVector::dequeue()
{
	// can not dequeue from an empty queue
	if (isEmpty()) throw "Queue is empty\n";
	int val = data.firstValue();
	data.removeFirst();
	return val;
}

void QueueVector::enqueue(int val)
{
	try
	{
		data.addNext(val);
	}
	catch (const char* msg)
	{
		throw "the Queue is full\n";
	}
}

int QueueVector::front()
{
	if (isEmpty())
		throw "Queue is empty\n";
	return data.firstValue();
}

bool QueueVector::isEmpty() const
{
	return data.isEmpty();
}

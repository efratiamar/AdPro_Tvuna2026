#include "QueueList.h"

void QueueList::clear()
{
    data.clear();
}

int QueueList::dequeue()
{
    int x = data.firstElement();
    data.removeFirst();
    return x;
}

void QueueList::enqueue(int value)
{
    data.addLast(value);
}

int QueueList::front()
{
    return data.firstElement();
}

bool QueueList::isEmpty() const
{
    return data.isEmpty();
}

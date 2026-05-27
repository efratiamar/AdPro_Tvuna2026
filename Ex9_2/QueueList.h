#pragma once
#include "Queue.h"
#include "TailList.h"

class QueueList : public Queue
{
	TailList data;
public:
	// Inherited via Queue
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;
};
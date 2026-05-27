#pragma once
#include "Queue.h"
#include "RoundVector.h"

class QueueVector : public Queue
{
	RoundVector data;
public:
	// constructor requires a size
	QueueVector(int max);
	QueueVector(const QueueVector&);

	// Inherited via Queue
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;
};

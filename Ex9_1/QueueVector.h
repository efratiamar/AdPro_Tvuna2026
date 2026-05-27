#pragma once
#include"Queue.h"	//home work 3
#include"RoundVector.h"
//--------------------------------
//  class QueueVector
//  Queue implemented using 
//  round vector operations
//--------------------------------
class QueueVector : public Queue
{
public:
	// constructor requires a size
	QueueVector(int max);
	QueueVector(const QueueVector&);

	// implement Queue protocol
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;
private:
	RoundVector data;

};

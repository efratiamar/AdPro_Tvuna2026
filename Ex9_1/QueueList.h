#pragma once

#pragma once
#include "Queue.h"
#include "TailList.h"   //targil 7
//--------------------------------
// class QueueList
// Queue implemented using List operations
//--------------------------------

class QueueList : public Queue
{
public:
    // constructors
    QueueList();
    //QueueList(const QueueList& v);

    // implement Queue protocol 
    void clear() override;
    int dequeue()override;
    void enqueue(int value) override;
    int front()override;
    bool isEmpty() const override;
private:
    TailList data;
};

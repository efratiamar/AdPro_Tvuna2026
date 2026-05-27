#pragma once
#include "Stack.h"
#include "Vector.h"

class StackVector : public Stack
{
private:
    Vector data;
public:
    StackVector(int capacity);
    void clear();
    bool isEmpty() const;
    int pop();
    void push(int value);
    int top() const;
};

#pragma once
#include "Stack.h"
#include "Vector.h"

class StackVector : public Stack
{
    Vector data;
public:
    StackVector(int capacity);
    bool isEmpty() const override;
    void clear() override;
    int pop() override;
    void push(int value) override;
    int top() override;
};

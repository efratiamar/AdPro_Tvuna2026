#pragma once
#include "Stack.h"
#include "List.h"

class StackList : public Stack
{
    List data;
public:
    StackList();
    bool isEmpty() const override;
    void clear() override;
    int pop() override;
    void push(int value) override;
    int top() override;
};

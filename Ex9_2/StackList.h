#pragma once
#include "Stack.h"
#include "List.h"

class StackList : public Stack
{
private:
    List data;
public:
    StackList();
    void clear() override;
    bool isEmpty() const override;
    int pop() override;
    void push(int value) override;
    int top() const override;
};
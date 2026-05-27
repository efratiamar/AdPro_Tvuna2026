#pragma once
#include "List.h"

class TailList : public List
{

	Link* tail;
public:
	TailList();
	~TailList();
	void addFirst(int value);
	void removeFirst();
	void addLast(int value);

};

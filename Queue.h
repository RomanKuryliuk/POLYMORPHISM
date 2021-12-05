#pragma once

template <class Type>
class Queue
{
private:
	Type n;
	Queue* p;

public:
	Queue* first(Type);
	void add(Queue**, Type);
	Type del(Oueue**);
};


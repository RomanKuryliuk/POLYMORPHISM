#pragma once

template <class Type>
class Queue
{
private:
	Type n;
	Queue* p;

public:
	Queue<Type>* first(Type);
	void add(Queue<Type>**, Type);
	Type del(Queue<Type>**);
};


#pragma once

#include <new>

template <typename T>
class Queue
{
private:
	T* p; //��������� �����
	int count; //�-��� �������� � ����

public:
	Queue();
	Queue(const Queue&);
	~Queue();

	void push(T);
	T pop();

	Queue& operator=(const Queue&);

	T GetItem();
	void clear();
	bool IsEmpty();
	int GetN();
	void print(const char*);
};



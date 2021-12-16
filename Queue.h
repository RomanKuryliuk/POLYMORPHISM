#pragma once

template <typename T>
class Queue
{
private:
	T* p; //динам≥чний масив
	int count; //к-сть елемент≥в в черз≥

public:
	Queue();
	Queue(const Queue&);
	~Queue();

	void push(T);
	T pop();	

	Queue& operator=(const Queue&);

	// вз€ть первый элемент из очереди не выт€гива€ его
	T GetItem()
	{
		if (count > 0)
			return p[0];
		else
			return 0;
	}

	// очистка очереди
	void clear()
	{
		if (count > 0)
		{
			delete[] p;
			count = 0;
		}
	}

	// проверка существовани€ элементов в очереди
	bool IsEmpty()
	{
		return count == 0;
	}

	// количество элементов в очереди
	int GetN()
	{
		return count;
	}

	// метод, вывод€щий очередь
	void print(const char* objName)
	{
		cout << "Object: " << objName << endl;
		for (int i = 0; i < count; i++)
			cout << p[i] << "\t";
		cout << endl;
		cout << "---------------------" << endl;
	}
};



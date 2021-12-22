#pragma once

#include <new>

using namespace std;

template <typename T>
class Queue
{
private:
	T* p; //динамічний масив
	int count; //к-сть елементів в черзі

public:
	//конструктор за замовчуванням
	Queue<T>() {
		p = new T[0];
		count = 0; //порожня черга
	}

	//конструктор копіювання
	Queue(const Queue& obj) {
		//скопіювати obj в даний об'єкт
		count = obj.count;

		try {
			//спроба виділити пам'ять під р
			p = new T[count];
			//заповнення значеннями
			for (int i = 0; i < count; i++)
				p[i] = obj.p[i];
		}
		catch (bad_alloc e)
		{
			//якщо пам'ять не виділина, троiки посваритись
			cout << e.what() << endl;
			count = 0; //здатися і створити порожню чергу
		}
	}

	//деструктор
	~Queue() {
		if (count > 0)
			delete[] p;
	}


	//додати елемент в чергу
	void push(T item) {
		T* p2; //оголосити додатковий вказівник
		p2 = p; //перенаправити додатковий вказівник на р

		try {
			//спроба виділити новий фрагмент пам'яті для р, але на 1 більший
			p = new T[count + 1];

			// скопіявати дані з місця, на яке вказує p2 (старі дані)
			// в місце, на яке вказує p
			for (int i = 0; i < count; i++)
				p[i] = p2[i];

			// скопіювати останній елемент
			p[count] = item;

			// збільшити к-сть елементів на 1
			count++;

			// звільнити стару пам'ять
			if (count > 1)
				delete[] p2;
		}
		catch (bad_alloc e)
		{
			//якщо пам'ять не виділена
			cout << e.what() << endl; //посваритись

			//повернути старий вказівник на p
			p = p2;
		}
	}

	//витягнути перший елемент з черги
	T& pop() {
		//заповнити елемент, який витягається
		T item;
		item = p[0];


		if (count == 0)
			return item;	

		//сформувати ділянку пам'яті, яка менша на 1
		try {
			T* p2;

			//спроба виділити пам'ять
			p2 = new T[count - 1];

			count--; //зменшити к-сть елементів в черзі

			//p=>p2
			for (int i = 0; i < count - 1; i++)
				p2[i] = p[i + 1]; //копіюється все, окрім першого

			  //звільнити ділянку, на яку вказує p
			if (count > 0)
				delete[] p;

			//перенаправити p на p2
			p = p2;

			//повернути item
			return item;
		}
		catch (bad_alloc e)
		{
			//якщо пам'ять не виділилась, то повернути 0
			cout << e.what() << endl;
			return item;
		}
	}



	//операторна функція operator=(),
	//реалізує присвоювання об'єктів типу Queue
	Queue& operator=(const Queue& obj) {
		T* p2; //вказівник на додаткову пам'ять

		try {
			//спроба виділити нову ділянку пам'яті для p2
			p2 = new T[obj.count];

			//якщо пам'ять виділена успішно,
			//можна звільняти пам'ять, виділену для p
			if (count > 0)
				delete[] p;

			//скопіювати obj в теперішній об'єкт
			p = p2; //перенаправити p на p2
			count = obj.count;

			//заповнити значеннями
			for (int i = 0; i < count; i++)
				p[i] = obj.p[i];
		}
		catch (bad_alloc e)
		{
			//якщо пам'ять не виділилась, то посваритись
			cout << e.what() << endl;
		}
		return *this; //повернути об'єкт
	}


	//взяти перший елемент з черги, не витягуючи його
	T& GetItem() {
		if (count > 0)
			return p[0];
	}

	//очистка черги
	void clear() {
		if (count > 0)
		{
			delete[] p;
			count = 0;
		}
	}

	//перевірка існування елеменів в черзі
	bool IsEmpty() {
		return count == 0;
	}

	//к-сть елементів в черзі
	int GetN() {
		return count;
	}

	//метод, який виводить чергу
	void print(const char* objName) {
		cout << "Object: " << objName << endl;
		for (int i = 0; i < count; i++)
			cout << p[i] << endl;
		cout << endl;
		cout << "---------------------" << endl;
	}
};


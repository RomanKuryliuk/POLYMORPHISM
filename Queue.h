#pragma once

#include <new>

using namespace std;

template <class T>
T temp;

template <typename T>
class Queue
{
private:
	T* p; //��������� �����
	int count; //�-��� �������� � ����

public:
	//����������� �� �������������
	Queue<T>() {
		p = new T[0];
		count = 0; //������� �����
	}

	//����������� ���������
	Queue(const Queue& obj) {
		//��������� obj � ����� ��'���
		count = obj.count;

		try {
			//������ ������� ���'��� �� �
			p = new T[count];
			//���������� ����������
			for (int i = 0; i < count; i++)
				p[i] = obj.p[i];
		}
		catch (bad_alloc e)
		{
			//���� ���'��� �� �������, ���i�� �����������
			cout << e.what() << endl;
			count = 0; //������� � �������� ������� �����
		}
	}

	//����������
	~Queue() {
		if (count > 0)
			delete[] p;
	}


	//������ ������� � �����
	void push(T item) {
		T* p2; //��������� ���������� ��������
		p2 = p; //������������� ���������� �������� �� �

		try {
			//������ ������� ����� �������� ���'�� ��� �, ��� �� 1 ������
			p = new T[count + 1];

			// ��������� ��� � ����, �� ��� ����� p2 (���� ���)
			// � ����, �� ��� ����� p
			for (int i = 0; i < count; i++)
				p[i] = p2[i];

			// ��������� ������� �������
			p[count] = item;

			// �������� �-��� �������� �� 1
			count++;

			// �������� ����� ���'���
			if (count > 1)
				delete[] p2;
		}
		catch (bad_alloc e)
		{
			//���� ���'��� �� �������
			cout << e.what() << endl; //�����������

			//��������� ������ �������� �� p
			p = p2;
		}
	}

	//��������� ������ ������� � �����
	T& pop() {
		//��������� �������, ���� ����������
		temp<T> = p[0];


		if (count == 0)
			return temp<T>;

		//���������� ������ ���'��, ��� ����� �� 1
		try {
			T* p2;

			//������ ������� ���'���
			p2 = new T[count - 1];

			count--; //�������� �-��� �������� � ����

			//p=>p2
			for (int i = 0; i < count; i++)
				p2[i] = p[i + 1]; //��������� ���, ���� �������

			  //�������� ������, �� ��� ����� p
			if (count > 0)
				delete[] p;

			//������������� p �� p2
			p = p2;

			//��������� temp<T>
			return temp<T>;
		}
		catch (bad_alloc e)
		{
			//���� ���'��� �� ���������, �� ��������� 0
			cout << e.what() << endl;
			return temp<T>;
		}
	}



	//���������� ������� operator=(),
	//������ ������������ ��'���� ���� Queue
	Queue& operator=(const Queue& obj) {
		T* p2; //�������� �� ��������� ���'���

		try {
			//������ ������� ���� ������ ���'�� ��� p2
			p2 = new T[obj.count];

			//���� ���'��� ������� ������,
			//����� �������� ���'���, ������� ��� p
			if (count > 0)
				delete[] p;

			//��������� obj � �������� ��'���
			p = p2; //������������� p �� p2
			count = obj.count;

			//��������� ����������
			for (int i = 0; i < count; i++)
				p[i] = obj.p[i];
		}
		catch (bad_alloc e)
		{
			//���� ���'��� �� ���������, �� �����������
			cout << e.what() << endl;
		}
		return *this; //��������� ��'���
	}


	//����� ������ ������� � �����, �� ��������� ����
	T& GetItem() {
		if (count > 0)
			return p[0];
	}

	//������� �����
	void clear() {
		if (count > 0)
		{
			delete[] p;
			count = 0;
		}
	}

	//�������� ��������� ������� � ����
	bool IsEmpty() {
		return count == 0;
	}

	//�-��� �������� � ����
	int GetN() {
		return count;
	}

	//�����, ���� �������� �����
	void print(const char* objName) {
		cout << "Object: " << objName << endl;
		for (int i = 0; i < count; i++)
			cout << p[i] << endl;
		cout << endl;
		cout << "---------------------" << endl;
	}
};


#include <iostream>

#include "Queue.h"

using namespace std;

//����������� �� �������������
template<typename T>
inline Queue<T>::Queue()
{
	count = 0; //������� �����
}


//����������� ���������
template<typename T>
Queue<T>::Queue(const Queue& obj)
{
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
template<typename T>
Queue<T>::~Queue()
{
	if (count > 0)
		delete[] p;
}


//������ ������� � �����
template<typename T>
void Queue<T>::push(T item)
{
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
template<typename T>
T& Queue<T>::pop()
{
	if (count == 0)
		return 0;

	//��������� �������, ���� ����������
	T item;

	item = p[0];

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

		//��������� item
		return item;
	}
	catch (bad_alloc e)
	{
		//���� ���'��� �� ���������, �� ��������� 0
		cout << e.what() << endl;
		return 0;
	}
}


//���������� ������� operator=(),
//������ ������������ ��'���� ���� Queue
template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& obj)
{
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
template<typename T>
T& Queue<T>::GetItem()
{
	if (count > 0)
		return p[0];
	else
		return 0;
}

//������� �����
template<typename T>
void Queue<T>::clear()
{
	if (count > 0)
	{
		delete[] p;
		count = 0;
	}
}

//�������� ��������� ������� � ����
template<typename T>
bool Queue<T>::IsEmpty()
{
	return count == 0;
}

//�-��� �������� � ����
template<typename T>
int Queue<T>::GetN()
{
	return count;
}

//�����, ���� �������� �����
template<typename T>
void Queue<T>::print(const char* objName)
{
	cout << "Object: " << objName << endl;
	for (int i = 0; i < count; i++)
		cout << p[i] << "\t";
	cout << endl;
	cout << "---------------------" << endl;
}
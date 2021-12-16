#pragma once

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

	// ����� ������ ������� �� ������� �� ��������� ���
	T GetItem()
	{
		if (count > 0)
			return p[0];
		else
			return 0;
	}

	// ������� �������
	void clear()
	{
		if (count > 0)
		{
			delete[] p;
			count = 0;
		}
	}

	// �������� ������������� ��������� � �������
	bool IsEmpty()
	{
		return count == 0;
	}

	// ���������� ��������� � �������
	int GetN()
	{
		return count;
	}

	// �����, ��������� �������
	void print(const char* objName)
	{
		cout << "Object: " << objName << endl;
		for (int i = 0; i < count; i++)
			cout << p[i] << "\t";
		cout << endl;
		cout << "---------------------" << endl;
	}
};



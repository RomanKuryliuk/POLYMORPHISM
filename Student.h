#pragma once

#include<iostream>

using namespace std;

class Student
{
private:
	char* name, * surname;
	int group, * marks;

public:
	Student();
	Student(char*, char*, int, int*);
	Student(Student&);
	~Student();

	char* get_name();
	char* get_surname();
	int get_group();
	int* get_marks();

	Student& set_name(char*);
	Student& set_surname(char*);
	Student& set_group(int);
	Student& set_name(int*);

	int middle_point();
	void add_mark(int);
	void print();

	Student& operator=(Student&);
	bool operator>(Student&);
	bool operator<(Student&);
	friend istream operator>>(istream, Student&);
	friend ostream operator<<(ostream, Student&);

};


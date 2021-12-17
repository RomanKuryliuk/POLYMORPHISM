#include "Student.h"

Student::Student()
{
	try {
		name = new char[];
		strcpy_s(name, (sizeof "noname") + 1, "noname");
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	try {
		surname = new char[];
		strcpy_s(surname, (sizeof "nosurname") + 1, "nosurname");
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	group = 0;
	marks = new int[];
}

Student::Student(char* _name, char* _surname, int _group, int* _marks, int _number)
{
	try {
		name = new char[];
		strcpy_s(name, (sizeof _name) + 1, _name);
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	try {
		surname = new char[];
		strcpy_s(surname, (sizeof _surname) + 1, _surname);
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	group = _group;

	number = _number;

	if (_number > 0) {
		marks = new int[];
		for (int i = 0; i < number; i++) {
			marks[i] = _marks[i];
		}
	}
}

Student::Student(Student& _student)
{
	try {
		name = new char[];
		strcpy_s(name, (sizeof _student.name) + 1, _student.name);
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	try {
		surname = new char[];
		strcpy_s(surname, (sizeof _student.surname) + 1, _student.surname);
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	group = _student.group;

	number = _student.number;

	marks = new int[];
	for (int i = 0; i < number; i++) {
		marks[i] = _student.marks[i];
	}
}

Student::~Student()
{
	if (name) {
		delete[] name;
	}

	if (surname) {
		delete[] surname;
	}

	if (number > 0) {
		delete[] marks;
	}
}

char* Student::get_name()
{
	return name;
}

char* Student::get_surname()
{
	return surname;
}

int Student::get_group()
{
	return group;
}

int* Student::get_marks()
{
	return marks;
}

int Student::get_number()
{
	return number;
}

Student& Student::set_name(char* _name)
{
	if (name) {
		delete[] name;
	}

	try {
		name = new char[];
		strcpy_s(name, (sizeof _name) + 1, _name);
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	return *this;
}

Student& Student::set_surname(char* _surname)
{
	if (surname) {
		delete[] surname;
	}

	try {
		surname = new char[];
		strcpy_s(surname, (sizeof _surname) + 1, _surname);
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	return *this;
}

Student& Student::set_group(int _group)
{
	group = _group;

	return *this;
}

Student& Student::set_marks(int* _marks, int _number)
{
	if (number > 0) {
		delete[] marks;
	}
	
	if (_number > 0) {
		marks = new int[];
		for (int i = 0; i < number; i++) {
			marks[i] = _marks[i];
		}
	}

	return *this;
}



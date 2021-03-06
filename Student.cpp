#include "Student.h"

Student::Student()
{
	try {
		name = new char[(sizeof "noname") + 1];
		strcpy_s(name, (sizeof "noname") + 1, "noname");
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	try {
		surname = new char[(sizeof "nosurname") + 1];
		strcpy_s(surname, (sizeof "nosurname") + 1, "nosurname");
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	group = 0;
	number = 0;
	marks = new int[0];
}

Student::Student(char* _name, char* _surname, int _group, int* _marks, int _number)
{
	try {
		name = new char[(sizeof _name) + 1];
		strcpy_s(name, (sizeof _name) + 1, _name);
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	try {
		surname = new char[(sizeof _surname) + 1];
		strcpy_s(surname, (sizeof _surname) + 1, _surname);
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	group = _group;

	number = _number;

	if (_number > 0) {
		marks = new int[number];
		for (int i = 0; i < number; i++) {
			marks[i] = _marks[i];
		}
	}
	else {
		marks = new int[0];
	}
}

Student::Student(Student& _student)
{
	try {
		name = new char[(sizeof _student.name) + 1];
		strcpy_s(name, (sizeof _student.name) + 1, _student.name);
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	try {
		surname = new char[(sizeof _student.surname) + 1];
		strcpy_s(surname, (sizeof _student.surname) + 1, _student.surname);
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	group = _student.group;

	number = _student.number;

	marks = new int[number];
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
		name = new char[(sizeof _name) + 1];
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
		surname = new char[(sizeof _surname) + 1];
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
		number = _number;
		marks = new int[number];
		for (int i = 0; i < number; i++) {
			marks[i] = _marks[i];
		}
	}

	return *this;
}

double Student::middle_point()
{
	double middle = 0;

	for (int i = 0; i < number; i++) {
		middle += marks[i];
	}

	middle /= number;

	return middle;
}

void Student::add_mark(int _mark)
{
	int* _marks = new int[number+1];
	for (int i = 0; i < number; i++) {
		_marks[i] = marks[i];
	}
	_marks[number] = _mark;

	marks = _marks;
	number++;
}

void Student::print()
{
	cout << name << " " << surname << ", group: " << group << endl
		<< marks << ":" << endl;
	for (int i = 0; i < number; i++) {
		cout << marks[i] << ", ";
	}
}

Student& Student::operator=(Student& _student)
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

	try {
		name = new char[(sizeof _student.name) + 1];
		strcpy_s(name, (sizeof _student.name) + 1, _student.name);
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	try {
		surname = new char[(sizeof _student.surname) + 1];
		strcpy_s(surname, (sizeof _student.surname) + 1, _student.surname);
	}
	catch (bad_alloc e) {
		cout << e.what() << endl;
	}

	group = _student.group;

	number = _student.number;

	marks = new int[number];
	for (int i = 0; i < number; i++) {
		marks[i] = _student.marks[i];
	}

	return *this;
}

bool Student::operator>(Student& _student)
{
	return middle_point() > _student.middle_point();
}

bool Student::operator<(Student& _student)
{
	return middle_point() < _student.middle_point();
}

istream& operator>>(istream& _input, Student& _student)
{
	_input >> _student.name >> _student.surname >> _student.group >> _student.number;
	for (int i = 0; i < _student.number; i++) {
		_input >> _student.marks[i];
	}
	return _input;
}

ostream& operator<<(ostream& _output, Student& _student)
{
	return 	_output << _student.get_name() << " " << _student.get_surname() << ", " 
		<< _student.get_group() << ", " << _student.middle_point();
;
}

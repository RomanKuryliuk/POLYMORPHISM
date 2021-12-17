#include <iostream>

#include "Queue.h"
#include "Student.h"

using namespace std;

void main() {

	Queue<Student> queue1;
	queue1.print("queue1");

	Student student1;
	cin >> student1;
	queue1.push(student1);

	queue1.print("queue1");

	Student student2;
	cin >> student2;
	queue1.push(student2);

	queue1.print("queue1");

	Student student3;
	student3 = queue1.pop();
	cout << student3;

	queue1.print("queue1");
	

}
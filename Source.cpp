#include <iostream>

#include "Queue.h"
#include "Queue.cpp"

using namespace std;

int main() {
	Queue<int>* pbeg = first(1);
	Queue<int>* pend = pbeg;
	for (int i = 2; i < 6; i++) {
		add(&pend, i);
	}
	while (pbeg)
		cout << del(&pbeg) << " ";

	return 0;
}
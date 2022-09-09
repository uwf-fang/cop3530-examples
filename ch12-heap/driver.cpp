#include <utility>
#include <iostream>
#include "priority-queue.hpp"

using namespace std;

int main() {
	PriorityQueue<int> q;
	q.push(10);
	q.push(34);
	q.push(15);
	q.push(23);
	int size = q.getLength();

	// pop out one by one, expect to be in ascending order
	for (int i = 0; i < size; ++i) {
		cout << q.pop() << " \n";
	}
}



#include <utility>
#include <iostream>
#include "priority-queue.hpp"

using namespace std;

int main() {
	PriorityQueue<int> q;
	q.enqueue(10);
	q.enqueue(34);
	q.enqueue(15);
	q.enqueue(23);
	int size = q.getLength();

	// pop out one by one, expect to be in ascending order
  cout << "Ascending order expected" << endl;
	for (int i = 0; i < size; ++i)
		cout << q.dequeue() << " ";
  cout << endl;
}



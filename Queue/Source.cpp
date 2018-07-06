#include "cirQueue.hpp"
#include "LinkedListQueue.hpp"
#include <iostream>
#include <ctime>

using namespace std;
void test() {
	CircleQueue<int> cq;
	for (int i = 0; i < 7; ++i) {
		cq.push(i);
	}
	cq.show();
	cout << cq.front() << endl;
	cq.pop();
	cq.show();
	cq.pop();
	cq.show();
	cq.pop();
	cq.show();
	cq.pop();
	cq.show();
	cq.push(21);
	cq.show();
	cq.push(22);
	cq.show();
	cq.push(23);
	cq.show();
	cq.push(24);
	cq.show();
	cq.push(25);
	cq.show();
	cq.push(26);
	cq.show();
}

void test2() {
	LinkedListQueue<int> cq;
	for (int i = 0; i < 7; ++i) {
		cq.push(i);
	}
	cq.show();
	cout << cq.front() << endl;
	cq.pop();
	cq.show();
	cq.pop();
	cq.show();
	cq.pop();
	cq.show();
	cq.pop();
	cq.show();
	cq.push(21);
	cq.show();
	cq.push(22);
	cq.show();
	cq.push(23);
	cq.show();
	cq.push(24);
	cq.show();
	cq.push(25);
	cq.show();
	cq.push(26);
	cq.show();
}
int main() {
	CircleQueue<int> cq;
	
	clock_t t1, t2, t3;
	t1 = clock();
	if (true) {
		LinkedListQueue<int> llq;
		for (int i = 0; i < 1000000; ++i) {
			llq.push(i);
		}
		for (int i = 0; i < 1000000; ++i) {
			llq.pop();
		}
	}
	
	
	
	t2 = clock();
	
	t3 = clock();
	cout << t3 - t2 << endl;
	for (int i = 0; i < 1000000; ++i) {
		cq.push(i);
	}
	for (int i = 0; i < 1000000; ++i) {
		cq.pop();
	}
	cout << t2 - t1 << endl;
	getchar();
}
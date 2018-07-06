#include "ArrayListHeap.hpp"


int main() {
	ArrayListHeap<int> alh;
	alh.add(63);
	alh.add(35);
	alh.add(24);
	alh.add(51);
	alh.add(23);
	alh.show();
	alh.pop();
	alh.show();
	int a[8] = { 23, 43, 22,45, 11, 77, 13,88 };
	
	ArrayListHeap<int> alh2;
	alh2.heapify(a, 8);
	alh2.show();
	getchar();
}
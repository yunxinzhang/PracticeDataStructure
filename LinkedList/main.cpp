#include "LinkedList.hpp"

void test() {
	LinkedList<int> list;
	for (int i = 0; i < 9; ++i) {
		list.add(i, i);
		list.show();
	}
	cout << list.size() << endl;
	list.delFirst();
	list.show();
	cout << list.size() << endl;
	list.addFirst(123);
	list.show();
	list.delFirst();
	list.show();
	cout << list.size() << endl;
	list.addFirst(123);
	list.show();
	cout << list.size() << endl;
	cout << list.get(5) << endl;
}



int main() {
	LinkedList<int> list;
	for (int i = 0; i < 9; ++i) {
		list.add(i, i);
		if (i % 3 == 0)list.add(i,3);
		
	}
	list.show();
	getchar();
}
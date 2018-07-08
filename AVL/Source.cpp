#include <iostream>
#include "avl.hpp"
int main() {
	AVL<int> bst;
	bst.add(6);
	bst.add(7);
	bst.add(5);
	bst.forword_print();
	bst.add(2);
	bst.add(7);
	bst.add(8);
	bst.forword_print();
	bst.add(22);
	bst.forword_print();
	bst.add(17);
	bst.add(4);
	bst.forword_print();
	cout << bst.getSize() << endl;
	cout << bst.hasVal(5) << endl;
	cout << bst.hasVal(7) << endl;

	bst.del(7);

	bst.forword_print();
	bst.del(22);

	bst.forword_print();
	bst.del(5);

	bst.forword_print();
	bst.del(6);

	bst.forword_print();
	cout << bst.getSize() << endl;
	cout << bst.hasVal(5) << endl;
	cout << bst.hasVal(7) << endl;
	getchar();
}
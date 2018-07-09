#include <iostream>
#include "rbt.hpp"
int main() {
	RedBlackTree<int> bst;
	bst.add(6);
	bst.add(7);
	bst.forword_print();
	bst.add(5);
	bst.forword_print();
	bst.add(2);
	bst.add(22);

	bst.forword_print();
	cout << bst.getSize() << endl;
	cout << bst.hasVal(5) << endl;
	cout << bst.hasVal(7) << endl;

	bst.del(7);

	bst.forword_print();
	cout << bst.getSize() << endl;
	cout << bst.hasVal(5) << endl;
	cout << bst.hasVal(7) << endl;
	getchar();
}
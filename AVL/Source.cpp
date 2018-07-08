#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <random>
#include "avl.hpp"
//#include "bst.hpp"

void test1() {
	/*AVL<int> bst;
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
	cout << bst.hasVal(7) << endl;*/
}

vector<string> dict;
void read() {
	ifstream fin("lex-chars.txt");
	string word;
	while (!fin.eof()) {
		fin >> word;
		dict.push_back(word);
	}
	fin.close();
}

int main() {
	read();
	int NTIME = 10000;
	clock_t t1, t2, t3;
	t1 = clock();
	AVL<string> avl;
	
	for (int i = 0; i < dict.size(); ++i) {
		avl.add(dict[i]);
	}
	srand(clock());
	int ind = 0;
	for (int i = 0; i < NTIME; ++i) {
		ind = rand() % NTIME;
		avl.hasVal(dict[ind]);
	}
	
	t2 = clock();
	/*BinarySearchTree<string> bst;
	for (int i = 0; i < dict.size(); ++i) {
		bst.add(dict[i]);
	}
	srand(clock());
	int ind = 0;
	for (int i = 0; i < NTIME; ++i) {
		ind = rand() % NTIME;
		bst.hasVal(dict[ind]);
	}*/
	t3 = clock();
	cout << t2 - t1 << endl;
	cout << t3 - t2 << endl;
	cout << avl.isAVL() << endl;
	getchar();
}
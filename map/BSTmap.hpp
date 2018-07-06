#include <iostream>
#include "Map.hpp"
#include "bst.hpp"

using namespace std;

template <typename K, typename V>
class BSTmap :public BinarySearchTree<K, V> {
public:
	BinarySearchTree bst;
public:
	void forword_print() {
		bst.forword_print();
	}
	
	V at(const K & k) {
		return bst.at(k);
	};
	int size() {
		
		return bst.getSize();
	};
	void add(const K &k, const V &v) {
		cout << "add" << endl;
		bst.add(k, v);
	};
	void del(const K & k) {
		bst.del(k);
	};
	void update(const K &k, const V &v) {
		bst.add(k, v);
	};
	bool contains(K & k) {
		bst.hasKey(k);
	};
};



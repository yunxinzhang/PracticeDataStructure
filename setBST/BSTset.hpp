#pragma once
#include "bst.hpp"
#include "Set.hpp"

template <typename T>
class BSTset :public Set<T> {
private:
	BinarySearchTree<T> bst;
public:
	void add(const T &t) {
		bst.add(t);
	};
	void del(const T &t) {
		bst.del(t);
	};
	int size() {
		return bst.getSize();
	};
	bool contains(const T &t) {
		return bst.hasVal(t);
	};
};
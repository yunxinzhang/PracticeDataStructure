#pragma once
#include "queue.h"
#include "LinkedList.hpp"
template <typename T>
class LinkedListQueue :public queue<T> {
private:
	LinkedList<T> list;
public:
	void push(const T &t) {
		list.addLast(t);
	}
	void pop() {
		list.delFirst();
	}
	int size() { return list.size(); }
	T front() { return list.get(0); }
	void show(){
		list.show();
	}
};
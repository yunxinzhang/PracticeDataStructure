#pragma once
#include "../Heap/ArrayListHeap.hpp"
#include "../Queue/queue.h"
// 不要拷贝同样的文件，更新难以维护。
// 没有测试过的函数，例如 index --> i , vs可以通过。
template <typename T>
class PriorityQueue:public queue<T> {
private:
	ArrayListHeap<T> alh;
public:
	void push(const T &t) {
		alh.add(t);
	};
	void pop() {
		alh.pop();
	};
	int size() {
		return alh.size();
	};
	T front() {
		return alh.get(0);
	};
};
#pragma once
#include "../Heap/ArrayListHeap.hpp"
#include "../Queue/queue.h"
// ��Ҫ����ͬ�����ļ�����������ά����
// û�в��Թ��ĺ��������� index --> i , vs����ͨ����
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
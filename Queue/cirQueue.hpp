#pragma

#include<iostream>
#include "queue.h"
using namespace std;
template<typename T>

class CircleQueue:public queue<T>{
private:
	T * arr;
	int _size;
	int capacity;
	int head;
	int tail;
	
	void resize() {
		T * temp = arr;
		capacity *= 2;
		arr = new T[capacity];
		for (int i = 0; i < _size; ++i) {
			arr[i] = temp[(head + i) % (capacity/2)];//选择合适的数据。
		}
		delete[] temp;
		temp = NULL;
		head = 0;
		tail = _size - 1;
	};
public:
	void show() {
		for (int i = 0; i < _size; ++i) {
			cout << arr[(i + head) % capacity] << "\t";
		}
		cout << endl;
	}
	void push(const T &t) {
		if ((tail + 1) % capacity == head) {
			resize();
		}
		tail = (_size + head) % capacity;
		arr[tail] = t;
		++_size;
		
	}
	void pop() {
		if (_size == 0) {
			throw exception("size == 0");
		}
		head = (head + 1) % capacity;
		--_size;
	}
	int size() { return _size; }
	T front() {
		if (_size == 0) {
			throw exception("size == 0");
		}
		return arr[head];
	}
	CircleQueue() {
		_size = 0;
		capacity = 4;
		head = 0;
		tail = 0;
		arr = new T[capacity];
	}
	~CircleQueue() {
		if (arr != NULL) {
			delete[] arr;
			arr = NULL;
		}
	}
};

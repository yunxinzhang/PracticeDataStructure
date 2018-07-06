#pragma once

template <typename T>

class heap {
public:
	virtual int size() = 0;
	virtual bool isEmpty() = 0;
	virtual void add(const T & t) = 0;
	virtual void pop() = 0;
	virtual void siftUp() = 0;
	virtual void siftDown() = 0;
	virtual void heapify(T arr[] ,int n) = 0;
	virtual void repalce(const T & t) = 0;
};
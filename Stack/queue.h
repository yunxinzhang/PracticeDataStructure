#pragma once

template<typename T>
virtual class queue {
public:
	virtual void push(T &t);
	virtual void pop();
	virtual int size();
	virtual T front();
};

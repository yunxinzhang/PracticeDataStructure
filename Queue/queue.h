#pragma once

template<typename T>
class queue {
public:
	virtual void push(const T &t)=0;
	virtual void pop()=0;
	virtual int size()=0;
	virtual T front()=0;
};

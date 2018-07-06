#pragma once
template<typename M>
class  Stack {
public:
	virtual void pop()=0;
	virtual void push(const M & t)=0;
	virtual M front()=0;
	virtual int getSize()=0;
	virtual bool isEmpty()=0;
};
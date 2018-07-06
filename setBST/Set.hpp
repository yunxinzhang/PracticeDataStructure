#pragma once
template <typename T>
class Set {
public:
	virtual void add(const T &t) = 0;
	virtual void del(const T &t) = 0;
	virtual int size() = 0;
	virtual bool contains(const T &t) = 0;
};

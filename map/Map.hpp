#pragma once
template <typename K, typename V>
class Map {
public:
	virtual V get(K & k) = 0;
	virtual int size() = 0;
	virtual void add(const K &k, const V &v) = 0;
	virtual void del(const K & k) = 0;
	virtual void update(const K &k, const V &v) = 0;
	virtual bool contains(K & k) = 0;
};
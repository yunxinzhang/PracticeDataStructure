#pragma once
#include <iostream>

using namespace std;

template <typename T>
class ArrayList {
private:
	T *arr;
	int size;
	int capality;
public:
	ArrayList() {
		size = 0;
		capality = 4;
		arr = new T[capality];
	}
	T get(int index) {
		if (index<0 || index>size) {
			throw exception("out of index boundary");
		}
		return arr[index];
	}
	void set(int index, const T &t) {
		if (index<0 || index>size) {
			throw exception("out of index boundary");
		}
		arr[index] = t;
	}
	void add(int index ,const T &t) {
		if (index<0 || index>size) {
			throw exception("out of index boundary");
		}
		if (size == capality) {
			capality *= 2;
			T * temp = arr;
			arr = new T[capality];
			for (int i = 0; i < capality; ++i) {
				arr[i] = temp[i];
			}
			temp = NULL;
		}
		for (int i = size - 1; i >= index; --i) {
			arr[i + 1] = arr[i];
		}
		arr[index] = t;
		++size;
	}
	// 不是变量的时候用常引用
	void addLast(const T &t) {
		add(size, t);
	}
	void addFirst(const T &t) {
		add(0, t);
	}
	void show() {
		for (int i = 0; i < size; ++i) {
			cout << arr[i] << '\t';
		}
		cout << endl;
	}
	int getSize() { return size; }
	void remove(int index) {
		if (index<0 || index>=size) {
			throw exception("out of index boundary");
		}
		for (int i = index; i < size -1; ++i) {
			arr[i] = arr[i + 1];
		}
		arr[--size] = NULL;
	}
	void removeLast() { remove(size - 1); }
	void removeFirst() { remove(0); }
	int find(const T & t) {
		for (int i = 0; i < size; ++i) {
			if (arr[i] == t) {	// 重载运算符，如果是自定义的类的话
				return i;
			}
		}
		return -1;
	}
	~ArrayList(){
		if (arr != NULL) {	// 如果是NULL释放
			cout << "destroyed arr" << endl;
			delete[] arr;
			arr = NULL;
		}	
	}
};
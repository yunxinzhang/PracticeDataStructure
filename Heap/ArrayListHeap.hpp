#include <iostream>
#include "ArrayList.hpp"
#include "heap.hpp"

using namespace std;

template<typename T>
class ArrayListHeap:public heap<T> {
private:
	ArrayList<T> al;
public:
	int size() {
		return al.getSize();
	};
	bool isEmpty() {
		return al.getSize() == 0;
	};
	void add(const T & t) {
		al.addLast(t);
		siftUp();
	};
	void pop() {
		if (al.getSize() == 0) {
			throw exception("size == 0");
		}
		T t = al.get(al.getSize() - 1);
		al.removeLast();
		al.set(0, t);
		siftDown();
	};
	void show() {
		cout << "--------" << endl;
		for (auto i = 0; i < al.getSize(); ++i) {
			cout << al.get(i) << endl;
		}
	}
	void siftUp() {
		int mv = al.getSize() - 1;
		if (mv <= 0)return;
		int p = 0;
		if (mv % 2 == 0) {
			p = mv / 2 - 1;
		}
		else {
			p = mv / 2;
		}
		while (al.get(p) < al.get(mv)) {
			T t = al.get(p);
			al.set(p,al.get(mv));
			al.set(mv, t);
			mv = p;
			if (mv % 2 == 0) {
				p = mv / 2 - 1;
			}
			else {
				p = mv / 2;
			}
			if (p < 0)break;
		}
		return;
	};
	void siftDown() {
		int mv = 0;
		int left = 2 * mv + 1;
		int right = 2 * mv + 2;
		int t;
		while (left < al.getSize()) {
			if (right < al.getSize()) {
				t = al.get(left) > al.get(right) ? left : right;
			}
			else {
				t = left;
			}
			if (al.get(t) > al.get(mv)) {
				T temp = al.get(t);
				al.set(t, al.get(mv));
				al.set(mv, temp);
			}
			mv = t;
			left = 2 * mv + 1;
			right = 2 * mv + 2;
		}
		return;
	};
	void heapify(T arr[], int n) {
		
		for (int i = 0; i < n; ++i) {
			add(arr[i]);
		}
	};
	void repalce(const T & t) {
		if (al.getSize() == 0) {
			throw exception("size == 0");
		}
		al.set(0, t);
		siftDown();
	};
	T get(int ind) { return al.get(0); }
};


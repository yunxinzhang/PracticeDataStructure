#include "MyArray.hpp"
#include "Stack.h"

template<typename T>
class ArrayStack:Stack<T>{
private:
	MyArray<T> arr;
public:
	void pop() {
		arr.removeLast();
	}
	void push(const T &t) {
		arr.addLast(t);
	}
	T front() {
		return arr.get(arr.getSize() - 1);
	}
	int getSize() {
		return arr.getSize();
	}
	bool isEmpty() {
		return arr.getSize() == 0;
	}
	void show() {
		int size = arr.getSize();
		for (int i = 0; i < size; ++i) {
			cout << arr.get(i) << "\t";
		}
		cout << endl;
	}
};

int main() {
	ArrayStack<int> ss;
	for (int i = 0; i < 10; ++i) {
		ss.push(i);
	}
	ss.show();
	ss.pop();
	cout << ss.getSize() << endl;
	ss.show();
	ss.pop();
	ss.show();
	cout << ss.getSize() << endl;
	getchar();
}
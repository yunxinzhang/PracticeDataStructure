#include <iostream>

using namespace std;

template <typename T>
class MyArray {
private:
	T *arr;
	int size;
	int capality;
public:
	MyArray() {
		size = 0;
		capality = 4;
		arr = new T[capality];
	}
	T get(int index) {
		if (index<0 || index>size) {
			throw exception("out of index boundary");
		}
		return arr[i];
	}
	void set(int index, const T &t) {
		if (index<0 || index>size) {
			throw exception("out of index boundary");
		}
		arr[i] = t;
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
	~MyArray(){
		if (arr != NULL) {	// 如果是NULL释放
			cout << "destroyed arr" << endl;
			delete[] arr;
			arr = NULL;
		}	
	}
};

int main() {
	if (true) {
		// 范式需要声明类型
		MyArray<int> list;
		list.addLast(3);
		list.addLast(4);
		list.addLast(5);
		list.addLast(6);
		list.addLast(7);
		list.add(2, 100);
		//list.add(12, 1100);
		cout << list.find(4) << endl;
		list.show();
		cout << list.getSize() << endl;
		list.remove(3);
		list.show();
		list.removeFirst();
		list.show();
		list.removeLast();
		list.remove(1);
		list.show();
		cout << list.find(5) << endl;
		cout << list.getSize() << endl;
	}
	cout << 123 << endl;
	getchar();
}
#include "PriorityQueue.hpp"

template <typename T>
// 以函数为参数，需要带上函数的参数。函数名为一个地址.
T merger(T (*fun)(const T&a, const T&b), const T & a, const T & b) {
	return fun(a, b);
}
template <typename T>
T add(const T & a, const T & b) {
	return a + b;
}

template <typename T>
T mul(const T & a, const T & b) {
	return a * b;
}
int main() {
	cout << merger(add, 2, 3) << endl;
	cout << merger(mul, 2, 3) << endl;
	PriorityQueue<int> pq;

	pq.push(34);
	pq.push(32);
	pq.push(87);
	pq.push(52);
	pq.push(21);
	pq.push(23);
	pq.push(67);
	pq.push(2);

	while (pq.size() > 0) {
		cout << pq.front() << endl;
		pq.pop();
	}

	getchar();

}
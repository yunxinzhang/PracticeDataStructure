#pragma once
#include <iostream>

using namespace std;

template <typename T>
T merge(T (*fun)(const T&a, const T&b), const T & a, const T & b) {
	return fun(a, b);
}

template <typename T>
T fun(const T & a, const T & b) {
	//return a>b?a:b;
	return a + b;
}

template <typename T>
class SegmentTree {
private:
	T *arr;
	int arrlen;
public:
	T *tree;
	int treelen;
	SegmentTree(T array[], int n) {
		arrlen = n;
		treelen = 4 * n;
		arr = new T[arrlen];
		for (int i = 0; i < arrlen; ++i) {
			arr[i] = array[i];
		}
		tree = new T[treelen]();
		buildTree(0, 0, n - 1);
	}
	// TODO
	~SegmentTree(){}
	void buildTree(int ind, int leftBoundary, int rightBoundary) {
		if (leftBoundary == rightBoundary) {
			tree[ind] = arr[rightBoundary];
			return;
		}
		int leftChildInd = ind * 2 + 1;
		int rightChildInd = ind * 2 + 2;
		// 避免越界
		int mid = leftBoundary + (rightBoundary - leftBoundary) / 2; 
		buildTree(leftChildInd, leftBoundary, mid);
		buildTree(rightChildInd, mid + 1, rightBoundary);
		tree[ind] = merge(fun,tree[leftChildInd], tree[rightChildInd]);

	}
	T search(int leftInd, int rightInd) {
		return search(0, 0, arrlen - 1, leftInd, rightInd);
	}
	T search(int ind, int leftBoundary, int rightBoundary, int leftInd, int rightInd) {
		if (leftInd == leftBoundary && rightInd == rightBoundary) {
			return tree[ind];
		}
		int leftChildInd = ind * 2 + 1;
		int rightChildInd = ind * 2 + 2;
		int mid = leftBoundary + (rightBoundary - leftBoundary) / 2;
		if (mid >= rightInd) {
			return search(leftChildInd, leftBoundary, mid, leftInd, rightInd);
		}
		if (mid <= leftInd) {
			return search(rightChildInd, mid+1, rightBoundary, leftInd, rightInd);
		}
		T  ta = search(leftChildInd, leftBoundary, mid, leftInd, mid);
		T  tb = search(rightChildInd, mid + 1, rightBoundary, mid + 1, rightInd);
		return merge(fun, ta, tb);
	}
	void update(int arrindex, const T &t) {
		arr[arrindex] = t;
		update(0, 0, arrlen - 1, arrindex, t);
	}
	void update(int treeindex, int leftBoundary, int rightBoundary, int arrindex, const T &t) {
		if (leftBoundary == rightBoundary && leftBoundary == arrindex) {
			tree[treeindex] = t;
			return;
		}
		int leftChildInd = treeindex * 2 + 1;
		int rightChildInd = treeindex * 2 + 2;
		int mid = leftBoundary + (rightBoundary - leftBoundary) / 2;
		// 避免懒惰，出现不必要的漏洞错误。格式不统一
		if (mid >= arrindex) {
			update(leftChildInd, leftBoundary, mid, arrindex, t);
		}else
		 {
			update(rightChildInd, mid + 1, rightBoundary, arrindex, t);
		}
		tree[treeindex] = tree[leftChildInd] + tree[rightChildInd];
	}
	void showTree() {
		cout << "---------------" << endl;
		for (int i = 0; i < treelen; ++i) {
			cout << tree[i] << endl;
		}
		cout << "---------------" << endl;
	}
};
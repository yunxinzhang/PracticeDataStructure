#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
	T data;
	int size;
	Node * left;
	Node * right;
	Node() {
		left = NULL;
		right = NULL;
	}
	Node(const T & t) {
		data = t;
		left = NULL;
		right = NULL;
	}
};

// 完整的二分搜索树，而不是简化版的。
// 并不是非常好写，特别是递归的逻辑与删除时的分类讨论。

template<typename T>
class BinarySearchTree {
private:
	Node<T> * root;
	int size;
public:
	BinarySearchTree() { root = NULL; size = 0; }
	void add(const T & t) {
		if (!hasVal(t)){
			root = add(root, t);
			++size;
		}
	}
	int getSize() { return size; }
	// 递归到底
	Node<T>* add(Node<T> * node, const T&t) {
		if (node == NULL) {
			return new Node<T>(t);
		}
		else {
			if (node->data > t) {
				node->left =  add(node->left, t);
			}
			else if(node->data < t){
				node->right =  add(node->right, t);
			}
		}
		return node;
	}
	void del(const T & t) {
		root = del(root, t);
	}
	void forword_print() {
		cout << "===========" << endl;
		forword_print(root);
	}
	void forword_print(Node<T>*node) {
		if (node == NULL)return;
		cout << node->data << endl;
		forword_print(node->left);
		forword_print(node->right);
	}
	Node<T>* del(Node<T> * node,const T & t) {
		if (node == NULL) {
			return NULL;
		}
		if (node->data < t) {
			node->right = del(node->right, t);
			return node;
		}
		else if (node->data > t) {
			node->left = del(node->left, t);
			return node;
		}
		else {
			if (node->left == NULL) {
				Node<T> * temp = node;
				temp = node->right;
				--size;
				delete node;
				node = NULL;
				return temp;
			}
			if (node->right == NULL) {
				Node<T> * temp = node;
				temp = node->left;
				--size;
				delete node;
				node = NULL;
				return temp;
			}
			Node<T> * min= minNode(node->right);
			min->right = delMinNode(node);
			min->left = node->left;
			--size;
			delete node;
			node = NULL;
			return min;
		}
	}
	
	Node<T> * findNode(Node<T> *node ,const T&data) {
		if (node == NULL)return NULL;
		if (node->data == data) {
			return node;
		}
		else if(node->data<data) {
			return findNode(node->right, data);
		}
		else {
			return findNode(node->left, data);
		}
	}
	bool hasVal(const T &t) {
		if (findNode(root, t) == NULL)return false;
		return true;
	}
	Node<T>*  minNode(Node<T> *node) {
		// node!=NULL
		if (node->left == NULL)return node;
		return minNode(node->left);
	}
	// 不是删除，是改造
	Node<T> * delMinNode(Node<T> * t) {
		if (t == NULL)return NULL;
		if (t->left == NULL) {
			Node<T>*temp = t->right;
			//delete t;
			//t = NULL;
			return temp;
		}
		t->left = delMinNode(t->left);
		return t;
	}
};
#pragma once
#include <iostream>
using namespace std;

#define BLACK  false
#define RED    true

template<typename T>
class Node {
public:
	
	T data;
	int size;
	bool color;
	Node * left;
	Node * right;
	Node() {
		left = NULL;
		right = NULL;
		color = RED;
	}
	Node(const T & t) {
		data = t;
		left = NULL;
		right = NULL;
		color = RED;
	}
	Node(const T & t, bool c) {
		data = t;
		left = NULL;
		right = NULL;
		color = c;
	}
};

// 完整的二分搜索树，而不是简化版的。
// 并不是非常好写，特别是递归的逻辑与删除时的分类讨论。
// size的逻辑控制。小心逻辑的不清晰。
template<typename T>
class RedBlackTree {
private:
	Node<T> * root;
	int size;
public:
	RedBlackTree() { root = NULL; size = 0; }
	
	~RedBlackTree(){
		// TODO
	}
	void add(const T & t) {
		if (!hasVal(t)) {
			root = add(root, t);
			root->color = BLACK;
			++size;
		}
	}
	//  n
	//   \
	//	  r
	Node<T>* rotateLeft(Node<T> *& node) {
		Node<T> * rnode = node->right;
		node->right = rnode->left;
		rnode->left = node;
		rnode->color = node->color;
		node->color = RED;
		return rnode;
	}
	Node<T>* rotateRight(Node<T> *& node) {
		Node<T> * lnode = node->left;
		node->left = lnode->right;
		lnode->right = node;
		lnode->color = node->color;
		node->color = RED;
		return lnode;
	}
	void flipColors(Node<T> *& node) {
		node->color = RED;
		node->left->color = BLACK;
		node->right->color = BLACK;
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
		if (!isRed(node->left) && isRed(node->right)) {
			node = rotateLeft(node);
		}
		if (isRed(node->left) && isRed(node->left->left)) {
			node = rotateRight(node);
		}
		if (isRed(node->left) && isRed(node->right)) {
			flipColors(node);
		}
		return node;
	}
	bool isRed(Node<T>* node) {
		if (node == NULL)return BLACK;
		else return node->color;
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
		cout << node->data<< "\t"<< ((node->color==BLACK)?"BLACK":"RED") << endl;
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
			min->right = delMinNode(node->right);// 不要弄错，多做测试
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
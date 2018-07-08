#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Node {
public:
	T data;
	int size;
	int height;
	int balanceFactor;
	Node * left;
	Node * right;
	Node() {
		left = NULL;
		right = NULL;
		height = 1;
		balanceFactor = 0;
	}
	Node(const T & t) {
		data = t;
		left = NULL;
		right = NULL;
		height = 1;
		balanceFactor = 0;
	}
};

// 并不是非常好写，特别是递归的逻辑与删除时的分类讨论。
template<typename T>
class AVL {
private:
	Node<T> * root;
	int size;
public:
	AVL() { root = NULL; size = 0; }
	void add(const T & t) {
		if (!hasVal(t)) {
			root = add(root, t);
			++size;
		}
	}
	int getSize() { return size; }

	int getHeight(Node<T> *node) {
		if (node == NULL)return 0;
		return node->height;
	}
	// 维护 height & blanceFactor
	void updateHeightAndBlance(Node<T>*node) {
		if (node == NULL)return;
		const int &lh = getHeight(node->left);
		const int &rh = getHeight(node->right);
		node->height = lh > rh ? (lh + 1) : (rh + 1);
		node->balanceFactor = lh - rh;
	}
	Node<T>* rotateRight(Node<T> *node) {
		Node<T>* lnode = node->left;
		node->left = lnode->right;
		lnode->right = node;
		
		updateHeightAndBlance(node);
		updateHeightAndBlance(lnode);
		return lnode;
	}
	Node<T>* rotateLeftRight(Node<T> *node) {
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}
	Node<T>* rotateLeft(Node<T> *node) {
		Node<T>* rnode = node->right;
		node->right = rnode->left;
		rnode->left = node;
		
		updateHeightAndBlance(node);
		updateHeightAndBlance(rnode);
		return rnode;
	}
	Node<T>* rotateRightLeft(Node<T> *node) {
		node->right = rotateRight(node->right);
		return rotateLeft(node);
	}
	// 递归到底
	Node<T>* add(Node<T> * node, const T&t) {
		if (node == NULL) {
			return new Node<T>(t);
		}
		else {
			if (node->data > t) {
				node->left =  add(node->left, t);
				updateHeightAndBlance(node);
				
			}
			else if(node->data < t){
				node->right =  add(node->right, t);
				updateHeightAndBlance(node);
				
			}
			
		}
		return rotate(node);
	}
	Node<T>* rotate(Node<T> *node) {
		if (node->balanceFactor == 2 && node->left->balanceFactor == 1) {
			node = rotateRight(node);
		}
		else if (node->balanceFactor == 2 && node->left->balanceFactor == -1) {
			node = rotateLeftRight(node);
		}
		else if (node->balanceFactor == -2 && node->right->balanceFactor == -1) {
			node = rotateLeft(node);
		}
		else if (node->balanceFactor == -2 && node->right->balanceFactor == 1) {
			node = rotateRightLeft(node);
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
		cout << node->data <<"\t"<<node->height<<"\t"<<node->balanceFactor<< endl;
		forword_print(node->left);
		forword_print(node->right);
	}
	Node<T>* del(Node<T> * node,const T & t) {
		if (node == NULL) {
			return NULL;
		}
		if (node->data < t) {
			node->right = del(node->right, t);
			updateHeightAndBlance(node);
			return rotate(node);
		}
		else if (node->data > t) {
			node->left = del(node->left, t);
			updateHeightAndBlance(node);
			return rotate(node);
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
			min->right = delMinNode(node->right);
			min->left = node->left;
			--size;
			delete node;
			node = NULL;
			updateHeightAndBlance(min);
			return rotate(min);
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
		updateHeightAndBlance(t);
		return rotate(t);
	}
	void getNodeValues(Node<T> *node, vector<T> & v) {
		if (node == NULL)return;
		if (node->left == NULL && node->right == NULL) {
			v.push_back(node->data);
		}
		getNodeValues(node->left, v);
		v.push_back(node->data);
		getNodeValues(node->right, v);
	}
	bool reBalance(Node<T> *node) {
		if (node == NULL)return true;
		if(!reBalance(node->left))return false;
		if(!reBalance(node->right))return false;
		updateHeightAndBlance(node);
		if (node->balanceFactor > 1 || node->balanceFactor < -1)return false;
		return true;
	}
	bool isAVL() {
		vector<T> v;
		getNodeValues(root, v);
		for (int i = 0; i < v.size() - 1; ++i) {
			if (v[i] > v[i + 1]) {
				cout << v[i] << "\t" << v[i + 1] << endl;
				return false;
			}
		}
		return reBalance(root);
	}
};
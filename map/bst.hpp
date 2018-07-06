#pragma once
#include <iostream>
using namespace std;

template<typename K, typename V>
class Node {
public:
	K key;
	V value;
	Node * left;
	Node * right;
	Node() {
		left = NULL;
		right = NULL;
	}
	Node(const K & k, const V& v):key(k),value(v) {
		left = NULL;
		right = NULL;
	}
};

// 完整的二分搜索树，而不是简化版的。
// 并不是非常好写，特别是递归的逻辑与删除时的分类讨论。
// size的逻辑控制。小心逻辑的不清晰。
template<typename K, typename V>
class BinarySearchTree {
public:
	Node<K, V> * root;
	int size;
public:
	BinarySearchTree() { root = NULL; size = 0; }
	void add(const K & k, const V & v) {
		cout << size <<","<< (root==NULL) << endl;
		//forword_print();
		if (!hasKey(k)) {
			root = add(root, k, v);
			
			
			++size;
		}
		string ss = ((root == NULL) ? "为NULL" : "not NULL");
		cout << "root --=-> " << ss << endl;
	}
	int getSize() { 
		string ss = ((root == NULL) ? "为NULL" : "not NULL");
		cout << "sroot --=-> " << ss << endl;
		return size; 
	}
	// 递归到底
	Node<K,V>* add(Node<K, V> * node, const K & k , const V & v) {
		if (node == NULL) {
			cout << k<<" >>"<<v << endl;
			return new Node<K,V>(k, v);
		}
		else {
			if (node->key > k) {
				node->left =  add(node->left, k, v);
			}
			else if(node->key < k ){
				node->right =  add(node->right, k, v);
			}
			else if (node->key == k) {
				node->value = v;
			}
		}
		return node;
	}
	void del(const K & k) {
		root = del(root, k);
	}
	void forword_print() {
		cout << "===========" << endl;
		string ss = ((root == NULL) ? "为NULL" : "not NULL");
		cout << "root --=-> " << ss << endl;
		forword_print(root);
		
	}
	void forword_print(Node<K, V>*node) {
		if (node == NULL)return;
		cout << node->key <<" : " << node->value << endl;
		forword_print(node->left);
		forword_print(node->right);
	}
	Node<K, V>* del(Node<K,V> * node,const K & t) {
		if (node == NULL) {
			return NULL;
		}
		if (node->key < t) {
			node->right = del(node->right, t);
			return node;
		}
		else if (node->key > t) {
			node->left = del(node->left, t);
			return node;
		}
		else {
			if (node->left == NULL) {
				Node<K,V> * temp = node;
				temp = node->right;
				--size;
				delete node;
				node = NULL;
				return temp;
			}
			if (node->right == NULL) {
				Node<K,V> * temp = node;
				temp = node->left;
				--size;
				delete node;
				node = NULL;
				return temp;
			}
			Node<K,V> * min= minNode(node->right);
			min->right = delMinNode(node);
			min->left = node->left;
			--size;
			delete node;
			node = NULL;
			return min;
		}
	}
	V at(const K &k) {
		cout << (root == NULL) << endl;
		if (findNode(root, k) == NULL) {
			throw exception("no such key ");
		}
		return findNode(root, k)->value;
	}
	Node<K, V> * findNode(Node<K, V> *node, const K&data) {
		if (node == NULL)
		{
			return NULL;
		};
		if (node->key == data) {
			return node;
		}
		else if(node->key<data) {
			return findNode(node->right, data);
		}
		else {
			return findNode(node->left, data);
		}
	}
	bool hasKey(const K &t) {
		if (findNode(root, t) == NULL)return false;
		return true;
	}
	Node<K,V>*  minNode(Node<K,V> *node) {
		// node!=NULL
		if (node->left == NULL)return node;
		return minNode(node->left);
	}
	// 不是删除，是改造
	Node<K,V> * delMinNode(Node<K,V> * t) {
		if (t == NULL)return NULL;
		if (t->left == NULL) {
			Node<K,V>*temp = t->right;
			//delete t;
			//t = NULL;
			return temp;
		}
		t->left = delMinNode(t->left);
		return t;
	}
};
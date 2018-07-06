#pragma once
#include<iostream>

using namespace std;

template<typename T>
class Node {
public:
	Node * next;
	T data;
	Node() { next = NULL; }
	Node(const T&t, Node * n) { 
		next = n; 
		data = t; 
	}
};

template<typename T>
class LinkedList {
private:
	Node<T> *dummyHead;
	Node<T> *tail;
	int _size;
public:
	LinkedList() {
		dummyHead = new Node<T>;
		tail = dummyHead;
		_size = 0;
	}
	void delElement(const T & val) {

	}
	
	int size() { return _size; }
	void addFirst(const T&t) {
		add(0, t);
	}
	void delFirst() {
		del(0);
	}
	void show() {
		Node<T>*mv = dummyHead;
		cout << " head -> ";
		while (mv->next != NULL) {
			cout << mv->next->data <<"\t";
			mv = mv->next;
		}
		cout << " -> null" << endl;
	}
	void add(int index, const T&t) {
		if (index < 0 || index>_size) {
			throw exception("out of index boundary");
		}
		Node<T>* mv = dummyHead;//类之外的泛型要显示
		Node<T>* cur = NULL;
		for (int i = 0; i < index; ++i) {
			mv = mv->next;
		}
		mv->next = new Node<T>(t, mv->next);
		if (index == _size) {
			tail = mv->next;
		}
		++_size;
	}
	void addLast(const T &t) {
		tail->next = new Node(t, NULL);
		tail = tail->next;
	}
	T get(int index) {
		if (index < 0 || index>=_size) {
			throw exception("out of index boundary");
		}
		Node<T>* mv = dummyHead;
		for (int i = 0; i < index; ++i) {
			mv = mv->next;
		}
		return mv->next->data;
	}
	void update(int index, const T&t) {
		if (index < 0 || index >= _size) {
			throw exception("out of index boundary");
		}
		Node<T>* mv = dummyHead;
		for (int i = 0; i < index; ++i) {
			mv = mv->next;
		}
		mv->next->data = t;
	}
	void del(int index) {
		if (index < 0 || index >= _size) {
			throw exception("out of index boundary");
		}
		Node<T>* mv = dummyHead;
		Node<T>* cur;
		for (int i = 0; i < index; ++i) {
			mv = mv->next;
		}
		cur = mv->next;
		mv->next = cur->next;
		if (cur != NULL)delete cur;
		--_size;
	}
	~LinkedList() {
		cout << "destroy" << endl;
		Node<T> *cur= dummyHead;
		Node<T> *mv;
		while (cur != NULL) {
			mv = cur;
			cur = cur->next;
			delete mv;
			mv = NULL;
		}
	}
};

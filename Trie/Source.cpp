#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Node {
public:
	map<char,Node*> nextNodes;
	bool isWord;
	Node() {
		isWord = false;
	}
};
// Node * ��map ��insertʱ��vs ��ʾ���󡣿�����vs��bug
class Trie {
private:
	Node * root;
public:
	Trie() { root = new Node; }
	~Trie() {
		// TODO
	}
	void add(const string str) {
		char c;
		Node*  mv = root;
		for (size_t i = 0; i < str.size(); ++i) {
			c = str.at(i);
			if (mv->nextNodes.find(c) == mv->nextNodes.end()) {
				mv->nextNodes.insert(pair<char, Node*>(c, new Node));
			}
			mv = mv->nextNodes.at(c);
		}
		mv->isWord = true;
	}
	bool startWith(const string str) {
		char c;
		Node*  mv = root;
		for (size_t i = 0; i < str.size(); ++i) {
			c = str.at(i);
			if (mv->nextNodes.find(c) == mv->nextNodes.end()) {
				return false;
			}
			mv = mv->nextNodes.at(c);
		}
		return true;
	}
	bool hasWordLike(Node * mv, const string str, int loc) {
		char c;
		for (size_t i = loc; i < str.size(); ++i) {
			c = str.at(i);
			if (c != '.') {
				if (mv->nextNodes.find(c) == mv->nextNodes.end()) {
					return false;
				}
				mv = mv->nextNodes.at(c);
			}
			else {
				for (auto it : mv->nextNodes) {
					if (hasWordLike(it.second, str, i + 1))return true;
				}
			}
		}
		return true;
	}
	// ��.��ͨ��һ���ַ�
	bool hasWordLike(const string str) {
	
		return hasWordLike(root, str, 0);
	}
	bool hasWord(const string str) {
		char c;
		Node*  mv = root;
		for (size_t i = 0; i < str.size(); ++i) {
			c = str.at(i);
			if (mv->nextNodes.find(c) == mv->nextNodes.end()) {
				return false;
			}
			mv = mv->nextNodes.at(c);
		}
		return mv->isWord;
	}
};


int main() {
	Trie tr;
	tr.add("apple");
	tr.add("cat");
	tr.add("dog");
	// �����к����Ķ��壬��vs�Ҳ������� ���� bug
	cout << tr.hasWord("cat") << endl;
	cout << tr.hasWord("ca") << endl;
	cout << tr.startWith("ca") << endl;
	cout << tr.hasWordLike("ca.") << endl;
	cout << tr.hasWordLike("da.") << endl;
	cout << tr.hasWordLike("ba.") << endl;
	cout << tr.hasWordLike("a..le") << endl;
	getchar();
}
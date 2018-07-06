#include "BSTmap.hpp"
#include <string>
using namespace std;

int main() {
	BSTmap<int,string> map;
	map.add(1, "hello world!");
	map.add(2, "nihao");
	map.add(3, "youxi");
	//cout << map.size() << endl;
	cout <<"biff >>"<<( map.bst.root == NULL )<< endl;
	map.forword_print();
	
	cout << map.at(3) << endl;
	map.del(1);
	cout << map.size() << endl;
	map.forword_print();
	getchar();
}
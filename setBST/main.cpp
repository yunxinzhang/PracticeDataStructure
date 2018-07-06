#include "BSTset.hpp"
#include  <string>

int main() {
	string str = "hello world!";
	BSTset<char> set;
	for (int i = 0; i < str.size(); ++i) {
		set.add(str.at(i));
	}
	cout << set.size() << endl;
	cout << set.contains('h') << endl;
	set.del('l');
	cout << set.contains('l') << endl;
	cout << set.size() << endl;
	getchar();
}
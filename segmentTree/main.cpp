#include "SegmentTree.hpp"

int main() {
	int arr[9] = { 9,2,4,5,3,7,3,0,1 };
	SegmentTree<int> st(arr,9);
	st.showTree();

	cout << st.search(0, 2) << endl;
	cout << st.search(5, 7) << endl; 
	cout << st.search(3, 6) << endl;
	st.update(2, 10);
	st.showTree();
	cout << st.search(0, 2) << endl;
	cout << st.search(5, 7) << endl;
	cout << st.search(3, 6) << endl;
	getchar();
}
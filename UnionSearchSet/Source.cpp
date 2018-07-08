#include <iostream>
#include <ctime>
#include <random>
#include <vector>
using namespace std;
class UnionSearchSet {
public:
	virtual bool isConnected(int x, int y) = 0;
	virtual void unionEntry(int x, int y) = 0;
};

//Array
class UnionSearchSet1:public UnionSearchSet {
public:
	int * parent;
	int number;
	UnionSearchSet1(int n) {
		number = n;
		parent = new int[n];
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
	}
	~UnionSearchSet1() {
		// TODO
	}
	bool isConnected(int x, int y) {
		return parent[x] == parent[y];
	}
	void unionEntry(int x, int y) {
		int px = parent[x];
		int py = parent[y];
		if (py == px)return;
		for (int i = 0; i < number; ++i) {
			if (parent[i] == py) {
				parent[i] = px;
			}
		}
	}
};
// tree
class UnionSearchSet2:public UnionSearchSet {
public:
	int * parent;
	int number;
	UnionSearchSet2(int n) {
		number = n;
		parent = new int[n];
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
	}
	~UnionSearchSet2() {
		// TODO
	}
	int getRoot(int x) {
		while (parent[x] != x) {
			x = parent[x];
		}
		return x;
	}
	bool isConnected(int x, int y) {
		return getRoot(x) == getRoot(y);
	}
	void unionEntry(int x, int y) {
		int rx = getRoot(x);
		int ry = getRoot(y);
		if (rx == ry) return;
		parent[rx] = ry;
	}
};

// tree  size
class UnionSearchSet3 :public UnionSearchSet {
public:
	int * parent;
	int * size;
	int number;
	UnionSearchSet3(int n) {
		number = n;
		parent = new int[n];
		size = new int[n];
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
			size[i] = 1;
		}
	}
	~UnionSearchSet3() {
		// TODO
	}
	int getRoot(int x) {
		while (parent[x] != x) {
			x = parent[x];
		}
		return x;
	}
	bool isConnected(int x, int y) {
		return getRoot(x) == getRoot(y);
	}
	void unionEntry(int x, int y) {
		int rx = getRoot(x);
		int ry = getRoot(y);
		if (rx == ry) return;
		if (size[rx] > size[ry]) {
			parent[ry] = rx;
			size[rx] += size[ry];
		}
		else {
			parent[rx] = ry;
			size[ry] += size[rx];
		}
		
	}
};
// tree rank
class UnionSearchSet4 :public UnionSearchSet {
public:
	int * parent;
	int * rank;
	int number;
	UnionSearchSet4(int n) {
		number = n;
		parent = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
			rank[i] = 1;
		}
	}
	~UnionSearchSet4() {
		// TODO
	}
	int getRoot(int x) {
		while (parent[x] != x) {
			x = parent[x];
		}
		return x;
	}
	bool isConnected(int x, int y) {
		return getRoot(x) == getRoot(y);
	}
	void unionEntry(int x, int y) {
		int rx = getRoot(x);
		int ry = getRoot(y);
		if (rx == ry) return;
		if (rank[rx] > rank[ry]) {
			parent[ry] = rx;
		}
		else if(rank[rx] < rank[ry]) {
			parent[rx] = ry;
		}
		else {
			parent[rx] = ry;
			++rank[ry];
		}

	}
};

// tree compress path
class UnionSearchSet5 :public UnionSearchSet {
public:
	int * parent;
	int * rank;
	int number;
	UnionSearchSet5(int n) {
		number = n;
		parent = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
			rank[i] = 1;
		}
	}
	~UnionSearchSet5() {
		// TODO
	}
	int getRoot(int x) {
		while (parent[x] != x) {
			x =parent[x] = parent[parent[x]];
			//x = parent[x];
		}
		return x;
	}
	bool isConnected(int x, int y) {
		return getRoot(x) == getRoot(y);
	}
	void unionEntry(int x, int y) {
		int rx = getRoot(x);
		//parent[x] = rx;
		int ry = getRoot(y);
		//parent[y] = ry;
		if (rx == ry) return;
		if (rank[rx] > rank[ry]) {
			parent[ry] = rx;
		}
		else if (rank[rx] < rank[ry]) {
			parent[rx] = ry;
		}
		else {
			parent[rx] = ry;
			++rank[ry];
		}

	}
};
void test(int range, int nunion, int nsearch, UnionSearchSet * uss) {
	srand(clock());
	vector<int> res;
	bool flag;
	int x, y;
	clock_t t1, t2;
	t1 = clock();
	for (int i = 0; i < nunion; ++i) {
		x = rand() % range;
		y = rand() % range;
	//	cout << "union " << x << " " << y << endl;
		uss->unionEntry(x, y);
	}
	for (int i = 0; i < nsearch; ++i) {
		x = rand() % range;
		y = rand() % range;
		flag = uss->isConnected(x, y);
	//	cout << x <<"\t"<< y <<"\t"<< flag << endl;
		res.push_back(flag);
	}
	t2 = clock();
	cout << t2 - t1 << endl;
}
int main() {
	int range = 100000;
	int nunion = 60000;// 并的越多，越可能长。压缩路径的效果越明显
	int nsearch = 200000;
	//UnionSearchSet *uss1 = new UnionSearchSet1(range);
	//test(range, nunion, nsearch, uss1);
	//UnionSearchSet *uss2 = new UnionSearchSet2(range); // 稍微优化，加入几行代码和一点空间速度即可提升50倍
	//test(range, nunion, nsearch, uss2);
	UnionSearchSet *uss3 = new UnionSearchSet3(range);
	test(range, nunion, nsearch, uss3);
	UnionSearchSet *uss4 = new UnionSearchSet4(range);
	test(range, nunion, nsearch, uss4);
	UnionSearchSet *uss5 = new UnionSearchSet5(range);	// 不同的数据结构适合不同类型的数据
	test(range, nunion, nsearch, uss5);
	getchar();
}
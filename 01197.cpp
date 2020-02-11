#include <iostream>
#include <vector>
using namespace std;

int root(int a, vector<int> &parent) {
	int last_a;
	while(a != parent[a]) {
		last_a = a;
		a = parent[a];
		parent[last_a] = parent[a];
	}
	return a;
}

bool isSameSet(int a, int b, vector<int> &parent, vector<int> &rank) {
	return root(a, parent) == root(b, parent);
}

void merge(int a, int b, vector<int> &parent, vector<int> &rank) {
	int r_a, r_b;
	r_a = root(a, parent);
	r_b = root(b, parent);
	if (rank[r_a] > rank[r_b]) {
		parent[r_b] = r_a;
	} else if (rank[r_b] > rank[r_a]) {
		parent[r_a] = r_b;
	} else {
		parent[r_a] = r_b;
		rank[r_b]++;
	}
}

int findSet0(int n, vector<int> &parent) {
	int r_0 = root(0, parent);
	int r_i, count;
	count = 1;
	for (int i = 1; i < n; i++) {
		r_i = root(i, parent);
		if (r_i == r_0) {
			count++;
		}
	}
	return count;
}

int main() {
	int stud, grps, k, cur, ls;
	vector<int> parent;
	vector<int> rank;
	while(true) {
		cin >> stud >> grps;
		if (!(stud || grps)) break;
		parent.clear();
		parent.assign(stud, 0);
		rank.clear();
		rank.assign(stud, 0);
		for (int u = 0; u < stud; u++) parent[u] = u;
		if (!(stud || grps)) break;
		for (int y = 0; y < grps; y++) {
			cin >> k;
			cin >> cur;
			for (int t = 1; t < k; t++) {
				cin >> ls;
				merge(cur, ls, parent, rank);
				ls = cur;
			}
		}
		cout << findSet0(stud, parent) << endl;
	}
	return 0;
}

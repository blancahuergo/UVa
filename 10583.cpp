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

void merge(int a, int b, vector<int> &parent, vector<int> &rank, int &groups) {
	int r_a, r_b;
	r_a = root(a, parent);
	r_b = root(b, parent);
	if (r_a == r_b) return;
	groups--;
	if (rank[r_a] > rank[r_b]) {
		parent[r_b] = r_a;
	} else if (rank[r_b] > rank[r_a]) {
		parent[r_a] = r_b;
	} else {
		parent[r_a] = r_b;
		rank[r_b]++;
	}
}
int main() {
	int n, m, A, B, groups, cas;
	vector<int> parent;
	vector<int> rank;
	cas = 1;
	while(true) {
		cin >> n >> m;
		if (!(n || m)) break;
		parent.clear();
		parent.assign(n, 0);
		for (int u = 0; u < n; u++) parent[u] = u;
		rank.assign(n, 0);
		groups = n;
		for (int u = 0; u < m; u++) {
			cin >> A >> B;
			merge(A-1, B-1, parent, rank, groups);
		}
		cout << "Case " << cas << ": " << groups << endl;
		cas++;
	}
	return 0;
}

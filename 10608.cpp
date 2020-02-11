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

void merge(int a, int b, vector<int> &parent, vector<int> &size) {
	int r_a, r_b;
	r_a = root(a, parent);
	r_b = root(b, parent);
	if (r_a == r_b) return;
	if (size[r_a] > size[r_b]) {
		parent[r_b] = r_a;
		size[r_a] += size[r_b];
	} else {
		parent[r_a] = r_b;
		size[r_b] += size[r_a];
	}
}

int main() {
	int cas, n, m, A, B, max_s;
	vector<int> parent;
	vector<int> size;
	cin >> cas;
	while (cas--) {
		cin >> n >> m;
		parent.clear();
		size.clear();
		parent.assign(n, 0);
		for (int u = 0; u < n; u++) parent[u] = u;
		size.assign(n, 1);
		for (int y = 0; y < m; y++) {
			cin >> A >> B;
			merge(A-1, B-1, parent, size);
		}
		max_s = 0;
		for (int g = 0; g < n; g++) {
			if (size[g] > max_s) max_s = size[g];
		}
		cout << max_s << endl;
	}
	return 0;
}

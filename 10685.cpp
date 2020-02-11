#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int root(int a, vector<int> &parent) {
	while(a != parent[a]) {
		a = parent[a];
	}
	return a;
}

void merge(int a, int b, vector<int> &parent, vector<int> &size) {
	int r_a, r_b;
	r_a = root(a, parent);
	r_b = root(b, parent);
	if (r_a == r_b) return;
	parent[r_b] = r_a;
	size[r_a] += size[r_b];
}

int main() {
	vector<int> parent;
	vector<int> size;
	unordered_map<string, int> names;
	string nam, A, B;
	int C, R, max_s;
	while(true) {
		cin >> C >> R;
		if (!(C || R)) break;
		parent.clear();
		size.clear();
		names.clear();
		size.assign(C, 1);
		parent.assign(C, 0);
		for (int u = 0; u < C; u++) {
			cin >> nam;
			names[nam] = u;
			parent[u] = u;
		}
		for (int f = 0; f < R; f++) {
			cin >> A >> B;
			merge(names[A], names[B], parent, size);
		}
		max_s = 0;
		for (int i = 0; i < C; i++) {
			if (size[i] > max_s) max_s = size[i];
		}
		cout << max_s << endl;
	}
	return 0;
}

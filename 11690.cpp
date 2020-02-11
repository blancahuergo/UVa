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

void merge(int a, int b, vector<int> &parent, vector<int> &rank) {
	int r_a, r_b;
	r_a = root(a, parent);
	r_b = root(b, parent);
	if (r_a == r_b) return;
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
	int cas, F, R, cur, A, B, c_root;
	cin >> cas;
	vector<int> parent;
	vector<int> rank;
	vector<int> owes;
	vector<int> money;
	bool met;
	for (int c = 0; c < cas; c++) {
		cin >> F >> R;
		parent.clear();
		rank.clear();
		owes.clear();
		parent.assign(F, 0);
		rank.assign(F, 0);
		for (int i = 0; i < F; i++) {
			cin >> cur;
			owes.push_back(cur);
			parent[i] = i;
		}
		for (int u = 0; u < R; u++) {
			cin >> A >> B;
			merge(A, B, parent, rank);
		}
		money.clear();
		money.assign(F, 0);
		for (int b = 0; b < F; b++) {
			c_root = root(b, parent);
			money[c_root] += owes[b];
		}
		met = true;
		for (int y = 0; y < F; y++) {
			if (money[y] != 0) {
				met = false;
				break;
			}
		}
		if (met) {
			cout << "POSSIBLE" << endl;
		} else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}

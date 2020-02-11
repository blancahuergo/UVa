#include <iostream>
#include <unordered_map>
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
	int cases, F, count;
	string A, B;
	vector<int> size;
	vector<int> parent;
	unordered_map<string, int> names;
	cin >> cases;
	while(cases--) {
		cin >> F;
		size.clear();
		parent.clear();
		size.assign(F*2, 1);
		parent.assign(F*2, 0);
		count = 0;
		names.clear();
		for (int y = 0; y < F*2; y++) parent[y] = y;
		for (int u = 0; u < F; u++) {
			cin >> A >> B;
			if (names.find(A) == names.end()) {
				names[A] = count;
				count++;
			}
			if (names.find(B) == names.end()) {
				names[B] = count;
				count++;
			}
			merge(names[A], names[B], parent, size);
			cout << max(size[root(names[A], parent)], size[root(names[B], parent)]) << endl;
		}
	}
	return 0;
}
